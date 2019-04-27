#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    bool flag = true;
    vector<vector<int>> ans;
    queue<TreeNode *> q;
    TreeNode *node = root;
    TreeNode *first = root;
    if (node != NULL)
    {
        q.push(node);
        while (!q.empty())
        {
            node = q.front();
            if (node == first)
            {
                if (flag && !ans.empty())
                    reverse(ans.back().begin(), ans.back().end());
                flag = !flag;
                ans.push_back(vector<int>());
                first = NULL;
            }
            ans.back().push_back(node->val);
            q.pop();
            if (node->left != NULL)
            {
                if (first == NULL)
                    first = node->left;
                q.push(node->left);
            }
            if (node->right != NULL)
            {
                if (first == NULL)
                    first = node->right;
                q.push(node->right);
            }
        }
    }
    if (flag && !ans.empty())
        reverse(ans.back().begin(), ans.back().end());
    return ans;
}