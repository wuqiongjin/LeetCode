[toc]

[参考: 代码随想录 - KMP算法)](https://programmercarl.com/0028.实现strStr.html#其他语言版本)

# KMP算法

&emsp;KMP的主要思想是**当出现字符串不匹配时，可以知道一部分之前已经匹配的文本内容，可以利用这些信息避免从头再去做匹配了。**

KMP的重点就在于next数组的实现，next数组中保存着**如果该位置不匹配, 应该回溯到上一个匹配的结点的位置**的信息。

获得到上一个匹配位置的信息时，你就省去了再从头开始匹配的这部分操作了，这就是KMP算法的核心。

&emsp;

**注意**:

&emsp;当你通过next数组回溯到上一个匹配位置的位置时，你需要再判断该位置的下一个位置是否满足当前需要判断的条件，如果不满足，还要继续回溯! 继续回溯到上一个匹配位置的值。(此处是需要用**while循环**的!!!)

&emsp;

&emsp;

## 前缀表(next数组)

&emsp;**前缀表是用来回退的，它记录了模式串与主串(文本串)不匹配的时候，模式串应该从哪里开始重新匹配。**

> next数组是KMP里面的特殊名词，它的本质其实就是前缀表。(只不过一些人写KMP算法时，会将前缀表统一减去1，然后将减一后的数组称为next数组，不过减不减一完全不影响KMP算法的实现的!)



**问题: 前缀表是如何实现的? 它是如何实现不匹配时，模式串应该回溯到哪个位置继续判断是否匹配的?**

&emsp;首先要知道: 前缀表的任务是当前位置匹配失败，找到之前已经匹配上的位置，再重新匹配，此也意味着在某个字符失配时，前缀表会告诉你下一步匹配中，模式串应该跳到哪个位置。

前缀表**记录了下标i之前(包括i)的字符串中，有多大长度的相同前缀后缀。**

&emsp;

&emsp;

## 最长相等(公共)前后缀

**前缀是指不包含最后一个字符的所有以第一个字符开头的连续子串**。

**后缀是指不包含第一个字符的所有以最后一个字符结尾的连续子串**。

举例: 字符串a的最长相等前后缀为0。 字符串aa的最长相等前后缀为1。 字符串aaa的最长相等前后缀为2。

&emsp;

&emsp;







## 实现next数组

```cpp
void getNext(int *next, const string &s)
{
    // j表示"前缀"的末尾
    // i表示"后缀"的末尾

    // 1. 初始化next数组(存的是最长相等的前后缀长度)
    int j = 0;
    next[0] = j;

    //生成前缀表(next数组)
    for (size_t i = 1; i < s.size(); ++i)
    {
        // 2. 如果前缀末尾与后缀末尾 ≠ 不相等
        while (j > 0 && s[j] != s[i]) //回溯
        {
            j = next[j - 1]; // j的值变为前一个(j-1)位置对应的next数组(前缀表)中存的值
        }

        // 3. 如果前缀末尾与后缀末尾 = 相等
        if (s[j] == s[i])
        {
            ++j;
        }
        next[i] = j;
    }
}
```

> 回溯的只有前缀的下标, 因为我们需要知道当要进行重新匹配的时, 上一个应该匹配的前缀的位置(所以这才叫前缀表啊!)
>
> next数组本质是靠 **前缀的下标**生成的!

**<font size="4">方便理解KMP的步骤</font>**:

1. KMP的核心是next数组, next数组中保存的是: 当该位置不匹配时，应该回溯到哪个位置继续进行匹配? 的信息。
2. next数组的生成过程:
   ①: 设定前缀下标为j, 后缀下标为i。
   ②: **初始化**前缀下标j = 0, next[j] = 0。
   ③: i 从 1 位置开始进行匹配(因为i是后缀, 后缀不能从0开始)
   ④: **判断当该位置不匹配时**, 使用while循环进行不断回溯，直到匹配或者j == 0
   ⑤: **判断当该位置匹配时**, ++j。
   ⑥: **``next[i] = j``**。给next[i]赋值，表示当i位置如果匹配时，应该回溯到j下标处。

&emsp;

&emsp;

## • 28. 实现strStr()

```cpp
void getNext(int *next, const string &s)
{
    // j表示"前缀"的末尾
    // i表示"后缀"的末尾

    // 1. 初始化next数组(存的是最长相等的前后缀长度)
    int j = 0;
    next[0] = j;

    //生成前缀表(next数组)
    for (size_t i = 1; i < s.size(); ++i)
    {
        // 2. 如果前缀末尾与后缀末尾 ≠ 不相等
        while (j > 0 && s[j] != s[i]) //回溯
        {
            j = next[j - 1]; // j的值变为前一个(j-1)位置对应的next数组(前缀表)中存的值
        }

        // 3. 如果前缀末尾与后缀末尾 = 相等
        if (s[j] == s[i])
        {
            ++j;
        }
        next[i] = j;
    }
}

// KMP算法
int strStr(string haystack, string needle)
{
    int next[needle.size()];
    getNext(next, needle);
    
    int j = 0;
    for (int i = 0; i < haystack.size(); ++i)
    {
        while (j > 0 && haystack[i] != needle[j])
        {
            j = next[j - 1];
        }

        if (haystack[i] == needle[j]){
            ++j;
        }

        if(j == needle.size()){ //j==needle.size()说明 j刚判断完最后一个字符, 并且++到了needle.size()
            return i - j + 1;
        }
    }

    return -1;
}
```





## • 459. 重复的子字符串

```cpp
class Solution {
public:
    void getNext(int* next, const string& s)
    {
        int j = 0;
        next[0] = j;
    
        for(int i = 1; i < s.size(); ++i)
        {
            while(j > 0 && s[j] != s[i])
            {
                j = next[j - 1];
            }

            if(s[j] == s[i]){
                ++j;
            }
            next[i] = j;
        }
    }

    bool repeatedSubstringPattern(string s) 
    {
        //思路: 根据next数组的值判断 字符串s是否能被重复的子串构成
        int next[s.size()];
        getNext(next, s);

        //方法1. 笨方法: 取重复的pattern串，然后判断字符串是否能被pattern组成
        // int patternLength = s.size() - next[s.size() - 1];
        // // next[s.size() - 1]不能为0!!!
        // if(patternLength == s.size()){
        //     return false;
        // }
        // string pattern = s.substr(0, patternLength);

        // int i = patternLength;
        // while(i < s.size())
        // {
        //     if(s.substr(i, patternLength) != pattern){
        //         return false;
        //     }
        //     i += patternLength;
        // }
        // return true;


        //方法2. 利用next数组的值进行模运算
        int patternLength = s.size() - next[s.size() - 1];
        if(patternLength == s.size()){  //next[s.size() - 1]值不能为0
            return false;
        }

        if(s.size() % patternLength == 0){
            return true;
        }
        return false;
    }
};
```

