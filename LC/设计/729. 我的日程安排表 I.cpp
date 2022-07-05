class MyCalendar {
public:
    MyCalendar() {
    }
    //只要start < s && end > f , 那么start 和 end必然和当前日程表冲突!
    bool book(int start, int end) {
        for(auto& [f,s] : vp)
        {
            if(start < s && end > f){   //仔细画一画想想
                return false;
            }
        }

        vp.emplace_back(start, end);
        return true;
    }
    
    vector<pair<int,int>> vp;
};


//借助set进行排序查找
class MyCalendar {
public:
    MyCalendar() {
    }
    //思路
    //找到第一个比end大的[f,s]的f的区间。
    //然后让start与这个区间的前面一个区间进行比较
    //设[f1,s1] [f2, s2], 我们通过end找到了[f2,s2]区间, 此时end <= f2
    //我们接下来只需要判断 start >= s1 即可!
    bool book(int start, int end) {
        auto it = sp.lower_bound({end,0});
        if((it == sp.begin()) || (--it)->second <= start){
            sp.emplace(start, end);
            return true;
        }
        return false;
    }

    set<pair<int,int>> sp;
};