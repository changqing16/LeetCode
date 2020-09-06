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

int help(TreeNode *root, int &m, int &n)
{
    if (root == nullptr)
    {
        m = 0;
        n = 0;
    }

    int ml, nl, mr, nr;
    help(root->left, ml, nl);
    help(root->right, mr, nr);
    m = root->val + nl + nr;
    n = max(ml, nl) + max(mr, nr);
}

vector<int> robber(TreeNode *root)
{
    vector<int> ans(2, 0);
    if (root == NULL)
    {
        return ans;
    }
    vector<int> left = robber(root->left);
    vector<int> right = robber(root->right);
    ans[0] = max(left[0], left[1]) + max(right[0], right[1]);
    ans[1] = root->val + left[0] + right[0];
    return ans;
}

int rob(TreeNode *root)
{
    vector<int> ans = robber(root);
    return max(ans[0], ans[1]);
}