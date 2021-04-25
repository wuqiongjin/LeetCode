void NodecopyAfter(Node* cur)
{
    Node* p = new Node(cur->val);
    p->next = cur->next;
    cur->next = p;
}

class Solution {
public:
    Node* copyRandomList(Node* head) 
    {
        if(head == nullptr)
            return nullptr;
        Node* cur = head;
		//先进行拼接和值val的复制
        while(cur)
        {
            NodecopyAfter(cur);
            cur = cur->next->next;
        }
		//再进行random的复制
        cur = head;
        while(cur)
        {
            //!!!注意：这里要判断cur->random是否指向空指针，否则会出现空指针解引用问题！
            if(cur->random)
                cur->next->random = cur->random->next;
            else
                cur->next->random = nullptr;
            cur = cur->next->next;
        }
		//进行拆解
        cur = head;
        Node* newHead = cur->next;
        while(cur)
        {
            Node* next = cur->next;
            cur->next = next->next;
            //注意这里空指针的隐患！！！ cur->next->next可能会出现空指针的解引用
            if(next->next)
                next->next = cur->next->next;
            cur = cur->next;
        }
        return newHead;
    }
};