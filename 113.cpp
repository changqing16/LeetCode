#include <algorithm>
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

vector<vector<int>> ans;
vector<int> fa;

void perT(TreeNode *root, int sum)
{
    sum -= root->val;
    fa.push_back(root->val);

    if (root->left == NULL && root->right == NULL && sum == 0)
    {
        ans.push_back(vector<int>());
        ans.back().assign(fa.begin(), fa.end());
        fa.pop_back();
        return;
    }

    if (root->left != NULL)
        perT(root->left, sum);
    if (root->right != NULL)
        perT(root->right, sum);
    fa.pop_back();
}

vector<vector<int>> pathSum(TreeNode *root, int sum)
{
    if (root == NULL)
        return ans;
    perT(root, sum);
}