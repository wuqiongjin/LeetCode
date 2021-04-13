struct TreeNode* _buildTree(int* inorder, int inLeft, int inRight, int* postorder, int postLeft, int postRight)
{
    //递归终止条件
    if(inLeft > inRight || postLeft > postRight)
        return NULL;
    
    int pivot = postorder[postRight];
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = pivot;
    //root->left = root->right = NULL;
    
    //先找pindex（根节点在中序遍历中的下标）
    int pindex = 0;
    while(inorder[pindex] != pivot)
    {
        ++pindex;
    }

    //递归构建左右子树
    root->left = _buildTree(inorder, inLeft, pindex - 1,
                            postorder, postLeft, postRight + pindex - inRight - 1);
    root->right = _buildTree(inorder, pindex + 1, inRight,
                            postorder, postRight + pindex - inRight, postRight - 1);
    return root;
}

struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize)
{
    if(inorderSize != postorderSize)
        return NULL;
    return _buildTree(inorder, 0, inorderSize -1, postorder, 0, postorderSize - 1);
}