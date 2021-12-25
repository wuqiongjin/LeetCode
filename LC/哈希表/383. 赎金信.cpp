class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) 
    {
        // //这题用哈希表费空间
        // unordered_map<char, int> umci;
        // for(auto i : magazine)
        //     umci[i]++;
        
        // for(auto i : ransomNote)
        // {
        //     if(umci.find(i) != umci.end() && umci[i] != 0)
        //         umci[i]--;
        //     else
        //         return false;
        // }
        // return true;

        //用普通的数组更节省空间
        int record[26] = {0};
        for(auto i : magazine)
            record[i - 'a']++;
        
        for(auto i : ransomNote)
        {
            if(record[i - 'a'] == 0)
                return false;
            else
                record[i - 'a']--;
        }
        return true;
    }
};