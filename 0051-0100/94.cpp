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

// void InOrder(TreeNode *root, vector<int> &ans)
// {
//     if (root != NULL)
//     {
//         InOrder(root->left, ans);
//         ans.push_back(root->val);
//         InOrder(root->right, ans);
//     }
// }

// vector<int> inorderTraversal(TreeNode *root)
// {
//     vector<int> ans;
//     InOrder(root, ans);
//     return ans;
// }

vector<int> inorderTraversal(TreeNode *root)
{
    stack<TreeNode *> s;
    vector<int> ans;
    while (root != NULL || !s.empty())
    {
        if (root != NULL)
        {
            s.push(root);
            root = root->left;
        }
        else
        {
            root = s.top();
            s.pop();
            ans.push_back(root->val);
            root = root->right;
        }
    }
    return ans;
}