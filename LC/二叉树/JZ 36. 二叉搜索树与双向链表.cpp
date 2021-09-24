/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    //prev必须要使用引用 或 二级指针。
    //因为在递归的时候，我们这次修改完，下次不管回到哪里都需要修改后的值
    void _treeToDoublyList(Node* root, Node*& prev)
    {
        if(root == NULL)
            return;
        
        _treeToDoublyList(root->left, prev);

        //核心思路：让root->left链接到prev，root->right链接到root的下一个位置
        root->left = prev;

        //※关键※ 这句代码的意义要到下一次递归回来时才能体现
        //因为我们无法知道root的下一个结点是谁
        //但是递归回到下一次时，root前往下一个位置，prev到了root的位置。
        //此时这句代码可以翻译为：root->right = NEXT;   (NEXT为root的下一个位置)
        if(prev)
            prev->right = root; 
        prev = root;    //更新prev的位置
        _treeToDoublyList(root->right, prev);
    }

    //必须创建一个子函数，因为要使用2个指针来进行控制 cur和prev 2个位置
    Node* treeToDoublyList(Node* root) 
    {
        //空树直接返回
        if(root == NULL)
            return root;

        Node* prev = NULL;
        _treeToDoublyList(root, prev);

        Node *head = root, *tail = root;
        while(head->left)
            head = head->left;
        while(tail->right)
            tail = tail->right;
        head->left = tail;
        tail->right = head;
        
        return head;
    }
};