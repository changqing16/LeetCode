#include <algorithm>
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

//用hashmap更快


int arr[1000];
int ans = 0;
int target;
void dfs(TreeNode *root, int depth)
{
    arr[depth] = root->val;
    int tmp = 0;
    for (int i = depth; i >= 0; i--)
    {
        tmp += arr[i];
        if (tmp == target)
            ans += 1;
    }

    if (root->left != NULL)
        dfs(root->left, depth + 1);
    if (root->right != NULL)
        dfs(root->right, depth + 1);
}

int pathSum(TreeNode *root, int sum)
{
    if (root == NULL)
        return 0;
    target = sum;
    dfs(root, 0);
    return ans;
}