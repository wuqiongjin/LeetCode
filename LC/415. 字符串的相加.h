class Solution {
public:
    // void _swap(char& x, char& y)
    // {
    //     char tmp = x;
    //     x = y;
    //     y = tmp;
    // }
    // void reverse_string(string& s)
    // {
    //     int begin = 0, end = s.size() - 1;
    //     while(begin < end)
    //     {
    //         _swap(s[begin], s[end]);
    //         ++begin;
    //         --end;
    //     }
    // }

//这题没必要用迭代器。。。
//用下标就可以解决了。。。
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
                ++it1; 				//迭代器的++ 要注意小心越界 （如果已经到.rend()时，再++就是越界访问）
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
		//注意！！！如果还有进位，要进行判断。比如 1 + 9 。 此时出了while循环时，还有进位需要加
        if(takeOver)
        {
            res += '1';
        }
        //reverse_string(res);
        reverse(res.begin(), res.end());//逆置算法 [迭代器的两端范围]
        return res;
    }
};