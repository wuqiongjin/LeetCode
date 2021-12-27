class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) 
    {
        unordered_map<int, int> umii;
        for(int a : nums1)
            for(int b : nums2)
            {
                umii[a + b]++;
            }

        int count = 0;
        for(int c : nums3)
            for(int d : nums4)
            {
                if(umii.find(0 - (c + d)) != umii.end())
                {
                    count += umii[0 - (c + d)];
                }
            }
        return count;
    }
};