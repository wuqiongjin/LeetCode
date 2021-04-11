struct ListNode* getKthFromEnd(struct ListNode* head, int k)
{
    if(head == NULL)
        return NULL;

    struct ListNode* fast = head;

    while(fast && k--)
    {
        fast = fast->next;
    }

    if(k && fast == NULL)
        return NULL;
    struct ListNode* slow = head;
    while(fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}