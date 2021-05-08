class Solution {
public:
    ListNode* insertionSortList(ListNode* head) 
    {
        if(head == nullptr || head->next == nullptr)
            return head;
        //使用带哨兵位的头结点
        ListNode* DummyHead = new ListNode;
        DummyHead->next = head;
        //定义2个指针cur和next用来遍历链表，将未排序的结点依次插入
        ListNode* cur = head->next;
        //※这里必须要将已排序的那个节点的下一个位置置成nullptr，否则容易使链表成环
        head->next = nullptr;
        
        //            4          2  ->  1  ->  3
        //sortprev sortcur      cur    next
        while(cur)
        {
            //必须要定义next用来存储cur的下一个，不然cur会找不到下一个结点的
            ListNode* next = cur->next;
            
            ListNode* sortprev = DummyHead;
            ListNode* sortcur = sortprev->next;
            //普通插入+头插
            while(sortcur)
            {
                //普通插入+头插
                if(sortcur->val >= cur->val)
                {
                    cur->next = sortcur;
                    sortprev->next = cur;
                    //插入后直接break
                    break;
                }
                else
                {
                    sortprev = sortcur;
                    sortcur = sortcur->next;
                }                
            }
            //尾插 如果sortcur是因为到空结束的，那么证明该节点应该尾插到最后
            if(sortcur == nullptr)
            {
                cur->next = sortcur;
                sortprev->next = cur;
            }
            cur = next;
        }
        return DummyHead->next;
    }
};