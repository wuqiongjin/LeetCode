//1. 暴力枚举
class MagicDictionary {
public:
    MagicDictionary() {
    }
    
    void buildDict(vector<string> dictionary) {
        for(auto& e : dictionary)
            dict.emplace_back(e);
    }
    
    bool search(string searchWord) {
        for(int i = 0; i < dict.size(); ++i)
        {
            if(dict[i].size() != searchWord.size()){	//注意, 必须是替换一个字符(所以排除多一个字符或少一个字符的情况
                continue;
            }

            int diff = 0;
            for(int j = 0; j < dict[i].size(); ++j)
            {
                if(dict[i][j] != searchWord[j]){
                    ++diff;
                }
            }
            if(diff == 1){
                return true;
            }
        }
        return false;
    }
    vector<string> dict;
};



//DFS + 字典树
class Trie{
public:
    Trie* tr[26] = { nullptr };
    bool flag = false;
};

class MagicDictionary {
public:
    MagicDictionary() {
        root = new Trie();
    }
    
    void buildDict(vector<string> dictionary) {
        for(auto& word : dictionary){
            Trie* cur = root;   //注意, 这里要放到循环里面, 每次换一个单词后, 我们都要从根开始重新插入character
            for(auto& x : word){
                int u = x - 'a';
                if(cur->tr[u] == nullptr)   cur->tr[u] = new Trie();
                cur = cur->tr[u];
            }
            cur->flag = true;
        }
    }
    
    bool search(string searchWord) {		//这里需要捕捉&到searchWord
        function<bool(Trie*,int,bool)> dfs = [&](Trie* root, int pos, bool isModified){
            if(pos == searchWord.size()){
                // if(root->flag == true && isModified == true){
                //     return true;
                // }
                // return false;
                return root->flag && isModified;
            }

            int u = searchWord[pos] - 'a';
            if(root->tr[u] != nullptr){
                if(dfs(root->tr[u], pos + 1, isModified)){
                    return true;
                }
            }

            if(isModified == false){	//只有没被替换过的, 才有资格进入这个if
                isModified = true;
                for(int i = 0; i < 26; ++i)
                {
                    if(i != u && root->tr[i] != nullptr){   //注意!!!这里 i != u 很关键, 如果不加这个的话会死循环
                        if(dfs(root->tr[i], pos + 1, isModified)){
                            return true;
                        }
                    }
                }
            }

            return false;
        };

        return dfs(root, 0, false);
    }

    Trie* root = nullptr;
};