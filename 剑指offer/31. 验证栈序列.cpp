class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) 
    {
        //模拟栈的操作
        //入栈就直接入
        //每次入完和popV的起始元素进行比较，如果相同就出栈，直到不能出为止
        //然后再继续入，当pushV的元素全部入完。popV也停止判断了(可能全部弹出了，也可能没有)，就跳出循环
        //栈为空就是true，不为空就是false
        
        stack<int> st;
        
//         int i  = 0, j = 0;
//         while(!st.empty() || i < pushV.size())
//         {
//             if(i < pushV.size())
//             {
//                 st.push(pushV[i]);
//                 ++i;
//             }
//             while(!st.empty() && st.top() == popV[j])
//             {
//                 ++j;
//                 st.pop();
//             }
//             if(!st.empty() && i >= pushV.size())
//                 return false;
//         }
        
        int i = 0, j = 0;
        while(i < pushV.size())
        {
            st.push(pushV[i]);
            ++i;
            
            while(!st.empty() && st.top() == popV[j])
            {
                ++j;
                st.pop();
            }
        }
        
		//return st.empty();
		
        if(st.empty())
            return true;
        else
            return false;
    }
};