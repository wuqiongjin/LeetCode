//排序 + 查找(find)	O(NlogN + N*logN)
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        // if(nums.size() <= 1){
        //     return 0;
        // }
        //[1, 1, 3, 4, 5]   k = 2
        sort(nums.begin(), nums.end());
        unordered_set<int> usi;	//这里的去重其实可以不使用set, 直接for循环里面判断, 然后continue就行
        int res = 0;
        for(int i = 0; i < nums.size() - 1; ++i)    //这里走到nums.size() - 1就够了, 因为最后一个元素无法再向右匹配查找了
        {
            auto target = find(nums.begin() + i + 1, nums.end(), nums[i] + k);
            if(target != nums.end() && usi.find(*target) == usi.end()){
                usi.insert(nums[i]);
                usi.insert(*target);
                ++res;
            }
        }
        return res;
    }
};
//优化版 排序 +　查找(可替换为自己手写的二分查找)
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int res = 0;
        for(int i = 0; i < nums.size() - 1; ++i)
        {
            if(i > 0 && nums[i] == nums[i - 1]){    //去重
                continue;
            }
                                 //注意这里是+ i + 1
            auto target = find(nums.begin() + i + 1, nums.end(), nums[i] + k);
            if(target != nums.end()){
                ++res;
            }
        }
        return res;
    }
};



//单纯哈希表	O(N)/O(N)
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_set<int> visited; //保存已经访问过的变量
        unordered_set<int> res;     //保存结果集(x, y)中的x变量  [只保存一个就够了, 最终我们统计x的个数, 就知道有多少个数对了]
        
        //我们只需要遍历一遍数组, 如果元素不在visited, 就添加
        //我们不能提前就把visited哈希表给全部填满, 因为这样会把同一个结果集(x, y)算2遍
        //只有边遍历边添加元素, 才能保证(x, y)结果集只被添加一次
        //使用set还能保证去重, 对于{1, 1, 3}这样的, 1一旦被添加进去, 它也只会算作1种元素, 并不是2个元素。
        for(int num : nums)
        {
            if(visited.count(num - k)){
                res.emplace(num - k);   //结果集(num - k, num), 我们只添加其中一个就够了... (因为最后是看res.size()的)
            }

            if(visited.count(num + k)){
                res.emplace(num);
            }

            visited.emplace(num);
        }
        return res.size();
    }
};



//排序 + 双指针
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if(nums.size() <= 1){
            return 0;
        }
        int res = 0;
        sort(nums.begin(), nums.end());
        for(int left = 0, right = 1; left < nums.size() - 1 && right < nums.size(); ++right)
        {
            //当right遇到重复的时, 此时走到重复元素的最后一个元素处
            while(right < nums.size() - 1 && nums[right] == nums[right + 1])
            {
                ++right;
            }

            while(left < right && nums[left] + k < nums[right])
            {
                ++left;
            }

            if(left != right && nums[left] + k == nums[right]){
                ++res;
            }
            //进入下一轮循环, 此时不管是 nums[left] + k > nums[right] 还是 == nums[right],
        }   //我们都让right++ (这样当 left遇到相同元素的时候, right++后, 保证left不会被重复填入到res中)
        return res;
    }
};