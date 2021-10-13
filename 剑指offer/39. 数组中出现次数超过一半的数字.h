//C++
class Solution {
public:
    //哈希表
    int majorityElement(vector<int>& nums) 
    {
        unordered_map<int, int> countMap;
        for(auto e : nums)
        {
            countMap[e]++;
            if(countMap[e] > (nums.size() / 2)) //如果大于数组长度的一般，直接return
                return e;
        }
        //走到这里的话，说明最后一个元素加了之后，才大于长度的一半
        return nums[nums.size() - 1];
    }
};


int majorityElement(int* nums, int numsSize)
{
    //摩尔投票法
	//2个证明该方法肯定是正确的推论：
	//推论一：若记众数的票数为+1 ，非众数的票数为 -1，则一定有所有数字的票数和 > 0 。
	//推论二：若数组的前a个数字的 票数和 = 0，则 数组剩余(n-a)个数字的票数和一定仍 >0 ，即后 (n-a)个数字的 众数仍为 x 。

    int x = nums[0];
    int vote = 0;
    int i = 0;
    for(i = 0; i < numsSize; ++i)
    {
        //票数为0，则证明后面的数字中的众数也必然和整体的众数相同
        //此时可以丢弃前面的所有数字，重新定义 x
        if(vote == 0)
        {
            x = nums[i];
            ++vote;
        }
        else
        {
            //和假设的x相同的票数+1  否则-1
            x == nums[i] ? ++vote : --vote;
        }
    }
    //返回到这里的x有2种情况
    //1. 最后前面的所有元素都抵消了，只剩1个元素x，返回它，它也必定是众数
    //2. 遍历完所有元素后，最终票数vote = 1， 那么此时假设的x就是正确的，也就是众数
    return x;
}