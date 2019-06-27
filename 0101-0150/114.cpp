#include <iostream>
#include <vector>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *dfs(TreeNode *root)
{
    TreeNode *left = root->left, *right = root->right, *last = root;
    root->left = NULL;
    if (left != NULL)
    {
        last = dfs(left);
        root->right = left;
    }
    if (right != NULL)
    {
        last->right = right;
        last = dfs(right);
    }
    return last;
}

void flatten(TreeNode *root)
{
    if (root != NULL)
        dfs(root);
}