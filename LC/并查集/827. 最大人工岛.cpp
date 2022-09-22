class Solution {
public:
    //将二维下标舒展成一维下标(将二维数组的i和j转化为一维数组的数字)
    inline int flat(int row, int col, int n){
        return row * n + col;
    }

    //判断row和col是否合法
    inline bool isValid(int row, int col, int n){
        return row < n && row >= 0 && col < n && col >= 0;
    }

    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> ufs(n * n, -1); //由于本题是二维数组, 而我们这里使用的是一维ufs, 所以在映射下标时, 需要将二维下标转化为一维的, 此时我们需要flat函数
        auto findRoot = [&](int root){
            while(ufs[root] >= 0)
            {
                root = ufs[root];
            }
            return root;
        };
        auto Union = [&](int x1, int x2){
            int root1 = findRoot(x1);
            int root2 = findRoot(x2);
            if(root1 != root2){
                ufs[root1] += ufs[root2];
                ufs[root2] = root1;
            }
        };
        
        //按照"上"、"右"、"下"、"左" 顺时针方向
        static const vector<pair<int,int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        //第一次遍历grid, 将所有格子为1的元素相邻元素合并
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                //只有当前格子为1, 才去查找并合并其四周的1的格子
                if(grid[i][j] == 1){
                    for(int k = 0; k < 4; ++k)
                    {
                        int x = directions[k].first, y = directions[k].second;
                        if(isValid(i + x, j + y, n) && grid[i + x][j + y] == 1){
                            int root1 = findRoot(flat(i, j , n));
                            int root2 = findRoot(flat(i + x, j + y, n));
                            Union(root1, root2);    //合并相邻的1的元素格
                        }
                    }
                }
            }
        }

        //第二次遍历grid, 找到元素为0的格子, 然后寻找其四周, 判断是否能够连接到最大的集合
        int res = 0;
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                //我们还没结算过结果。由于可能存在没有0元素的情况, 所以我们需要计算每个1的元素岛屿的最大面积
                if(grid[i][j] == 1){
                    res = max(res, abs(ufs[findRoot(flat(i, j, n))]));  //注意, 这里是ufs[下标],下标=findRoot
                }

                int cntBlock = 1;
                if(grid[i][j] == 0){
                    unordered_set<int> usi;
                    for(int k = 0; k < 4; ++k)
                    {
                        int x = directions[k].first, y = directions[k].second;
                        if(isValid(i + x, j + y, n) && grid[i + x][j + y] == 1 \
                        && usi.count(findRoot(flat(i + x, j + y, n))) == 0){
                            int root = findRoot(flat(i + x, j + y, n));
                            usi.insert(root);
                            cntBlock += abs(ufs[root]);
                        }
                    }
                }
                res = max(res, cntBlock);
            }
        }

        return res;
    }
};