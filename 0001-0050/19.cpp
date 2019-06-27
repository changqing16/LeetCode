#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *removeNthFromEnd(ListNode *head, int n)
{
    ListNode *first = head, *second = head;
    int length = 0;
    while (first != NULL)
    {
        if (length - n > 0)
            second = second->next;

        length++;
        first = first->next;
    }

    if (second == head && length == n)
        return head->next;
    else
    {
        ListNode *tmp = second->next;
        second->next = tmp->next;
        return head;
    }
}

int main()
{
    ListNode *head;
    head = new ListNode(1);
    ListNode *p = head;

    for (int i = 0; i < 2; i++)
    {
        ListNode *now = new ListNode(i + 2);
        p->next = now;
        p = p->next;
    }
    ListNode *ans = removeNthFromEnd(head, 2);
    while (ans != NULL)
    {
        printf("%d ", ans->val);
        ans = ans->next;
    }
}