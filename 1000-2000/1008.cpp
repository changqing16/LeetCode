#include <iostream>
#include <stack>
#include <vector>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode *build(vector<int> &preorder, int s, int e)
{
    if (s > e)
        return NULL;
    TreeNode *root = new TreeNode(preorder[s]);
    int mid;
    for (mid = s + 1; mid <= e; mid++)
    {
        if (preorder[mid] > preorder[s])
            break;
    }
    root->left = build(preorder, s + 1, mid - 1);
    root->right = build(preorder, mid, e);
}

TreeNode *bstFromPreorder(vector<int> &preorder)
{
    return build(preorder, 0, preorder.size() - 1);
}