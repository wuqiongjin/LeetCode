// class Solution {
// public:
//     int strStr(string haystack, string needle) {
//         char* p = strstr(&(haystack[0]), &(needle[0]));
//         if(p == nullptr)
//             return -1;
//         else
//             return strstr(&(haystack[0]), &(needle[0])) - &haystack[0];
//     }
// };

//O(NM)的时间复杂度，O(1)空间复杂度。 效率很低 (模拟实现strstr时所用的指针法)

// class Solution {
// public:
//     int strStr(string haystack, string needle) 
//     {
//         if(haystack.size() == 0 && needle.size() == 0)
//             return 0;
//         int len_str = haystack.size();
//         int len_substr = needle.size();
//         int cur = 0, s1 = 0, s2 = 0;

//         while(cur < len_str)
//         {
//             s1 = cur;

//             while(s2 < len_substr && haystack[s1] == needle[s2])
//             {
//                 ++s2;
//                 ++s1;
//             }
//             if(s2 == len_substr)
//                 return cur;
//             ++cur;
//             s2 = 0;
//         }
//         return -1;
//     }
// };

//KMP算法 时间复杂度：O(M + N)  空间复杂度：O(N)
//模式串: 指要进行匹配的子串

class Solution {
public:
    int strStr(string haystack, string needle) 
    {
        int len1 = haystack.size();
        int len2 = needle.size();
        //模式串如果是空串，返回0
        if(len2 == 0)
            return 0;
        
        //构建next数组
        vector<int> next(len2);//len2是模式串的长度
        //1. 初始化
        int j = 0;
        next[0] = j;
        //这里的i必须从1开始。因为0位置处不存在前缀和后缀
        for(int i = 1; i < len2; ++i)
        {
            //2. 如果不匹配，将j进行回溯
            while(j > 0 && needle[i] != needle[j])  //回溯必须使用while循环，因为回溯到前一个位置时，还可能不相同
            {
                //这里使用的是前缀表(next数组直接用作前缀表，并没有进行任何变换)
                j = next[j - 1];//对于前缀表而言：如果不匹配，需要看它的前一个位置的值。然后回溯到前一个位置的值所对应的下标处
            }
            //3. 如果匹配的话，++j
            if(needle[i] == needle[j])
            {
                ++j;
            }
            //4. 更新next[i]的值   注意：更新next数组的是i，因为i是每轮都++的，而j的值不是
            next[i] = j;
        }

        //进行模式串匹配
        j = 0;//j在模式串中进行匹配和回溯
        //i在原串中进行遍历，匹配
        for(int i = 0; i < len1; ++i)
        {
            //1. 不匹配的话，将j进行回溯
            while(j > 0 && haystack[i] != needle[j])  //这里也必须是while循环，因为回溯到next[j - 1]位置时，
                j = next[j - 1];                      //仍有可能与原串的i位置的值不同，(必须回溯到它们相同，或者j回归原点)
            //2. 匹配的话，++j
            if(haystack[i] == needle[j])
                ++j;
            //3. 当j在模式串中走到结尾时，代表匹配成功。返回原串中的起始位置 i - j + 1
            if(j == len2)
                return (i - j + 1);
        }
        return -1;
    }
};