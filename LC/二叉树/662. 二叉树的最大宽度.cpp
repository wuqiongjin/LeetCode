//1.bfs, 层序遍历
typedef unsigned long long ull;
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        vector<pair<TreeNode*,ull>> vp;
        vp.emplace_back(root,1);
        ull res = 1;
        while(!vp.empty())
        {
            vector<pair<TreeNode*,ull>> tmp;
            for(auto& [f, s] : vp)
            {
                if(f->left){
                    tmp.emplace_back(f->left, 2 * s);
                }

                if(f->right){
                    tmp.emplace_back(f->right, 2 * s + 1);
                }
            }
            res = max(res, vp.back().second - vp.front().second + 1);
            vp = move(tmp);
        }
        return res;
    }
};

//2. dfs, 利用哈希表存储"每层的最小下标index"
using ULL = unsigned long long;
class Solution {
public:
    void dfs(TreeNode* root, int depth, ULL index){
        if(root == nullptr) return;
        if(umii.count(depth) == 0){
            umii[depth] = index;
        }
        res = max(res, index - umii[depth] + 1);
        dfs(root->left, depth + 1, index * 2);
        dfs(root->right, depth + 1, index * 2 + 1);
    }

    int widthOfBinaryTree(TreeNode* root) {
        dfs(root, 1, 0);
        return res;
    }
    unordered_map<int,ULL> umii;    //key:深度 value:当前层的最小下标
    ULL res = 0;
};