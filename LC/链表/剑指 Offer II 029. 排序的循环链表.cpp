/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        if(head == nullptr){    //特殊处理一下空结点
            head = new Node(insertVal);
            head->next = head;
            return head;
        }

        Node* TrueHead = head;
        Node* cur = head->next;
        pair<int,Node*> minNode = {head->val, head};    //找到最小的结点(将其作为TrueHead结点)
        while(cur != head)
        {
            if(cur->val < minNode.first){
                minNode.first = cur->val;
                minNode.second = cur;
            }
            cur = cur->next;
        }
        TrueHead = minNode.second;

        cur = TrueHead;
        Node* next = cur->next;
        while(next != TrueHead)
        {
            if(cur->val <= insertVal && insertVal <= next->val){
                Node* newNode = new Node(insertVal);
                newNode->next = next;
                cur->next = newNode;
                return head;    //在正常的排序链表中
            }
            cur = next;
            next = next->next;
        }
        
        //在排序链表的两端(最小值/最大值)
        //说明该元素比最大的元素大 / 比最小的元素小
        Node* newNode = new Node(insertVal);
        newNode->next = next;
        cur->next = newNode;
        return head;
    }
};