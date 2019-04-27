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
TreeNode *build(vector<int> &pre, vector<int> &in, int x, int y, int idx)
{
    if (x < y)
    {
        TreeNode *root = new TreeNode(pre[idx]);
        int i = x;
        for (; i < y; i++)
            if (in[i] == pre[idx])
                break;
        root->left = build(pre, in, x, i, idx + 1);
        root->right = build(pre, in, i + 1, y, idx + 1 + i - x);
        return root;
    }
    else
        return NULL;
}
TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    if (preorder.size() == 0)
        return NULL;
    TreeNode *root = new TreeNode(preorder[0]);
    int i = 0;
    for (; i < inorder.size(); i++)
        if (inorder[i] == preorder[0])
            break;
    root->left = build(preorder, inorder, 0, i, 1);
    root->right = build(preorder, inorder, i + 1, inorder.size(), i + 1);
    return root;
}
void preT(TreeNode *root)
{
    if (root->left != NULL)
        preT(root->left);
    cout << root->val << ",";
    if (root->right != NULL)
        preT(root->right);
}

int main()
{
    vector<int> pre = {3, 9, 20, 15, 7};
    vector<int> in = {9, 3, 15, 20, 7};
    TreeNode *root = buildTree(pre, in);
    preT(root);
    cout << endl;
    return 0;
}

// TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
// {
//     int num = preorder.size();
//     TreeNode *tree[num];
//     for (int i = 0; i < num; i++)
//         tree[i] = new TreeNode(preorder[i]);
//     int x = 0, y = 0, idx = 0;

//     for(int i=0;i<)

//     return tree[0]
// }
