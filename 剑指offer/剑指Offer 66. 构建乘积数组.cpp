class Solution {
public:
    //两次遍历
    //第一次正序遍历, 对于每一个a[i], 计算它的a[0] ~ a[i - 1]的乘积和到b[i]进行存储
    //第二次逆序遍历, 对于每一个a[i], 计算它的a[i + 1] ~ a[n]的乘积和到b[i]从而算出最终结果
    //          [        1,         2,          3,          4,           5]
    //第一次遍历:[        1,         1,        1*2,      1*2*3,     1*2*3*4]
    //第二次遍历:[(2*3*4*5), 1*(3*4*5),  1*2*(4*5),  1*2*3*(5),     1*2*3*4]
              //()表示逆序遍历在进行累积的过程
    vector<int> constructArr(vector<int>& a) {
        vector<int> b(a.size(), 1); //结果数组
        int tmp = 1;
        //a[0] ~ a[i - 1]
        for(int i = 1; i < a.size(); ++i)
        {
            b[i] *= b[i - 1] * a[i - 1];
        }

        //a[n - 1] ~ a[i + 1]
        for(int i = a.size() - 2; i >= 0; --i)
        {
            tmp *= a[i + 1];
            b[i] *= tmp;
        }

        return b;
    }
};


//用除法了(不让用的)
class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        int zeroIndex = -1;
        int sum = 1;
        for(int i = 0; i < a.size(); ++i)
        {
            if(a[i] == 0){
                if(zeroIndex != -1){
                    a.assign(a.size(), 0);
                    return a;
                }
                else{
                    zeroIndex = i;
                }
            }
            else{
                sum *= a[i];
            }
        }

        if(zeroIndex != -1){
            a.assign(a.size(), 0);
            a[zeroIndex] = sum;
            return a;
        }

        for(int i = 0; i < a.size(); ++i)
        {
            a[i] = sum / a[i];
        }

        return a;
    }
};