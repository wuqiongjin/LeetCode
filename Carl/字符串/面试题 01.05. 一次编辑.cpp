class Solution {
public:
    bool oneEditAway(string first, string second) 
    {
        int len_first = first.size(), len_second = second.size();
        if(abs(len_first - len_second) > 1) return false;   //长度差超过1肯定不正确

        if(len_second - len_first == 1){
            return oneEditAway(second, first); //把second > first的情况转换为first > second
        }

        //只判断first > second 和first == second(修改)的情况
        int change = 0;//记录编辑次数
        for(int i = 0, j = 0; i < len_first && j < len_second; )
        {
            if(first[i] == second[j]){
                ++i;
                ++j;
            }
            else{
                if(len_first == len_second){    //修改字符
                    ++change;
                    ++i;
                    ++j;
                }
                else{   //第二个字符串 少了一个字符
                    ++change;
                    ++i;
                }
            }
        }

        if(change > 1)  return false;
        return true;
    }
};