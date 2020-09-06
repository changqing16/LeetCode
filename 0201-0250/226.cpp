#include <iostream>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void pre(TreeNode *root)
{
    if (root == NULL)
        return;
    TreeNode *tmp = root->left;
    root->left = root->right;
    root->right = tmp;
    pre(root->left);
    pre(root->right);
}

TreeNode *invertTree(TreeNode *root)
{
    pre(root);
    return root;
}