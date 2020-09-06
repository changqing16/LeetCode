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
int i = 0;
TreeNode *bstFromPreorder(vector<int> &A, int bound = INT32_MAX)
{
    if (i == A.size() || A[i] > bound)
        return NULL;
    TreeNode *root = new TreeNode(A[i++]);
    root->left = bstFromPreorder(A, root->val);
    root->right = bstFromPreorder(A, bound);
    return root;
}