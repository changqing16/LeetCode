
#include <iostream>
#include <vector>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *build(vector<ListNode *> &ans, int x, int y)
{
    if (x >= y)
        return NULL;
    int mid = (x + y) / 2;
    TreeNode *root = new TreeNode(ans[mid]->val);
    root->left = build(ans, x, mid);
    root->right = build(ans, mid + 1, y);
    return root;
}

TreeNode *sortedListToBST(ListNode *head)
{
    vector<ListNode *> ans;
    while (true)
    {
        if (head != NULL)
        {
            ans.push_back(head);
            head = head->next;
        }
        else
            break;
    }
    return build(ans, 0, ans.size());
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
    ListNode *node = new ListNode(0);
    ListNode *aa = node;
    for (int i = 1; i < 5; i++)
    {
        aa->next = new ListNode(i);
        aa = aa->next;
    }
    TreeNode *root = sortedListToBST(node);
    preT(root);
}