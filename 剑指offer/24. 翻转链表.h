struct ListNode* reverseList(struct ListNode* head)
{
    if(head == NULL || head->next == NULL)
        return head;
    //头插法翻转
    struct ListNode* newHead = NULL;
    struct ListNode* cur = head;
    struct ListNode* next = head;
    while(next)
    {
        next = next->next;
        cur->next = newHead;
        newHead = cur;
        cur = next;
    }
    return newHead;
}