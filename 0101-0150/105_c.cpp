#include <stack>
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

// TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
// {
//     if (preorder.empty())
//         return nullptr;
//     unordered_map<int, int> pos;
//     for (int i = 0; i != inorder.size(); ++i)
//         pos[inorder[i]] = i;
//     TreeNode *root = new TreeNode(preorder[0]);
//     stack<TreeNode *> todo;
//     todo.push(root);
//     for (int i = 1; i != preorder.size(); ++i)
//     {
//         TreeNode *node = new TreeNode(preorder[i]);
//         if (pos[node->val] < pos[todo.top()->val])
//             todo.top()->left = node;
//         else
//         {
//             TreeNode *parent(nullptr);
//             while (!todo.empty() && pos[node->val] > pos[todo.top()->val])
//                 parent = todo.top(), todo.pop();
//             parent->right = node;
//         }
//         todo.push(node);
//     }
//     return root;
// }
TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    TreeNode *root = NULL;
    stack<TreeNode *> MyData;
    if (preorder.empty())
        return root;
    root = new TreeNode(preorder[0]);
    MyData.push(root);
    int index = 0;
    for (int i = 1; i <= preorder.size(); i++)
    {
        TreeNode *cur = MyData.top();
        if ((MyData.top()->val) != inorder[index])
        {
            cur->left = new TreeNode(preorder[i]);
            MyData.push(cur->left);
        }
        else
        {
            while (!MyData.empty() && ((MyData.top()->val) == inorder[index]))
            {
                cur = MyData.top();
                MyData.pop();
                index++;
            }
            if (index < inorder.size())
            {
                cur->right = new TreeNode(preorder[i]);
                MyData.push(cur->right);
            }
        }
    }
    return root;
}