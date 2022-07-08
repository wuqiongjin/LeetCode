/***                        Trie前缀树                          ***/
//定长数组
class Trie {
public:
    int trie[60000][26] = { 0 };  //60000 = 2000 * 30  (2000是题里面说的单词的最大长度, 30是26四舍五入取得, 这个无所谓)
    bool flag[60000] = { 0 };   //表示位置是否 曾作为一个单词的结尾
    int index = 0;

    Trie() {
    }
    
    void insert(string word) {
        int p = 0;  //p变量用于更改层数(想象它是一颗树,通过p变量找到下一层)
        for(auto x : word){
            int u = x - 'a';
            if(trie[p][u] == 0) trie[p][u] = ++index;
            p = trie[p][u]; //更新层数
        }
        flag[p] = true;
    }
    
    bool search(string word) {
        int p = 0;
        for(auto x : word){
            int u = x - 'a';
            if(trie[p][u] == 0) return false;
            p = trie[p][u];
        }
        return flag[p];
    }
    
    bool startsWith(string prefix) {
        int p = 0;
        for(auto x : prefix){
            int u = x - 'a';
            if(trie[p][u] == 0) return false;
            p = trie[p][u];
        }
        return true;
    }
};


//TrieNode
class Trie {
private:
    Trie* tr[26] = { nullptr };
    bool flag = false;
public:
    Trie() {
    }

    ~Trie(){
        for(int i = 0; i < 26; ++i){
            if(tr[i] != nullptr){
                delete tr[i];
            }
        }
    }
    
    void insert(string word) {
        Trie* root = this;
        for(auto x : word){
            int u = x - 'a';
            if(root->tr[u] == nullptr)  root->tr[u] = new Trie();//tr[u]是个指针数组, 我们给这个指针数组的u下标处开辟空间, 然后让root指针等于这个指针数组u下标处的指针(Trie类型的), 然后下一层循环, 然后再访问这个Trie指针的指针数组的u下标处... 以此来达到一种树状连接
            root = root->tr[u]; //将root指针转移到自己新开辟的Trie对象上
        }
        root->flag = true;
    }
    
    bool search(string word) {
        Trie* root = this;
        for(auto x : word){
            int u = x - 'a';
            if(root->tr[u] == nullptr)  return false;
            root = root->tr[u];
        }
        return root->flag;
    }
    
    bool startsWith(string prefix) {
        Trie* root = this;
        for(auto x : prefix){
            int u = x - 'a';
            if(root->tr[u] == nullptr)  return false;
            root = root->tr[u];
        }
        return true;
    }
};