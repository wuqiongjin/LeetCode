class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) 
    {
        //统计每个string出现的次数
        map<string, int> countMap;
        for(auto& e : words)
            countMap[e]++;
        //利用multimap，通过遍历countMap，去将每个结点对应的数字插入resMap中。
        //按照从大到小的顺序。利用multimap而不是反向遍历conutMap的原因在于：
        //它就可以保证countMap中对字母顺序的排序。比如 i 和 love，如果都出现2次。
        //那么会先取到countMap中的i放到resMap中。这样在结果数组ans中的顺序就是正确的！
        multimap<int, string, greater<int>> resMap;
        for(auto& e : countMap)
            resMap.insert(make_pair(e.second, e.first));
        vector<string> ans;
        multimap<int, string, greater<int>>::iterator it = resMap.begin();
        while(it != resMap.end())
        {
            if(k == 0)
                break;
            
            ans.push_back(it->second);
            ++it;
            --k;
        }
        return ans;
    }
};