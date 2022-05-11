class Solution {
public:
    // 优先队列 + 哈希表
    // 优先队列使用最小堆
    // 先通过哈希表统计出每个数字出现的次数,
    // 遍历哈希表，将pair<数据, 次数> 放入优先队列
    // 当优先队列大小 > K时，pop掉堆顶元素
    // 每次都丢掉最小的元素。当遍历完哈希表后，优先队列剩下的就是TopK大的元素了。

    // pair + 哈希表
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        unordered_map<int, int> umii;   //统计每个数字出现的次数
        vector<pair<int, int>> vp;      //存放从哈希表中拿出的数字和数字出现的次数
        vector<int> res;                //存放vp中排过序的TopK个结果

        for(auto e : nums)
            umii[e]++;
    
        for(auto& e : umii)
        {
            vp.emplace_back(e.first, e.second);
        }
        
        sort(vp.begin(), vp.end(), [](pair<int,int>& p1, pair<int,int>& p2){
            return p1.second > p2.second;   //注意:　我们要排降序(TopK大的)
        });

        for(int i = 0; i < k; ++i)
        {
            res.push_back(vp[i].first);
        }

        return res;
    }
};