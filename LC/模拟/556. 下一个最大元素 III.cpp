class Solution {
public:
    //思路:
    //倒序遍历,从当前位置'往后'找到 '大于当前的位置的值中的最小的值' 所在的位置
    //设这个变量为nearMaxValue, 给其初始化为s.size(), 如果循环了一遍后, 其值不是s.size()了,
    //那么, 交互当前位置和那个当于当前值的最小值的位置的值; 
    //然后对当前位置往后的所有位置, 全部进行排序, 排升序
    //如果排序完的值>INT_MAX, return -1;
    int nextGreaterElement(int n) {
        string s = to_string(n);    //转化为字符串方便操作
        for(int i = s.size() - 2; i >= 0; --i)
        {
            int nearMaxValue = s.size();
            for(int j = i + 1; j < s.size(); ++j)
            {
                if(s[j] > s[i]){
                    if(nearMaxValue == s.size()){
                        nearMaxValue = j;
                    }
                    else{
                        nearMaxValue = s[nearMaxValue] > s[j] ? j : nearMaxValue; 
                    }
                }
            }
            if(nearMaxValue != s.size()){
                swap(s[i], s[nearMaxValue]);
                sort(s.begin() + i + 1, s.end());
                if(stol(s) > INT_MAX){
                    break;
                }
                return stoi(s);
            }
        }
        return -1;
    }
};