class Solution {
public:
    //模拟实现法： 使用vector<string>
    string convert(string s, int numRows) {
        vector<string> store(numRows);
        int index = 0;
        int len = s.size();
        //设一个flag控制i是向上还是向下
        int flag = -1;
        while(index < len)
        {
            int i = 0;
            flag *= -1;
            if(flag == 1)
            {
                //向下++
                for(i = 0; i < numRows && index < len; ++i)
                {
                    store[i] += s[index++]; 
                }
            }
            else
            {
                //向上--
                //注意：这里的i的判断条件是 i > 0。 不能取等，否则第一行的那个位置将会重复录入1次
                for(i = numRows - 2; i > 0 && index < len; --i)
                {
                    store[i] += s[index++];
                }
            }
        }
  //      cout << store[0] << " " << store[1] << " " << store[2] << endl;

        //合并字符串
        for(int i = 1; i < numRows; ++i)
        {
            store[0] += store[i];
        }
        return store[0];
    }
};