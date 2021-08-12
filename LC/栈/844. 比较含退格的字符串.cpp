//也可以使用双指针，逆着遍历

class Solution {
public:
    bool backspaceCompare(string s, string t) 
    {
        string cmp_s, cmp_t;
        for(auto ch : s)
        {
            if(!cmp_s.empty() && ch == '#')
            {
                cmp_s.pop_back();
            }
            else if(ch != '#')
            {
                cmp_s.push_back(ch);
            }
        }
        for(auto ch : t)
        {
            if(!cmp_t.empty() && ch == '#')
            {
                cmp_t.pop_back();
            }
            else if(ch != '#')
            {
                cmp_t.push_back(ch);
            }
        }
        return !strcmp(cmp_s.c_str(), cmp_t.c_str());
    }
};