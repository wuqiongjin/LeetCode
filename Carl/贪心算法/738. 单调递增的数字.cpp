//n = 1234321, 2322332
//res=1233999, 2299999
//当num[i - 1] > num[i]时, 让num[i - 1]--, 然后让num[i]变为9(即, 借一位)
//而num[i - 1] <= num[i]时, 不需要做任何处理
class Solution {
public:
    int monotoneIncreasingDigits(int n) 
    {
        string num = to_string(n);	//转为字符串进行处理
        int start = num.size();	//标志'9'从哪里开始往后设置
        //逆序遍历(正序不好处理, 比如332, 正序遍历完是329, 此时依然不满足题意)
		for(int i = num.size() - 1; i > 0; --i)
        {
            if(num[i - 1] > num[i]){
                start = i;
                num[i - 1]--;
            }
        }

        for(int i = start; i < num.size(); ++i)
        {
            num[i] = '9';
        }
        return stoi(num);
    }
};