// class Solution {
// public:
//     void _replaceSpace(string& s, int i)
//     {
//         s[i] = '0';
//         s.insert(i,"%2");
//     }

//     string replaceSpace(string s) 
//     {
//         int i = s.size() - 1;
//         while(i >= 0)
//         {
//             if(s[i] == ' ')
//             {
//                 _replaceSpace(s, i);
//             }
//             --i;
//         }
//         return s;
//     }
// };


class Solution{
    public:
        string replaceSpace(string s) 
        {
            //遍历统计多少个space
            int count = 0;
            int i = s.size() - 1;
            for(auto e : s)
            {
                if(e == ' ')
                    ++count;
            }
            //更改大小size
            s.resize(s.size() + 2 * count);
            //倒叙替换
            int j = s.size() - 1;
            for(; i >= 0; --i, --j)
            {
                if(s[i] == ' ')
                {
                    s[j] = '0';
                    s[j - 1] = '2';
                    s[j - 2] = '%';
                    j -= 2;
                }
                else
                s[j] = s[i];
            }
            return s;
        }
};