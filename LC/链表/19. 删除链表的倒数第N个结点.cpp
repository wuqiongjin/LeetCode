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
// class Solution {
// public:
//     //这题保证了链表当中一定存在结点了(注意一下审题)
//     ListNode* removeNthFromEnd(ListNode* head, int n) 
//     {
//         ListNode* DummyHead = new ListNode;
//         DummyHead->next = head;
//         ListNode* del = head;
//         ListNode* cur = head;
//         ListNode* Prev = DummyHead;

//         while(n-- && cur)
//             cur = cur->next;
        
//         if(n != -1)
//             return DummyHead->next;
        
//         while(cur)
//         {
//             Prev = del;
//             del = del->next;
//             cur = cur->next;
//         }

//         Prev->next = del->next;
//         delete del;

//         return DummyHead->next;
//     }
// };

//N-2
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode* DummyHead = new ListNode;
        DummyHead->next = head;

        ListNode* fast = head;
        ListNode* slow = head;
        while(n--)
            fast = fast->next;

        ListNode* prev = DummyHead;
        while(fast)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next;
        }

        prev->next = slow->next;
        return DummyHead->next;
    }
};