/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/
//O(N^2)
class Solution {
public:
    Node* flatten(Node* head) {
        Node* DummyHead = new Node();
        DummyHead->next = head;
        Node* cur = head;
        while(cur)
        {
            Node* next = cur->next;
            if(cur->child){
                Node* child = flatten(cur->child);
                cur->next = child;
                child->prev = cur;
                while(child->next)
                {
                    child = child->next;
                }
                child->next = next;
                if(next)    //next可能为nullptr
                    next->prev = child;
                
                cur->child = nullptr;   //题里要求child必须置为nullptr
            }
            cur = next;
        }
        return DummyHead->next;
    }
};



//借助另一个函数, 省去了while循环, 效率为O(N)
//这两个函数的返回值意义不同, 所以必须使用2个函数
class Solution {
public:
    Node* dfs(Node* head){
        Node* cur = head;
        Node* last = cur;
        while(cur)
        {
            Node* next = cur->next;
            if(cur->child){
                Node* childLast = dfs(cur->child);
                cur->next = cur->child;
                cur->child->prev = cur;
                
                if(childLast)
                    childLast->next = next;
                if(next)
                    next->prev = childLast;
                
                cur->child = nullptr;
                
                last = childLast;//这里必须 = childLast, 不然如果下层恰好为本层的最后一个元素的孩子, 那么你返回给上一层的就应该是下一层结点的最后一个孩子而不是本层的最后一个元素
            }
            else{
                last = cur;
            }
            cur = next;
        }
        return last;
    }

    Node* flatten(Node* head) {
        dfs(head);
        return head;
    }
};