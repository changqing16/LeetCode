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

int ans = 0;

void dfs(TreeNode *root, int num)
{
    num = num * 10 + root->val;
    if (root->left == NULL && root->right == NULL)
    {
        ans += num;
        return;
    }
    if (root->left != NULL)
        dfs(root->left, num);
    if (root->right != NULL)
        dfs(root->right, num);
}

int sumNumbers(TreeNode *root)
{
    dfs(root, 0);
    return ans;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    cout << sumNumbers(root) << endl;
}