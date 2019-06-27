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

vector<int> preorderTraversal(TreeNode *root)
{
    stack<TreeNode *> s;
    vector<int> ans;
    while (root != NULL || !s.empty())
    {
        if (root != NULL)
        {
            ans.push_back(root->val);
            s.push(root);
            root = root->left;
        }
        else
        {
            root = s.top();
            s.pop();
            root = root->right;
        }
    }
    return ans;
}