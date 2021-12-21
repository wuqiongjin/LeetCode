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
    ListNode* swapPairs(ListNode* head) 
    {
        if(head == nullptr || head->next == nullptr)
            return head;
        ListNode* DummyHead = new ListNode;
        DummyHead->next = head;
        
        ListNode* Prev = DummyHead;
        ListNode* cur = head;
        while(cur && cur->next)
        {
            ListNode* Next = cur->next;
            cur->next = Next->next;
            Prev->next = Next;
            Next->next = cur;
            Prev = cur;
            cur = cur->next;
        }
        return DummyHead->next;
    }
};