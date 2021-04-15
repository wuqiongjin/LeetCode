struct TreeNode* mirrorTree(struct TreeNode* root)
{
    if(root == NULL)
        return NULL;
    //遍历树的所有节点
    //对树的每个结点的左右子树进行交换（翻转）
    struct TreeNode* tmp = root->left;
    root->left = mirrorTree(root->right);
    root->right = mirrorTree(tmp);
    return root;
}