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

TreeNode *build(vector<int> &in, vector<int> &post, int x, int y, int idx)
{
    if (x < y)
    {
        TreeNode *root = new TreeNode(post[idx]);
        int i = x;
        //此处可使用unorder_map
        for (; i < y; i++)
            if (in[i] == post[idx])
                break;
        root->left = build(in, post, x, i, idx - (y - i));
        root->right = build(in, post, i + 1, y, idx - 1);
        return root;
    }
    else
        return NULL;
}

TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
{
    if (postorder.size() == 0)
        return NULL;
    TreeNode *root = new TreeNode(postorder.back());
    cout<<root->val<<endl;
    int i = 0;
    for (; i < inorder.size(); i++)
        if (inorder[i] == postorder.back())
            break;
    root->left = build(inorder, postorder, 0, i, i - 1);
    root->right = build(inorder, postorder, i + 1, inorder.size(), inorder.size() - 2);
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
    vector<int> in = {9, 3, 15, 20, 7};
    vector<int> post = {9, 15, 7, 20, 3};
    TreeNode *root = buildTree(in, post);
    preT(root);
    cout << endl;
    return 0;
}