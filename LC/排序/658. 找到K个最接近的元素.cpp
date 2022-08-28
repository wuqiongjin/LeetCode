//1. 排序
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // auto cmp = [&](int a, int b)
        // {
        //     if(abs(a - x) < abs(b - x)){
        //         return true;
        //     }
        //     else if(abs(a - x) == abs(b - x)){
        //         return a < b;
        //     }
        //     else{
        //         return false;
        //     }
        // };
        auto cmp = [&](int a, int b)
        {
            return abs(a - x) < abs(b - x) || (abs(a - x) == abs(b - x) && a < b);
        };
        sort(arr.begin(), arr.end(), cmp);
        sort(arr.begin(), arr.begin() + k);
        return vector<int>(arr.begin(), arr.begin() + k);
    }
};


//2. 二分查找(lower_bound) + 双指针向左右两边扩展
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int right = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        int left = right - 1;   //左开右开 (右开是因为最后返回结果时, 我们使用的是vector的构造函数, 这个构造函数是左闭右开的, 而我们这里的left本身就是左开的, 所以最终返回结果的时候, 我们需要让left + 1, 而right不用处理)
        while(k--)
        {
            if(left < 0){   //判断当left到了左边界时, 此时只能移动right
                ++right;
            }
            else if(right >= arr.size()){   //当right到了右边界时, 此时只能移动left了
                --left;
            }
            else if(x - arr[left] <= arr[right] - x){   //比较left和right谁的值离x更近
                --left;
            }
            else{// x - arr[left] >= arr[right] - x
                ++right;
            }
        }
        return vector<int>(arr.begin() + left + 1, arr.begin() + right);
    }
};