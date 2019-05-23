#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

//别人的代码
// void connect(TreeLinkNode *root) {
//     TreeLinkNode *now, *tail, *head;

//     now = root;
//     head = tail = NULL;
//     while(now)
//     {
//         if (now->left)
//             if (tail) tail = tail->next =now->left;
//             else head = tail = now->left;
//         if (now->right)
//             if (tail) tail = tail->next =now->right;
//             else head = tail = now->right;
//         if(!(now = now->next))
//         {
//             now = head;
//             head = tail=NULL;
//         }
//     }
// }

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

tuple<Node *, Node *> getFirst(Node *root)
{
    if (root == NULL)
        return {NULL, NULL};
    if (root->left != NULL)
        return {root, root->left};
    else if (root->right != NULL)
        return {root, root->right};
    else
        return getFirst(root->next);
}

Node *connect(Node *root)
{
    if (root == NULL)
        return NULL;
    Node *first = root;
    Node *pre, *next_item, *cur;
    while (first != NULL)
    {
        //"first" is the first node of each level
        std::tie(pre, first) = getFirst(first); //go to the next level
        cur = first;
        while (cur != NULL) //make sure "pre" is "cur"'s father
        {
            if (cur == pre->left && pre->right != NULL)
                cur->next = pre->right;
            else
            {
                std::tie(pre, next_item) = getFirst(pre->next);
                cur->next = next_item;
            }
            cur = cur->next;
        }
    }
    return root;
}
