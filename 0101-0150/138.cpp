#include <iostream>
#include <unordered_map>
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
        return NULL;
    Node *cur = head;
    vector<Node *> nodes;
    int c = 0;
    while (cur != NULL)
    {
        nodes.push_back(new Node(cur->val, NULL, NULL));
        cur->val = c;
        c++;
        cur = cur->next;
    }
    nodes.push_back(NULL);
    cur = head;
    c = 0;
    while (cur != NULL)
    {
        if (cur->random != NULL)
            nodes[c]->random = nodes[cur->random->val];
        nodes[c]->next = nodes[c + 1];
        c++;
        cur = cur->next;
    }
    return nodes[0];
}