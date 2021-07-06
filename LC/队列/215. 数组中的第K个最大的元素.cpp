class Solution {
public:

    //使用最小堆来解决TopK问题变种
    //时间复杂度：O(N * logK)
    //空间复杂度：O(K)
    int findKthLargest(vector<int>& nums, int k) 
    {
        //构造函数可以传迭代器的范围以用来初始化
        priority_queue<int, vector<int>, greater<int>> pq(nums.begin(), nums.begin() + k);

        //调堆的时间复杂度为O(logK)。外层循环遍历时间复杂度为O(N)。
        for(int i = k; i < nums.size(); ++i)
        {
            if(nums[i] > pq.top())
            {
                pq.pop();
                pq.push(nums[i]);
            }
        }
        return pq.top();
    }
};