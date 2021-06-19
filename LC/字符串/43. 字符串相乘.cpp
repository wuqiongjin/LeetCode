class Solution {
public:
		//方法1：
        string addStrings(string num1, string num2) {       
        auto it1 = num1.rbegin();
        auto it2 = num2.rbegin();
        string res;
        int takeOver = 0;
        while(it1 != num1.rend() || it2 != num2.rend())
        {
            int val1 = 0, val2 = 0;
            if(it1 != num1.rend())
            {
                val1 = *it1 - '0';
                ++it1; 
            }

            if(it2 != num2.rend())
            {
                val2 = *it2 - '0';
                ++it2;
            }
            int Add = val1 + val2 + takeOver;
            if(Add > 9)
            {
                Add -= 10;
                takeOver = 1;
            }
            else
                takeOver = 0;
            res += (Add + '0');
        }

        if(takeOver)
        {
            res += '1';
        }
        reverse(res.begin(), res.end());//逆置算法 [迭代器的两端范围]
        return res;
    }

    //竖式乘法 1:模拟乘法，最后用调用字符串加法函数
    //从右向左遍历， O(M ^ 2 * N)
    string multiply(string num1, string num2) 
    {
        vector<string> v(num2.size());
        if(num2[0] - '0'== 0 || num1[0] - '0' == 0)
        {
            v[0] = "0";
            return v[0];
        }
        for(int i = num2.size() - 1; i >= 0; --i)
        {
            int takeOver = 0;
            for(int j = num2.size() - 1; j > i; --j)
                v[i] += '0';
            
            for(int j = num1.size() - 1; j >= 0; --j)
            {
                int val = (num2[i] - '0') * (num1[j] - '0');
                val += takeOver;
                takeOver = val / 10;
                val %= 10;
                v[i] += val + '0';
            }
            if(takeOver)
            {
                v[i] += takeOver + '0';
            }
            reverse(v[i].begin(), v[i].end());
        }
        string res = v[0];
        for(int i = 1; i < v.size(); ++i)
        {
            res = addStrings(res, v[i]);
        }
        return res;
    }


	//方法2：
    //优化竖式乘法， : 每个数字相乘，乘出的结果存到vector中，vector的大小是 n1 + n2
    //                最后进行 取模 和 进位 的操作
    string multiply(string num1, string num2)
    {
        int n1 = num1.size();
        int n2 = num2.size();
        string ans;
        //乘数中有0的话，直接返回0.
        if(num1 == "0" || num2 == "0")
        {
            ans += "0";
            return ans;
        }      
        
        vector<int> v(n1 + n2);        
        for(int j = n2 - 1; j >= 0; --j)
        {
            for(int i = n1 - 1; i >= 0; --i)
            {
                //因为最后要对vector进行逆置，所以index的起始位置就是0，最大值是 n1 + n2 - 2;
                int index = n1 - 1 - i + n2 - 1 - j;    //index是vector中的下标 
                int val = (num1[i] - '0') * (num2[j] - '0');
                if(val < 10)
                {
                    v[index] += val;
                }
                else
                {
                    v[index++] += val % 10;
                    v[index] += val / 10;
                }
            }
        }
        
        //这里进行取模和进位的操作。
        //因为vector的大小是n1 + n2，所以并不用担心takeOver还需要额外判断的问题
        int takeOver = 0;
        int index = 0;
        for(; index < v.size(); ++index)
        {
            // if(v[index] >= 10)
            //{
                
                //直接判断就可以了，因为不管v[index] 大不大于10，都要进行下面的操作
                v[index] += takeOver;
                takeOver = v[index] / 10;
                v[index] %= 10;
            
            //}
            // else
            // {
            //     v[index] += takeOver;
            //     takeOver = v[index] / 10;
            //     v[index] %= 10;
            // }

        }

        //最后需要逆置一下vector数组
        reverse(v.begin(), v.end());
        
        //这里需要过滤掉最高位的0。(如果有0的话)
        int i = 0;
        while(i < v.size() && v[i] == 0)
            ++i;
        //整形转char
        for(; i < v.size(); ++i)
        {
            ans += v[i] + '0';
        }
        return ans;
    }       
    
};