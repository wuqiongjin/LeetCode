int majorityElement(int* nums, int numsSize)
{
    //摩尔投票法
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