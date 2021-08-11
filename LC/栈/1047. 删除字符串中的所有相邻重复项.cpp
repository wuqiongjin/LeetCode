class Solution {
public:
    string removeDuplicates(string s) 
    {
        //使用栈的思路，但是数据结构采用string。因为string中也有类似栈的接口
        string ans;
        for(auto ch : s)
        {
            if(ans.size() != 0 && ans[ans.size() - 1] == ch)
            {
                ans.pop_back();
            }
            else
            {
                ans.push_back(ch);
            }
        }
        return ans;


        //小丑代码。。。

        // stack<char> st;
        // for(int i = 0; i < s.size(); ++i)
        // {
        //     if(!st.empty() && st.top() == s[i])
        //     {
        //         st.pop();
        //     }
        //     else
        //     {
        //         st.push(s[i]);
        //     }
        // }

        // string ans;
        // while(!st.empty())
        // {
        //     ans += st.top();
        //     st.pop();
        // }
        // reverse(ans.begin(), ans.end());
        // return ans;
    }
};