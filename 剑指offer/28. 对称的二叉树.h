bool _isSymmetric(struct TreeNode* Left, struct TreeNode* Right)
{
    if(Left == NULL && Right == NULL)
        return true;
    if(Left == NULL || Right == NULL)
        return false;
    if(Left->val != Right->val)
        return false;

    return _isSymmetric(Left->left, Right->right)
        && _isSymmetric(Left->right, Right->left);
}

bool isSymmetric(struct TreeNode* root)
{
    if(root == NULL)
        return true;
    //比较的对象是根结点的左子树和右子树是否对称，所以需要另创建一个函数用来传left和right(2个参数对象需要比较)
    return _isSymmetric(root->left, root->right);
}