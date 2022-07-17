class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<int> ufs(isConnected.size(), -1);
        auto findRoot = [&](int x)
        {
            int root = x;
            while(ufs[root] >= 0)
                root = ufs[root];
            return root;
        };

        for(int i = 0; i < isConnected.size(); ++i)
        {
            for(int j = 0; j < isConnected.size(); ++j)
            {
                if(isConnected[i][j] == 1){
                    int root1 = findRoot(i);
                    int root2 = findRoot(j);
                    if(root1 == root2)  //!!! 同一个根的 不能继续Union合并!!!
                        continue;
                    ufs[root1] += ufs[root2];
                    ufs[root2] = root1;
                }
            }
        }

        int res = 0;
        for(int i = 0; i < ufs.size(); ++i)
        {
            if(ufs[i] < 0){
                ++res;  //统计 有多少棵树 (并查集是森林)
            }
        }
        return res;
    }
};