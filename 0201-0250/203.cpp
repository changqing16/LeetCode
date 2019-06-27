#include <stdio.h>

struct ListNode
{
    int val;
    ListNode *next;
};

ListNode *removeElements(ListNode *head, int val)
{
    while (head != NULL && head->val == val)
    {
        head = head->next;
    }
    ListNode *p;
    if (head != NULL)
        p = head->next;
    else
        return head;
    ListNode *pre = head;
    while (p != NULL)
    {
        if (p->val == val)
        {
            pre->next = p->next;
            p = pre->next;
        }
        else
        {
            pre = p;
            p = p->next;
        }
    }
    return head;
}