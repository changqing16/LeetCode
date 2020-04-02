#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int level = 0;
TreeNode *node, *nodep, *nodeq, *ans;
bool flag = false;
void dfs(int k, TreeNode *root)
{

    if (root != NULL)
    {
        dfs(k + 1, root->left);
        dfs(k + 1, root->right);
    }

    if (root == nodep || root == nodeq)
    {
        if (!flag)
        {
            flag = true;
            level = k;
            node = root;
        }
        if (flag)
            return;
    }
    if (root->left != NULL)
        dfs(k + 1, root->left);
    if (level > k)
    {
        level = k;
        node = root;
    }
    if (root->right != NULL)
        dfs(k + 1, root->right);
}

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (root == NULL || root == p || root == q)
        return root;
    TreeNode *left = lowestCommonAncestor(root->left, p, q);
    TreeNode *right = lowestCommonAncestor(root->right, p, q);
    return !left ? right : !right ? left : root;
}
