#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

//1. 注意find的范围，[first, last) !!!!!!!!
//2. 本题的方法是：先逆置整体，再逆置部分。这样就完成了每个单词的逆置
//3. getline获取一行


void reverse_string(string& s)
{
    reverse(s.begin(), s.end());
    int begin = 0, end = 0;
    
    while(1)
    {
        end = s.find(' ', begin);
        if(end != string::npos)
            reverse(s.begin() + begin, s.begin() + end);
        else
        {
            reverse(s.begin() + begin, s.end());
            break;
        }
        begin = end + 1;
    }
    cout << s;
}

int main()
{
    string s;
    getline(cin, s);
    reverse_string(s);
    return 0;
}