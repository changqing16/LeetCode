#include <stdio.h>
#include <vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *swapPairs(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    ListNode *first, *second, *pre;
    ListNode *nHead = new ListNode(1);
    nHead->next = head;

    pre = nHead;
    while (pre->next != NULL)
    {
        first = pre->next;
        if (first->next != NULL)
        {
            second = first->next;
            pre->next = second;
            first->next = second->next;
            second->next = first;
            pre = first;
        }
        else
            return nHead->next;
    }
    return nHead->next;
}