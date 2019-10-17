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
    ListNode *ans = new ListNode(-1);
    ListNode *cur, *index, *tmp;
    cur = head;
    while (cur != NULL)
    {
        index = ans;
        while (index->next != NULL && index->next->val < cur->next->val)
            index = index->next;
        tmp = cur->next;
        cur->next = index->next;
        index->next = cur;
        cur = tmp;
    }
    return ans->next;
}
