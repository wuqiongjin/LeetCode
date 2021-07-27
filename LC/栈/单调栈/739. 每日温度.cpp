class Solution {
public:
    //单调栈
    // vector<int> dailyTemperatures(vector<int>& temperatures) 
    // {
    //     vector<int> ans(temperatures.size());
    //     stack<int> st;
    //     for(int i = temperatures.size() - 1; i >= 0; --i)
    //     {
    //         if(st.empty())
    //         {
    //             st.push(i);
    //             ans[i] = 0;                
    //         }
    //         else
    //         {
    //             if(temperatures[i] >= temperatures[st.top()])
    //             {
    //                 while(!st.empty() && temperatures[i] >= temperatures[st.top()])
    //                 {
    //                     st.pop();
    //                 }
    //                 //如果栈为空，说明i位置后面没有比它更大的了
    //                 if(st.empty())
    //                     ans[i] = 0;
    //                 else
    //                     ans[i] = st.top() - i;

    //                 st.push(i);
    //             }
    //             else
    //             {
    //                 ans[i] = st.top() - i;
    //                 st.push(i);
    //             }
    //         }
    //     }
    //     return ans;

    // }


    //简化版本	-	单调栈 O(N)
    vector<int> dailyTemperatures(vector<int>& temperatures) 
    {
        vector<int> ans(temperatures.size());
        stack<int> st;
        for(int i = temperatures.size() - 1; i >= 0; --i)
        {
            while(!st.empty() && temperatures[i] >= temperatures[st.top()])
            {
                st.pop();
            }
            //栈为空，则当前位置后面没有比它更大的值了
            if(st.empty())
                ans[i] = 0;
            else    //栈不为空，栈顶元素的值 - 当前元素的下标
                ans[i] = st.top() - i;

            st.push(i);
        }
        return ans;
    }
};