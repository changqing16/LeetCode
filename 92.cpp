#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *reverseBetween(ListNode *head, int m, int n)
{
    ListNode new_head(0);
    new_head.next = head;
    ListNode *pre = &new_head;
    for (int i = 0; i < m - 1; i++)
        pre = pre->next;
    ListNode *cur = pre->next;
    ListNode *move;
    for (int i = 0; i < n - m; i++)
    {
        move = cur->next;
        cur->next = move->next;
        move->next = pre->next;
        pre->next = move;
    }
    return new_head.next;
}

int main()
{
    ListNode *head = new ListNode(0);
    ListNode *h = head;
    for (int i = 1; i < 6; i++)
    {
        head->next = new ListNode(i);
        head = head->next;
    }
    head = h;
    while (head != NULL)
    {
        cout << head->val << "->";
        head = head->next;
    }
    cout << endl;
    head = reverseBetween(h->next, 2, 5);
    while (head != NULL)
    {
        cout << head->val << "->";
        head = head->next;
    }
    cout << endl;
}