#include <iostream>
#include <stack>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


bool isValidBST(TreeNode *root)
{
    bool first = true;
    int prev, cur;
    stack<TreeNode *> s;
    TreeNode *node = root;
    while (node != NULL || !s.empty())
    {
        while (node != NULL)
        {
            s.push(node);
            node = node->left;
        }

        node = s.top();
        s.pop();
        if (first)
        {
            prev = node->val;
            first = false;
        }
        else
        {
            cur = node->val;
            if (prev >= cur)
                return false;
            prev = cur;
        }
        node = node->right;
    }
    return true;
}
