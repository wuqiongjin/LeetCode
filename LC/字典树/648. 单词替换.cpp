class Solution {
public:
    //这里讲一下string_view这个C++17的东西的使用注意事项
    //string_view不为自己的对象开辟真正的空间, 它类似于一个指针, 因此你要小心让它指向一个局部变量string
    //
    //Split函数: 根据切割符将字符串s切割, 将结果放入vector<string>数组
    vector<string_view> Split(string& s, char ch){
        vector<string_view> res;
        string_view tmp(s);

        int start = 0, end = 0;
        while(end < s.size())
        {
            while(end < s.size() && s[end] == ch){
                ++end;
            }
            start = end;
            
            while(end < s.size() && s[end] != ch){
                ++end;
            }

            if(start < s.size()){
                res.emplace_back(tmp.substr(start, end - start));   //substr得再熟悉熟悉...
            }
        }
        return res;
    }

    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string_view> us;
        for(auto& e : dictionary)
            us.emplace(e);

        vector<string_view> words = Split(sentence, ' ');
        for(auto& word : words) //这里的auto& 很关键!!! 因为我们要对word的内容进行修改, 因此我们必须要使用引用
        {
            for(int j = 0; j < word.size(); ++j)
            {
                if(us.count(word.substr(0, j + 1))){
                    word = word.substr(0, j + 1);
                    break;
                }
            }
        }

        string res;
        for(auto e : words)
        {
            res += e;
            res += " ";
        }
        res.resize(res.size() - 1);

        return res;
    }
};



//字典树
//将dictionary的单词放入字典树中, 然后判断sentence里面的每个word是否能在字典树中找到其前缀
//这里需要对startsWith方法进行一些灵活修改, 结束条件return true时, 可以是前缀走到了结尾(flag==true)
class Trie{
private:
    //推荐别用数组了, 我不清楚这个50000数字哪里来的...
    int trie[50050][26] = { 0 };
    bool flag[50050] = { false };
    int index = 0;
public:
    void insert(string& s){
        int p = 0;
        for(auto x : s){
            int u = x - 'a';
            if(trie[p][u] == 0) trie[p][u] = ++index;
            p = trie[p][u];
        }
        flag[p] = true;
    }

    bool startsWith(string& s, int& end){
        int p = 0;
        int len = 0;
        for(auto x : s){
            int u = x - 'a';
            if(trie[p][u] == 0) return false;

            p = trie[p][u];
            
            if(flag[p] == true){
                end = len;
                return true;
            }
            ++len;
        }
        end = len;
        return true;
    }

};

//将sentence切割成单词, 放入words中
vector<string> Split(string& s, char ch){
    vector<string> res;
    int start = 0, end = 0;
    while(end < s.size())
    {
        while(end < s.size() && s[end] == ch){
            ++end;
        }
        start = end;

        while(end < s.size() && s[end] != ch){
            ++end;
        }

        if(start < s.size()){
            res.emplace_back(s.substr(start, end - start));
        }
    }
    return res;
}

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie* tr = new Trie();  //尽量使用堆空间, 栈空间可能不够用
        for(auto& e : dictionary){
            tr->insert(e);
        }
        
        vector<string> words = Split(sentence, ' ');
        string res;
        for(auto& e : words)
        {
            int end = -1;
            if(tr->startsWith(e, end)){	//灵活的运用end输出型参数获取前缀在sentence的word的结束位置
                res += e.substr(0, end + 1);
            }
            else{
                res += e;
            }
            res += " ";
        }
        res.resize(res.size() - 1);
        return res;
    }
};