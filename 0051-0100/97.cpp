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

TreeNode *addTreeVal(TreeNode *root, int num)
{
    if (root == NULL)
        return NULL;
    TreeNode *new_node = new TreeNode(root->val + num);
    new_node->left = addTreeVal(root->left, num);
    new_node->right = addTreeVal(root->right, num);
    return new_node;
}

vector<TreeNode *> generateTrees(int n)
{
    if (n == 0)
        return vector<TreeNode *>();
    vector<vector<TreeNode *>> help(n + 1, vector<TreeNode *>());
    TreeNode *tree0 = NULL;
    help[0].push_back(tree0);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            for (size_t x = 0; x < help[j].size(); x++)
            {
                for (size_t y = 0; y < help[i - j - 1].size(); y++)
                {
                    TreeNode *new_node = new TreeNode(j + 1);
                    new_node->left = help[j][x];
                    new_node->right = addTreeVal(help[i - j - 1][y], j + 1);
                    help[i].push_back(new_node);
                }
            }
        }
    }

    return help[n];
}

void preOrder(TreeNode *root)
{
    if (root != NULL)
    {
        cout << root->val << "-";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(TreeNode *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        cout << root->val << '-';
        inOrder(root->right);
    }
}

void Order(TreeNode *root)
{
    if (root != NULL)
    {
        Order(root->left);
        Order(root->right);
        cout << root->val << '-';
    }
}

int main()
{
    vector<TreeNode *> ans = generateTrees(5);
    for (int i = 0; i < ans.size(); i++)
    {
        Order(ans[i]);
        cout << endl;
    }
}