// class Solution {
// public:
//     void skipSeparator(string& path, int& i, int len)
//     {
//         while(i < len && path[i] != '/')
//             ++i;
//         while(i < len && path[i] == '/')
//         {
//             ++i;
//         }   
//         --i;
//     }

//     bool isDir(string& path, int i, int len)
//     {
//         if(isalpha(path[i]))
//             return true;
//         int j = i;
//         bool hasAl = false;
//         while(j < len && path[j] != '/')
//         {
//             if(isalpha(path[j]))
//                 hasAl = true;
//             ++j;
//         }
//         if((j != i + 2 && j != i + 1) || hasAl)
//             return true;
//         return false;
//     }

//     void pushDir(string& path, stack<char>& st, int& i, int len)
//     {
//         while(i < len && path[i] != '/')
//         {
//             st.push(path[i]);
//             ++i;
//         }
//         --i;
//     }

//     //目录 + '/' 构成一个整体
//     string simplifyPath(string path) 
//     {
//         stack<char> st;
//         int len = path.size();
//         for(int i = 0; i < len; ++i)
//         {

//             if(path[i] == '/') // 字母 或. 或/ 后面 + '/'
//             {
//                 while(i < len && path[i] == '/')
//                 {
//                     ++i;
//                 }
//                 --i;
//                 st.push('/');
//             }
//             else if(isDir(path, i, len)) //目录直接push
//             {
//                 pushDir(path, st, i, len);
//             }
//             else if(path[i] == '.')
//             {
//                 //单个'.'
//                 if(i >= len || path[i + 1] != '.')
//                 {
//                     //跳过'.'后面的'/'
//                     skipSeparator(path, i, len);
//                     continue;
//                 }//2个'.'
//                 else if(path[i + 1] == '.' && (i + 2 >= len || (i + 2 < len && path[i + 2] != '.')))
//                 {
//                     if(st.size() > 1) //根目录再往上无法pop
//                     {
//                         //pop掉'.'前面的'/'
//                         if(st.size() > 1 && st.top() == '/')
//                             st.pop();   

//                         while(st.size() > 1 && isalpha(st.top()) || st.top() == '.')    //删除目录
//                             st.pop();
                        
//                         // //把要pop掉的上一级目录前面的'/'分隔符给pop掉 [别删根目录]
//                         // if(st.size() > 1 && st.top() == '/')
//                         // {
//                         //     st.pop();
//                         // }
//                     }
//                     //跳过..后面的'/'
//                     skipSeparator(path, i, len);
//                 }
//                 // else//大于2个'.'
//                 // {
//                 //     while(i < len && path[i] == '.')
//                 //     {
//                 //         st.push(path[i]);
//                 //         ++i;
//                 //     }
//                 //     --i;
//                 // }
//             }
//         }
//         //最后一个/的去除
//         if(st.size() > 1 && st.top() == '/') 
//         {
//             st.pop();
//         }
        
//         string ans;
//         while(!st.empty())
//         {
//             ans += st.top();
//             st.pop();
//         }
//         reverse(ans.begin(), ans.end());
//         return ans;
//     }
// };




class Solution {
public:
    //分割字符串split
    vector<string> split(const string& s,char delimiter)
    {
        vector<string> tokens;
        string token;
        istringstream tokenStream(s);
        while(getline(tokenStream, token, delimiter))
        {
                                            //根目录无法继续pop
            if(token== "" || token=="." || (token==".." && tokens.size() == 0))
                continue;
            else if(token==".." && tokens.size() > 0)
                tokens.pop_back();
            else
                tokens.push_back(token);
        }
        return tokens;
    }
    string simplifyPath(string path) 
    {
        string str = "";
        //用一个vector<string>数组去接收split的返回值
        vector<string> tmp = split(path, '/');  //将path按照'/'去分割，每个字符串存储到vector<string>中
        for(auto s : tmp)
        {
            str += "/";
            str += s;
        }
        return str == "" ? "/" : str;
    }
};