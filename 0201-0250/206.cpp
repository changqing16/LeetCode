#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *reverseList(ListNode *head)
{
    ListNode *before, *after;
    after = NULL;
    while (head != NULL)
    {
        before = head->next;
        head->next = after;
        after = head;
        head = before;
    }
    return after;
}