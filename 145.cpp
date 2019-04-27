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

vector<int> postorderTraversal(TreeNode *root)
{
    stack<TreeNode *> s;
    vector<int> ans;
    TreeNode *last = root; //当前考察节点的右子树
    while (root != NULL || !s.empty())
    {
        while (root != NULL)
        {
            s.push(root);
            root = root->left;
        }
        root = s.top();
        if (root->right == NULL || root->right == last)
        {
            ans.push_back(root->val);
            s.pop();
            last = root;
            root = NULL;
        }
        else
        {
            root = root->right;
        }
    }
    return ans;
}