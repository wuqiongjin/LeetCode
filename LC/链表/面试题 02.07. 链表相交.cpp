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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        int length1 = 0, lenght2 =0;
        ListNode* cur = headA;
        while(cur)
        {
            cur = cur->next;
            ++length1;
        }

        cur = headB;
        while(cur)
        {
            cur = cur->next;
            ++lenght2;
        }

        int differ = length1 - lenght2;
        ListNode* curA = headA;
        ListNode* curB = headB;
        if(differ > 0)
        {
            while(differ)
            {
                differ--;
                curA = curA->next;
            }
        }
        else if(differ < 0)
        {
            while(differ)
            {
                ++differ;
                curB = curB->next;
            }
        }

        while(curA != curB)
        {
            curA = curA->next;
            curB = curB->next;
        }

        return curA;
    }
};