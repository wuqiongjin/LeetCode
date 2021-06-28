class Solution {
public:

    //判断string是否为数字的(整数、小数、负数、科学计数法都可以)
    // bool isNumber(const string& str) 
    // {	
    //     //判断字符串是否为数字
    //     istringstream sin(str);
    //     double test;
    //     return sin >> test && sin.eof();
    // }

    //针对本题，因为题中的数字都是整数，所以只要判断第一个字符是什么就可以了
    //如果第一个字符不是数字，且string的长度还是1的话，return false [考虑负数了]
    //除此之外都是true
    bool isNum(const string& s)
    {
        if(s.size() == 1 && !isdigit(s[0]))
            return false;
        return true;
    }

    int evalRPN(vector<string>& tokens) 
    {
        //逆波兰表达式求值规则(逆波兰表达式 转 中缀表达式)
        //1. 遇到数字直接入栈
        //2. 遇到符号，将栈顶的2个数字先出栈，然后计算用该符号去计算它们的结果。最后再将结果入栈

        string s = "+-*/";
        stack<int> st;
        for(int i = 0; i < tokens.size(); ++i)
        {
            if(isNumber(tokens[i]))
            {
                st.push(stoi(tokens[i]));
            }
            else
            {
                int val;
                int x = st.top();
                st.pop();
                int y = st.top();
                st.pop();

                if(tokens[i][0] == s[0])
                    val = y + x;
                else if(tokens[i][0] == s[1])
                    val = y - x;
                else if(tokens[i][0] == s[2])
                    val = y * x;
                else
                    val = y / x;
                //将结果push入栈
                st.push(val);
            }
        }
        return st.top();
    }
};