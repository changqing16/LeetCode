#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *sortList(ListNode *head)
{
    ListNode *ans = head;
    ListNode *cur, *index, *tmp;
    cur = head->next;
    while (cur != NULL)
    {
        index = ans;
        if (cur->val <= ans->val)
        {
            tmp = cur->next;
            cur->next = ans;
            ans = cur;
            cur = tmp;
        }
        index = ans->next;
        while (index->next != NULL)
        {
            
        }
    }
}
