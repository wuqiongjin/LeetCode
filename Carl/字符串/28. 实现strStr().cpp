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