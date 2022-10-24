struct SkiplistNode{
    int val;
    vector<SkiplistNode*> nextV;

    SkiplistNode(int num, int level)
        :val(num)
        ,nextV(level, nullptr)
    {}
};

class Skiplist {
public:
    Skiplist() 
        :head(new SkiplistNode(-1, 1))  //头结点处我们初始化它是1层的(其实也可以直接拉到32层maxLevel,不过性能略有损耗)
    {
        srand(time(nullptr));   //生成随机数种子
    }
    
    bool search(int target) {
        SkiplistNode* cur = head;
        int level = cur->nextV.size() - 1;  //层数的下标

        //当level小于0时退出循环
        while(level >= 0)
        {
            //1. 当前结点的下一个为nullptr 或 下一个的值 > target, 此时向下走
            if(cur->nextV[level] == nullptr || cur->nextV[level]->val > target){
                --level;
            }//2. 当前结点的下一个不为nullptr && 下一个的值 < target, 此时向右走
            else if(cur->nextV[level]->val < target){
                cur = cur->nextV[level];
            }//3. 下一个的值 == target
            else{
                return true;
            }
        }
        return false;
    }
    
    //找prevV, add和erase均需要用
    vector<SkiplistNode*> findPrevVector(int target){
        SkiplistNode* cur = head;
        int level = cur->nextV.size() - 1;  //下面使用的都是下标, 所以这里作-1处理
        vector<SkiplistNode*> prevV(level + 1, head); //这里的prevV数组中, "i下标处存储的是第i+1层"的前一个节点
                                 //这里prevV默认初始化必须为head, 因为SkipList为空时, 插入的前一个节点一定是head
        while(level >= 0)
        {
            //1. 当下一个为nullptr 或 下一个的值 >= target, 此时向下走。(这里考虑允许数据冗余了)
            if(cur->nextV[level] == nullptr || cur->nextV[level]->val >= target){
                prevV[level] = cur; //prevV[level]存的是cur!!!
                --level;
            }
            else{//2. 当下一个不为nullptr && 下一个的值 < target
                cur = cur->nextV[level];
            }
        }
        return prevV;
    }

    void add(int num) {
        int level = randomLevel();  //随机生成层数
        if(level > head->nextV.size()){ //判断是否需要更新头结点的层数
            head->nextV.resize(level, nullptr);
        }
        vector<SkiplistNode*> prevV = findPrevVector(num);
        SkiplistNode* newNode = new SkiplistNode(num, level);
        //更新连接关系
        for(size_t i = 0; i < level; ++i)
        {
            newNode->nextV[i] = prevV[i]->nextV[i]; //prevV[i]: i下标就是第i+1层的前一个结点
            prevV[i]->nextV[i] = newNode;
        }
    }
    
    bool erase(int num) {
        vector<SkiplistNode*> prevV = findPrevVector(num);
        //先判断num值是否存在. 判断prevV[0]的下一个是否为nullptr, 以及下一个值是否为num
        //这里必须使用0下标, 其它下标的层数可能不存在
        if(prevV[0]->nextV[0] == nullptr || prevV[0]->nextV[0]->val != num){
            return false;
        }
        else{//删除, 并更新连接关系
            SkiplistNode* delNode = prevV[0]->nextV[0];
            for(size_t i = 0; i < delNode->nextV.size(); ++i)
            {
                prevV[i]->nextV[i] = delNode->nextV[i];
            }
            delete delNode;

            //判断是否需要更新头结点nextV的大小(无关紧要)
            size_t i = head->nextV.size() - 1;
            for(; i >= 0; --i)
            {
                if(head->nextV[i] != nullptr)
                    break;
            }
            head->nextV.resize(i + 1);

            return true;
        }
    }

    int randomLevel(){
        int level = 1;
        //rand()的概率是[0, RAND_MAX], 我们这里限定rand() < RAND_MAX * p, 这个概率正好为p
        while(rand() <= RAND_MAX * p && level < maxLevel)
        {
            ++level;
        }
        return level;
    }

private:
    SkiplistNode* head;
    size_t maxLevel = 32;
    double p = 0.25;
};

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */