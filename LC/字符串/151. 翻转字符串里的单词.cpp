//方法1：硬做
//创建string ans保存结果。然后从末尾开始添加单词和去除空格

// class Solution {
// public:
//     string reverseWords(string s) 
//     {
//         //"Hello  World  "
//         //"World Hello"
//         string ans;
//         int start = s.size() - 1;
//         int end = s.size() - 1;
//         bool first = false;
//         while(start >= 0)
//         {
//             while(start >= 0 && s[start] == ' ')
//             {
//                 --start;
//                 --end;
//             }
//             if(start < 0)
//                 break;
//             if(first)
//                 ans += ' ';

//             while(start >= 0 && s[start] != ' ')
//             {
//                 --start;
//             }
            
//             if(start >= -1)
//             {
//                 ans += s.substr(start + 1, end - start);
//                 first = true;
//             }
//             end = start;
//         }
//         return ans;
//     }
// };



//方法2：先整体翻转再局部翻转
//整体思路: 三个下标，index是从0位置开始更新字符串,start是单词的起始位置，end是单词的终止位置
//先整体翻转。
//然后start遍历string，去找单词的起始位置。
//找到单词后，让end = start，然后s[index++] = s[end++]开始对index下标处进行更新覆盖，
//更新完1个单词后，将这个单词翻转reverse
//最后在单词的后面加上空格s[index++] = ' ';
//start遍历结束后，删除index - 1位置后面的字符

class Solution {
public:
    string reverseWords(string s) 
    {
        //先反转整体，再反转每个单词
        reverse(s.begin(), s.end());
        //index是用来更新字符串的。
        //当index结束的时候，每个单词的反转，以及单词和单词之间的空格也会处理好。就只差最后一个单词的后面的空格了
        int index = 0;
        for(int start = 0; start < s.size(); ++start)
        {
            //当start指向空格的时候，++start。直到找到单词位置
            if(s[start] != ' ')
            {
                //在每个单词"前面"加空格，第一个单词前面不加
                // if(index != 0)
                //     s[index++] = ' ';
                
                //对index进行覆盖，除去单词之间的空格
                int end = start;
                while(end < s.size() && s[end] != ' ')
                    s[index++] = s[end++];
                
                //reverse单个单词
                reverse(s.begin() + index - (end - start), s.begin() + index);
                
                //更新start去找下一个单词
                start = end;

                //在每个单词的"后面"加个空格。要注意，这样也会导致最后1个单词也加空格。
                //因为erase的时候起始位置要-1
                s[index++] = ' ';
            }
        }
        //erase的位置就是index - 1的位置(index位置是空格)，因为字符串已经更新完成了。
        //index - 1后面的都可以删除掉
        s.erase(s.begin() + index - 1, s.end());
        return s;
    }
};


//方法3：头插逆置法(借助容器deque/list也可以)