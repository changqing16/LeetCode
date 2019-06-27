#include <iostream>

using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *deleteDuplicates(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    ListNode h(-1);
    h.next = head;
    ListNode *pre, *cur;
    pre = &h;
    h.next = head;
    int dep = 0;
    while (pre->next != NULL)
    {
        if (pre->next->next != NULL && pre->next->next->val == pre->next->val)
        {
            dep = pre->next->val;
            cur = pre->next->next->next;
            while (cur != NULL && cur->val == dep)
                cur = cur->next;
            pre->next = cur;
        }
        else
            pre = pre->next;
    }
    return h.next;
}