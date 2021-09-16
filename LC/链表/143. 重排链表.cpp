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