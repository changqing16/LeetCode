#include <iostream>
#include <vector>

using namespace std;
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node() {}

    Node(int _val, Node *_next, Node *_random)
    {
        val = _val;
        next = _next;
        random = _random;
    }
};
Node *copyRandomList(Node *head)
{
    if (head == NULL)
        return head;
    Node *cur = head, *cur1, *tmp;
    while (cur != NULL)
    {
        cur1 = cur->next;
        tmp = new Node(cur->val, cur1, NULL);
        cur->next = tmp;
        cur = cur1;
    }
    cur = head;
    while (cur != NULL)
    {
        if (cur->random != NULL)
        {
            cur->next->random = cur->random->next;
        }
        cur = cur->next->next;
    }
    cur = head;
    Node *ans = head->next;
    Node *copy = ans;
    while (copy->next != NULL)
    {
        cur->next = copy->next;
        cur = cur->next;
        copy->next = cur->next;
        copy = copy->next;
    }
    cur->next = cur->next->next;
    return ans;
}