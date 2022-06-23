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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* cur1 = l1, *cur2 = l2;
        int len1 = 0, len2 = 0;
        while(cur1){
            cur1 = cur1->next;
            ++len1;
        }
        while(cur2){
            cur2 = cur2->next;
            ++len2;
        }
        
        //将cur1指向最长的链表
        ListNode* head; //return 长链表的头
        if(len1 >= len2){
            cur1 = l1;
            cur2 = l2;
            head = l1;
        }
        else{
            cur1 = l2;
            cur2 = l1;
            head = l2;
        }

        ListNode* prev = cur1;  //保存cur1的上一个位置(为了保证新增结点的时候， prev能够连接上)
        int takeOver = 0;
        while(cur1 && cur2)
        {
            int res = cur1->val + cur2->val + takeOver;
            if(res >= 10){
                res -= 10;
                takeOver = 1;
            }
            else{
                takeOver = 0;
            }

            cur1->val = res;
            prev = cur1;
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
        //cur1链表还没走完
        while(cur1)
        {
            int res = cur1->val + takeOver;
            if(res >= 10){
                res -= 10;
                takeOver = 1;
            }
            else{
                takeOver = 0;
            }
            cur1->val = res;
            prev = cur1;
            cur1 = cur1->next;
        }
        //判断是否需要新增结点
        if(takeOver == 1){
            prev->next = new ListNode(1);
        }
        return head;
    }
};