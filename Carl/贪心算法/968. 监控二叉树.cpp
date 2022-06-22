/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int res = 0;
    //从叶子结点入手, "每个叶子结点都不是监控结点"!, 隔两个节点放一个摄像头，直至到二叉树头结点。
    //为了能从叶子结点自底向上遍历, 我们需要使用后序遍历

    //我们可以使用状态表示来控制"每隔'两'层"放一个摄像头
    //一个结点有3种状态:
    //0: 没有被覆盖
    //1: 是监控结点
    //2: 被覆盖了
    int traverse(TreeNode* root)
    {
        //情况0: 空结点必须设置为被覆盖状态(2), 不能设置为其它的
        //(0: 意味着它的父结点必须要是监控结点)
        //(1: 意味着它的父结点是被覆盖的, 但并没有)
        if(root == nullptr) return 2;

        int left = traverse(root->left);
        int right = traverse(root->right);

        //情况1: 左右孩子被覆盖了
        //左孩子和右孩子都被覆盖了, 那么当前结点不需要设置为监控结点(目前不需要), 
        //所以当前结点的状态是没有被覆盖 0
        if(left == 2 && right == 2){
            return 0;
        }

        //情况2: 左右孩子有一个处于'未被覆盖'状态
        //左孩子和右孩子有一个没有被覆盖, 那么当前结点必须是监控结点 1
        //这里也包含了(左右孩子有一个为监控结点、有一个没被覆盖 的状态, 此时依然需要设置当前结点是监控结点)
        if(left == 0 || right == 0){
            ++res;
            return 1;
        }

        //情况3: 左右孩子有一个是'监控结点'
        //左孩子和右孩子有一个是监控结点, 那么当前结点就是被覆盖的状态
        if(left == 1 || right == 1){
            return 2;
        }

        //不可能走到这里的
        return -1;
    }

    int minCameraCover(TreeNode* root) 
    {
        res = 0;
        //最终需要额外判断根结点是否是处于未被覆盖状态, 如果是的话需要额外将root设置为监控结点
        if(traverse(root) == 0){
            ++res;
        }
        return res;
    }
};