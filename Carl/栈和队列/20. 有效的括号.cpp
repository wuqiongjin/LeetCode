class Solution {
public:
    unordered_set<char> us = {
        '(', '[', '{'
    };

    bool isValid(string s) 
    {
        stack<int> st;
        for(int i = 0; i < s.size(); ++i)
        {
            if(us.find(s[i]) != us.end())
            {
                st.push(s[i]);
            }
            else
            {
                if(st.empty())
                    return false;
                if(s[i] == ')')
                {
                    if(st.top() != '(')
                        return false;
                }
                else if(s[i] == ']')
                {
                    if(st.top() != '[')
                        return false;
                }
                else if(s[i] == '}')
                {
                    if(st.top() != '{')
                        return false;
                }
                st.pop();
            }
        }
        if(st.empty())
            return true;
        return false;
    }
};