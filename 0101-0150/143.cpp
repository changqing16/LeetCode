#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void reorderList(ListNode *head)
{
    if (head == NULL)
        return;
    ListNode *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode *pre, *cur, *tmp;
    cur = slow->next;
    slow->next = NULL;
    pre = NULL;
    while (cur != NULL)
    {
        tmp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = tmp;
    }
    cur = pre;
    ListNode *nn = head;
    while (cur != NULL)
    {
        tmp = cur->next;
        cur->next = nn->next;
        nn->next = cur;
        nn = cur->next;
        cur = tmp;
    }
}