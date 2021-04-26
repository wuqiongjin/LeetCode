//下面的方法都进行哨兵位头结点的申请

//思路1：
//经过while循环体，那么prev的连接方式需要连接到next上（链接到next上代表删除了prev到next区间的结点）；否则连接到cur上（没有进行任何删除）

class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead) 
    {
        if(pHead == nullptr || pHead->next == nullptr)
            return pHead;
        ListNode* DummyHead = new ListNode(0);
        DummyHead->next = pHead;
        ListNode* prev = DummyHead;
        ListNode* cur = pHead;
        ListNode* next = cur->next;
        //删除重复结点
        while(next)
        {
            //定义布尔值变量del判断是否经过while循环，如果经过，那么prev的next是指向next的。如果没经过，那么prev的next指向cur。
            bool del = false;
            while(cur->val == next->val)
            {
                cur = next;
                next = next->next;
                del = true;
                if(next == nullptr)
                    break;
            }
            if(del)
            {
                prev->next = next;
                cur = prev->next;
                if(next)
                    next = next->next;
            }
            else
            {
                prev = cur;
                cur = next;
                if(next)
                    next = next->next;
            }
        }
        return DummyHead->next;
    }
};

//思路2：
//删除重复结点
//先确定删除区间，再进行删除操作

class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead) 
    {
        if(pHead == nullptr || pHead->next == nullptr)
            return pHead;
        ListNode* DummyHead = new ListNode(0);
        DummyHead->next = pHead;
        ListNode* prev = DummyHead;
        ListNode* cur = pHead;
        ListNode* next = cur->next;
        //删除重复结点
        while(next)
        {
            //如果不是要删除的结点
            if(cur->val != next->val)
            {
                prev = cur;
                cur = next;
                next = next->next;
            }
            else//遇到要删除的结点
            {
                //先确定要删除的区间，确定区间的时候只移动next指针（也就是只移动有边界）
                while(next && cur->val == next->val)
                {
                    next = next->next;
                }
                ListNode* del = nullptr;
                //然后移动左边界进行删除
                while(cur != next)
                {
                    del = cur;
                    cur = cur->next;
                    delete[] del;
                }
                //连接左右2部分
                prev->next = cur;
                if(next)
                    next = next->next;
            }
        }
        return DummyHead->next;
    }
};