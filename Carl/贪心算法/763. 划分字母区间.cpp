class Solution {
public:
    //记录每个字母出现的最大下标值
    //然后从头开始往后遍历, 当下标i == border值是时, 代表前面的区间的所有字母只出现在前面的那个区间了
    vector<int> partitionLabels(string s) 
    {
        //使用哈希表记录字母出现的最大下标
        // unordered_map<char,int> umci;
        // for(int i = 0; i < s.size(); ++i)
        // {
        //     umci[s[i]] = max(umci[s[i]], i);
        // }

        // vector<int> count(s.size());
        // for(int i = 0; i < s.size(); ++i)
        // {
        //     count[i] = umci[s[i]];
        // }

        // vector<int> res;
        // int before = 0;
        // int border = count[0];
        // for(int i = 0; i < count.size(); ++i)
        // {
        //     if(i >= border){
        //         if(res.empty()){
        //             res.push_back(i + 1);
        //         }
        //         else{
        //             res.push_back(i + 1 - before);
        //         }
        //         before = i + 1;
        //         if(i + 1 < count.size()){
        //             border = count[i + 1];
        //         }
        //     }
        //     else{
        //         border = max(border, count[i]);
        //     }
        // }
        // return res;


        //直接使用数组进行哈希
        int hash[27] = { 0 };
        for(int i = 0; i < s.size(); ++i)
        {
            hash[s[i] - 'a'] = i;   //记录每个字母出现的最大下标
        }

        vector<int> res;
        int border = 0;
        int before = 0;
        for(int i = 0; i < s.size(); ++i)
        {
            border = max(border, hash[s[i] - 'a']);
            if(i == border){
                res.push_back(i + 1 - before);
                before = i + 1;
            }
        }
        return res;
    }
};
};