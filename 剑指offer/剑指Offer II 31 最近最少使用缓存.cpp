class LRUCache {
public:
    LRUCache(int capacity) 
        :_capacity(capacity)
    {}
    
    int get(int key) {
        auto ret = hashMap.find(key);
        if(ret != hashMap.end()){
            auto it = ret->second;   //对应LRUList位置的迭代器
            LRUList.splice(LRUList.begin(), LRUList, it);
            return it->second;
        }
        return -1;
    }
    
    void put(int key, int value) {
        auto ret = hashMap.find(key);
        if(ret != hashMap.end()){   //数据已存在, 更新value
            auto it = ret->second;
            it->second = value;
            LRUList.splice(LRUList.begin(), LRUList, it);
            hashMap[key] = LRUList.begin();
        }
        else{   //数据未存在, 判断capacity是否满
            if(hashMap.size() >= _capacity){    //数据已经满了, 替换最久未使用
                hashMap.erase(hashMap.find(LRUList.back().first));
                LRUList.pop_back();
            }
            // else{   //数据未满, 直接插入到链表头部
                LRUList.emplace_front(key, value);
                hashMap[key] = LRUList.begin();
            // }
        }
    }

    typedef list<pair<int,int>>::iterator iter;
    list<pair<int,int>> LRUList;    //存放数据节点(key, value); 头部存放最新数据, 尾部是最久未使用的
    unordered_map<int,iter> hashMap;
    size_t _capacity;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */