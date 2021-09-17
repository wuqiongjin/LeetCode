//这个代码是针对所有运算符的，包括'('与')'。所给字符串可以出现负数，结果也可能超出整形范围

class Solution {
public:
    //无序集合存放优先级
    unordered_map<char,int> symbol_pri = 
    {
            {'+',1},
            {'-',1},
            {'*',2},
            {'/',2},
            {'%',2},
            {'^',3}
    };

    void _calculate()
    {
        long long x = nums.top(); nums.pop();
        long long y = nums.top(); nums.pop();
        long long tmp = 0;
        switch(symbol.top())
        {
            case '+': tmp = y + x; break;
            case '-': tmp = y - x; break;
            case '*': tmp = y * x; break;
            case '/': tmp = y / x; break;
            case '%': tmp = y % x; break;
            case '^': tmp = pow(y, x); break;
        }
        nums.push(tmp);
        symbol.pop();
    }

    int calculate(string s) 
    {
        //不管三七二十一，直接在数据栈中加一个0，这样能防止第一个数是负数
        //如果不是负数，那就无所谓了，这个0就相当于多余了。最后数据栈会有2个元素，0 和 最后的结果，我们返回top就行
        nums.push(0);
        
        for(int i = 0;i < s.size(); ++i)
        {
            if(s[i] == ' ')
                continue;
            else if(isdigit(s[i]))
            {
                int j = i;
                while(i + 1 < s.size() && isdigit(s[i + 1]))    //每次对 i + 1进行判断，这样最后就不用 --i了
                    ++i;
                nums.push(stoll(s.substr(j, i - j + 1)));  //substr取数字字符串
            }
            else if(s[i] == '(')
            {
                symbol.push('(');
                
                //处理 '(' 紧挨的数字是负数
                while(s[i + 1] == ' ')
                    ++i;
                if(s[i + 1] == '-')
                {
                    nums.push(0);   //防止 '(' 紧挨的的那个数字是负数，要在 '-' 前面加个0方便处理
                    symbol.push(s[i + 1]);
                    ++i;    //'-'已经录入，所以++i
                }
            }
            else if(s[i] == ')')
            {
                while(symbol.top() != '(')
                {
                    _calculate();                    
                }
                symbol.pop();   //把 '(' pop掉
            }
            else    //普通操作符
            {
                //这里用while循环的原因：
                //因为可能存在连续计算的情况
                //注意：遇到 '(' 或 符号栈为空 要停止计算
                //优先级的判断条件：当 [栈内的运算符] >= [当前的运算符] 就行进行运算
                while(!symbol.empty() && symbol.top() != '(' && symbol_pri[s[i]] <= symbol_pri[symbol.top()])
                    _calculate();
                symbol.push(s[i]);

                // if(symbol.empty())
                //     symbol.push(s[i]);
                
                // //判断优先级
                // if(symbol_pri[s[i]] > symbol_pri[symbol.top()])
                //     symbol.push(s[i]);
                // else         //✖，这里可能要进行多次运算，不能使用if else
                // {
                //     _calculate();
                //     symbol.push(s[i]);
                // }
            }
        }
        
        while(!symbol.empty())
            _calculate();

        return nums.top();
    }

    //存在外面方面函数直接调用
    stack<char> symbol;
    stack<long long> nums;  //int怕整形溢出
};