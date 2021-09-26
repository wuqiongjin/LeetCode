class Solution {
public:
    vector<int>& CreaterSubSequence(vector<int>& subsequence, int left, int right)
    {
        while(left <= right)
        {
            subsequence.push_back(left);
            ++left;
        }
        return subsequence;
    }

    vector<vector<int>> findContinuousSequence(int target) 
    {
        if(target == 1 || target == 2)
            return vector<vector<int>>();
        int left = 1, right = 2;
        int sum = left + right;
        vector<int> subsequence;
        vector<vector<int>> ans;

        //[left, right]
        //如果sum < target，让right++
        //   sum > target, 让left++
        //sum == target后，放入结果集合。然后让 ++left，继续寻找子集

        while(left < (target + 1) / 2)
        {
            if(sum < target)
            {
                ++right;
                sum += right;
            }
            else if(sum > target)
            {
                sum -= left;
                ++left;
            }
            else
            {
                vector<int> subsequence;
                ans.push_back(CreaterSubSequence(subsequence, left, right));
                sum -= left;
                ++left;
            }
        }
        return ans;
    }
};