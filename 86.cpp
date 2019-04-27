
#include <algorithm>
#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *partition(ListNode *head, int x)
{
    if (head == NULL)
        return head;
    ListNode *bigger, *mid, *smaller, *cur, *bef;
    ListNode h(-1);
    h.next = head;
    bef = &h;
    cur = head;
    bool flag = true;
    while (cur != NULL && cur->val < x)
    {
        bef = cur;
        cur = cur->next;
    }
    bigger = bef;
    while (cur != NULL)
    {
        if (flag && cur->val < x)
        {
            mid = bef;
            flag = false;
        }
        else if (!flag && cur->val >= x)
        {
            smaller = bef;
            ListNode *tmp1 = bigger->next;
            bigger->next = mid->next;
            smaller->next = tmp1;
            mid->next = cur;
            bigger = smaller;
            flag = true;
        }
        bef = cur;
        cur = cur->next;
    }
    if (!flag)
    {
        ListNode *tmp1 = bigger->next;
        bigger->next = mid->next;
        bef->next = tmp1;
        mid->next = NULL;
    }
    return h.next;
}

int main()
{
}