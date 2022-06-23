class Solution {
public:
    //思路: 将数字全部转化为字符串
    //然后进行字符串的拼接比较, 如: 30,3 那么比较 (330)和(303)的大小即可
    //我们可以直接运用这套比较规则对字符串数组进行sort排序, 最后直接把排序的结果拼一起即可
    string largestNumber(vector<int>& nums) {
        vector<string> vs;
        for(auto e : nums)
            vs.push_back(to_string(e));
        
        string res;
        auto cmp = [](const string& a, const string& b){
            return ((a + b) > (b + a));
        };
        sort(vs.begin(), vs.end(), cmp);

        for(auto& e : vs)
            res += e;
        //防止出现全部都是0的组合
        if(res[0] == '0'){
            return "0";
        }
        return res;
    }
};