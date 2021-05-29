class Solution {
public:
    vector<vector<int>> generate(int numRows) 
    {
        //画图很关键

        //开辟类似二维数组
        vector<vector<int>> vv;
        vv.resize(numRows);
        for(size_t i = 0; i < numRows; ++i)
        {
            vv[i].resize(i + 1);    //为每个vector中的vector开辟空间

            //另一种思路，可以在开辟空间的时候直接进行1的设置。
            //在开辟空间的时候直接进行 1 的设置。 这样的话，后面就不用再单独进行1的设置了。
            //后面只需要遍历整个vector，当vector中的元素不为1的时候，进行求和的运算        
            // vv[i][0] = 1;
            // vv[i][vv[i].size() - 1] = 1;
        }

        //存入数据
        for(size_t i = 0; i < vv.size(); ++i)
        {
            for(size_t j = 0; j < vv[i].size(); ++j)
            {
                if(j != 0 && j != i)    //每列第1个都设置成1，每行最后1个都设置成1
                    vv[i][j] = vv[i - 1][j - 1] + vv[i - 1][j];
                else
                    vv[i][j] = 1;
            }
        }

        return vv;
    }
};