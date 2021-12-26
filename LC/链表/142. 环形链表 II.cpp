/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) 
    {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow)
            {
                ListNode* meet = fast;
                ListNode* start = head;
                //这里是精髓，找到fast与slow的相遇点后，相遇点meet和头结点head到入环点的距离是"相同的"!
                while(start != meet)
                {
                    start = start->next;
                    meet = meet->next;
                }
                return meet;
            }
        }
        return nullptr;
    }
};


// class Solution {
// public:
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
//     {
//         int length1 = 0, lenght2 =0;
//         ListNode* cur = headA;
//         while(cur)
//         {
//             cur = cur->next;
//             ++length1;
//         }

//         cur = headB;
//         while(cur)
//         {
//             cur = cur->next;
//             ++lenght2;
//         }

//         int differ = length1 - lenght2;
//         ListNode* curA = headA;
//         ListNode* curB = headB;
//         if(differ > 0)
//         {
//             while(differ)
//             {
//                 differ--;
//                 curA = curA->next;
//             }
//         }
//         else if(differ < 0)
//         {
//             while(differ)
//             {
//                 ++differ;
//                 curB = curB->next;
//             }
//         }

//         while(curA != curB)
//         {
//             curA = curA->next;
//             curB = curB->next;
//         }

//         return curA;
//     }

//     ListNode *detectCycle(ListNode *head) 
//     {
//         if(head == nullptr || head->next == nullptr) return nullptr;
//         ListNode* fast = head->next->next, *slow = head->next;
//         while(fast && fast->next && fast != slow)
//         {
//             fast = fast->next->next;
//             slow = slow->next;
//         }
        
//         if(fast == nullptr || fast->next == nullptr)
//             return nullptr;
        
//         ListNode* meet = fast;
//         ListNode* cur1 = head, *cur2 = meet->next;
//         meet->next = nullptr;
    
//         return getIntersectionNode(cur1, cur2);
//     }
// };