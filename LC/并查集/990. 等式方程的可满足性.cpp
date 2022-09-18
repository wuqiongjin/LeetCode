class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        // 1. 将所有"=="两端的字符合并到一个集合中
        // 2. 检测"!=" 两端的字符是否在同一个结合中，如果在不满足，如果不在满足
        vector<int> ufs(26, -1);    //这题因为是字母, 所以直接开辟26个大小的空间
        auto findRoot = [&](int root)
        {
            while(ufs[root] >= 0)
            {
                root = ufs[root];
            }
            return root;
        };

        for(int i = 0; i < equations.size(); ++i)
        {
            if(equations[i][1] == '='){
                int root1 = findRoot(equations[i][0] - 'a');
                int root2 = findRoot(equations[i][3] - 'a');
                if(root1 == root2) continue;
                ufs[root1] += ufs[root2];
                ufs[root2] = root1;
            }
        }

        for(int i = 0; i < equations.size(); ++i)
        {
            if(equations[i][1] == '!'){
                int root1 = findRoot(equations[i][0] - 'a');
                int root2 = findRoot(equations[i][3] - 'a');
                if(root1 == root2){
                    return false;
                }
            }
        }

        return true;
    }
};