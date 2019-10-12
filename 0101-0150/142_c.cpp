#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *detectCycle(ListNode *head)
{
    ListNode *cur, *dd;

    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }

    cur = head->next;
    dd = head->next->next;

    while (cur != dd)
    {
        cur = cur->next;
        if (dd == NULL || dd->next == NULL)
        {
            return NULL;
        }
        dd = dd->next->next;
    }
    cur = head;
    while (cur != dd)
    {
        cur = cur->next;
        dd = dd->next;
    }
    return cur;
}

int main()
{
    ListNode *tmp = new ListNode(0);
    ListNode *head = tmp;
    for (int i = 1; i < 6; i++)
    {
        tmp->next = new ListNode(i);
        tmp = tmp->next;
    }
    tmp->next = head->next->next;
    ListNode *ans = detectCycle(head);
    cout << ans->val << endl;
}
