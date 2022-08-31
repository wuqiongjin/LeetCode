class Solution {
public:
    //归并排序子函数, 合并两个区间, 并在合并的过程中计算逆序对的个数
    //[1,3,5,7] [0,4,6,8]
    //这样两个区间, 只有在右区间的j小于左区间的i时, 才能统计入逆序对中
    //[0,1,3,5,7] , 此时count += 左区间的剩余元素个数(mid - i + 1) = 4, count += 4;
    int mergeAndCount(vector<int>& nums, int left_begin, int left_end, \
    int right_begin, int right_end, vector<int>& tmp){
        for(int i = left_begin; i <= right_end; ++i)
        {
            tmp[i] = nums[i];
        }

        int count = 0;
        int i = left_begin, j = right_begin;   //i记录左区间, j记录右区间
        for(int index = left_begin; index <= right_end; ++index)
        {
            if(i == left_end + 1){
                nums[index] = tmp[j++];
            }
            else if(j == right_end + 1){
                nums[index] = tmp[i++];
            }
            else if(tmp[i] <= tmp[j]){   //这里必须挂等号, 不然会将相等的情况也算做逆序对
                nums[index] = tmp[i++];
            }
            else{   //tmp[i] > tmp[j], 此情况下,应当统计逆序对的个数了
                nums[index] = tmp[j++];
                count += (left_end - i + 1);
            }
        }
        return count;
    }

    //注意: 这里计算逆序对是对不同区间之间计算的, 而不是在同一区间内计算, 因此我们使用归并排序, 递归到只剩一个元素, 然后在合并的过程中才开始计算的
    int mergeSort(vector<int>& nums, int left, int right, vector<int>& tmp){
        if(left == right){
            return 0;
        }

        int mid = left + (right - left) / 2;
        int left_count = mergeSort(nums, left, mid, tmp);   //计算左子区间 之间 的逆序对个数
        int right_count = mergeSort(nums, mid + 1, right, tmp); //计算右子区间 之间 的逆序对的个数
        
        //如果左区间的最大值 <= 右区间的最小值, 则对于这两个区间而言, 相互不存在逆序对
        if(nums[mid] <= nums[mid + 1]){
            return left_count + right_count;
        }
        int curCrossInterval_count = mergeAndCount(nums, left, mid, mid + 1, right, tmp);
        return left_count + right_count + curCrossInterval_count;
    }

    int reversePairs(vector<int>& nums) {
        if(nums.size() <= 1)    return 0;
        vector<int> tmp(nums);
        return mergeSort(nums, 0, nums.size() - 1, tmp);
    }
};