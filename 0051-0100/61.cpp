#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *rotateRight(ListNode *head, int k)
{
    if (head == NULL || head->next == NULL)
        return head;
    int length = 0;
    ListNode *theK = head, *cur = head;
    while (cur->next != NULL)
    {
        length++;
        if (length > k)
            theK = theK->next;
        cur = cur->next;
    }
    length++;
    if (k % length == 0)
        return head;

    if (k > length)
    {
        k = k % length;
        for (int i = 0; i < length - k - 1; i++)
            theK = theK->next;
    }
    cur->next = head;
    cur = theK->next;
    theK->next = NULL;
    return cur;
}

int main()
{
    ListNode *head = new ListNode(0);
    ListNode *cur = head;
    for (int i = 1; i < 3; i++)
    {
        cur->next = new ListNode(i);
        cur = cur->next;
    }
    cur->next = NULL;
    cur = rotateRight(head, 4);
    while (cur != NULL)
    {
        cout << cur->val << "->";
        cur = cur->next;
    }
    cout << "NULL" << endl;
}