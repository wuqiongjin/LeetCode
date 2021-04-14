//主要思路：
//通过递归遍历A，去对每一个结点进行判断（isincluded函数进行比较）是否包含B子树
//然后实现isincluded时也要用递归去判断比较

//判断是否包含的函数
bool isincluded(struct TreeNode* A, struct TreeNode* B)
{    
    //只要B位空，就是true
    if(B == NULL)
        return true;

    //A为空，B不为空，false
    if(A == NULL)
        return false;

    //该节点值不同，false
    if(A->val != B->val)
        return false;
    //结构相同且值相同，继续判断
    return isincluded(A->left, B->left)
        && isincluded(A->right, B->right);
}

bool isSubStructure(struct TreeNode* A, struct TreeNode* B)
{
    //如果A树为空，代表A已经遍历完了还没有找到包含B的起始节点，所以false
    //B为空，代表B为空树
    if(A == NULL || B == NULL)
        return false;
    //遍历整个A树的结点去找和B树相同的起始节点，如果找到相同的起始节点，去调用判断包含的函数isincluded
    return isincluded(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);

}