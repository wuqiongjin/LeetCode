/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    //本题的本质：链表中点 + 逆置链表 + 合并链表
    ListNode* reverseList(ListNode* head)
    {
        ListNode* newHead = nullptr;
        ListNode* cur = head;
        while(cur)
        {
            ListNode* next = cur->next;
            cur->next = newHead;
            newHead = cur;
            cur = next;
        }
        return newHead;
    }

    void reorderList(ListNode* head) 
    {
        if(head->next == nullptr)
            return;
        ListNode* first = head;
        ListNode* last = head;
        ListNode* prev = first;
        while(last != nullptr && last->next != nullptr)
        {
            prev = first;
            first = first->next;
            last = last->next->next;
        }
        prev->next = nullptr;
        last = reverseList(first);

        //合并链表
        first = head;
        ListNode* Fnext = first->next;
        ListNode* Lnext = last->next;
        while(first)
        {
            first->next = last;
            first = Fnext;
            if(Fnext)
                Fnext = Fnext->next;
            if(first)
            {
                last->next = first;
                last = Lnext;
                Lnext = Lnext->next;
            }
            else
            {
                break;
            }
        }
    }
};


//N-2
class Solution {
public:
    ListNode* reverse(ListNode* head){
        ListNode* newHead = nullptr;
        ListNode* cur = head;
        ListNode* next = cur;
        while(next)
        {
            next = cur->next;
            cur->next = newHead;
            newHead = cur;
            cur = next;
        }
        return newHead;
    }

    void reorderList(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return;
        }
        ListNode* fast = head, *slow = head, *prev = head;
        while(fast && fast->next)
        {
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }
        prev->next = nullptr;

        ListNode* l1 = head, *l2 = slow;
        l2 = reverse(slow);
        ListNode* cur1 = l1, *cur2 = l2;
        prev = cur1;
        while(cur1)
        {
            ListNode* next1 = cur1->next;
            cur1->next = cur2;
            cur1 = next1;

            ListNode* next2 = cur2->next;
            cur2->next = cur1;
            prev = cur2;
            cur2 = next2;
        }
        //针对1->2->3->4->5这种情况, 我们前面使用了prev->next = nullptr, 所以这里必须手动连接一下最后一个
        if(cur2){
            prev->next = cur2;
        }
        return;
    }
};