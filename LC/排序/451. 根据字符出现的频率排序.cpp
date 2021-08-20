class Solution {
public:
    string frequencySort(string s) 
    {
        //先利用计数排序的思想，将对应的字符放在对应的下标的位置处
        pair<int, int> p[75];   //更推荐使用vector<pair<int, int>> v;
        for(auto& e : s)
        {
            p[e - '0'].first++;
            p[e - '0'].second = e - '0'; 
        }

        //sort对pair的默认排序是：以pair中的第一个元素为标准的升序排列（想要修改规则需要自己实现函数指针或仿函数）
        sort(p, p + 75);
        reverse(p, p + 75); //不reverse的话，就要使用降序排列。（懒得自己写了）

        string ans;
        for(int i = 0; i < 75; ++i)
        {
            for(int j = 0; j < p[i].first; ++j)
            {
                ans += p[i].second + '0';
            }
        }
        return ans;
    }
};