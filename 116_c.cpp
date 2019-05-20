#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
    {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};

//为什么递归和非递归的内存相近，时间也相近呢
Node *connect(Node *root)
{
    Node *start = root;
    Node *cur;
    while (start != NULL)
    {
        cur = start;
        while (cur != NULL)
        {
            if (cur->left != NULL)
                cur->left->next = cur->right;
            if (cur->right != NULL && cur->next != NULL)
                cur->right->next = cur->next->left;
            cur = cur->next;
        }
        start = start->left;
    }
    return root;
}