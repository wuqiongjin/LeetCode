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
    //头插法反转   (还可以通过改变链表结点之间的指针指向来反转)
    ListNode* reverseList(ListNode* head) 
    {
        if(head == nullptr || head->next == nullptr)
            return head;

        ListNode* newHead = nullptr;
        ListNode* cur = head;
        while(cur)
        {
            ListNode* Next = cur->next;
            cur->next = newHead;
            newHead = cur;
            cur = Next;
        }
        return newHead;
    }
};