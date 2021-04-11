struct TreeNode* _buildTree(int* preorder, int preLeft, int preRight, int* inorder, int inLeft, int inRight)
{
	//递归终止条件，即区间不存在时停止递归
    if(preLeft > preRight || inLeft > inRight)
        return NULL;
    //因为没有重复元素，因此可以通过pivot去找根节点在中序遍历中的下标
    int pivot = preorder[preLeft];
    
	struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = pivot;
    //root->left = root->right = NULL;[没必要]
	
    //去中序遍历中找根节点的下标
	int pindex = 0;
    while(inorder[pindex] != pivot)// 严格上说还要做数组下标是否越界的判断 pivotIndex < inRight
    {
        ++pindex;
    }
	//根节点的左子树[左子树区间]（给出左子树所在区间去继续递归，最终会返回根节点左子树的根节点）
    root->left = _buildTree(preorder, preLeft + 1, preLeft + pindex - inLeft, 
    inorder, inLeft, pindex - 1);
	//根节点的右子树[右子树区间]
    root->right = _buildTree(preorder, preLeft + pindex - inLeft + 1, preRight,
    inorder, pindex + 1, inRight);
	
    //每个子树建立完成后，返回该子树的root结点
    return root;
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize)
{
    if(preorderSize != inorderSize)
        return NULL;
		
    return _buildTree(preorder, 0, preorderSize - 1, inorder, 0, inorderSize - 1);
}
