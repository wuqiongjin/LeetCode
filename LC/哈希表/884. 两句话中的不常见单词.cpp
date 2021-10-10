class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) 
    {
        s1 = s1 + " " + s2; //先合并成1个，中间必须加空格！stringstream就是靠空格或换行拆分数据的
        unordered_map<string, int> um;
        stringstream ss;    //stringstream ss(s1);直接构造也可以
        ss << s1;
        vector<string> ans;
        string tmp;
        
        //字符串的反序列化，利用stringstream
        while(ss >> tmp)
            um[tmp]++;
        
        for(auto& e : um)
        {
            if(e.second == 1)
                ans.push_back(e.first);
        }
        return ans;
    }
};


// class Solution {
// public:
//     vector<string> uncommonFromSentences(string s1, string s2) 
//     {
//         unordered_map<string, int> um;
//         int j = 0;
//         for(int i = 0; i <= s1.size(); ++i)
//         {
//             if(s1[i] == ' ' || s1[i] == '\0')
//             {
//                 um[s1.substr(j, i - j)]++;
//                 j = i + 1;
//                 if(s1[i] == '\0')
//                     break;
//             }
//         }
        
//         for(int i = 0, j = 0; i <= s2.size(); ++i)
//         {
//             if(s2[i] == ' ' || s2[i] == '\0')
//             {
//                 um[s2.substr(j, i - j)]++;
//                 j = i + 1;
//                 if(s2[i] == '\0')
//                     break;
//             }
//         }

//         vector<string> ans;
//         for(auto& e : um)
//         {
//             if(e.second == 1)
//                 ans.push_back(e.first);
//         }
//         return ans;
//     }
// };

