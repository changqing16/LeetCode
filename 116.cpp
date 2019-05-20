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

void dfs(Node *root, Node *next)
{
    if (root == NULL)
        return;
    root->next = next;
    dfs(root->left, root->right);
    if (root->next != NULL)
        dfs(root->right, root->next->left);
    else
        dfs(root->right, NULL);
}

Node *connect(Node *root)
{
    dfs(root, NULL);
    return root;
}