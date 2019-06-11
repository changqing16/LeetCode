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
TreeNode *toBST(ListNode *head, ListNode *tail)
{
    ListNode *slow = head;
    ListNode *fast = head;
    if (head == tail)
        return NULL;
    while (fast != tail && fast->next != tail)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    TreeNode *thead = new TreeNode(slow->val);
    thead->left = toBST(head, slow);
    thead->right = toBST(slow->next, tail);
    return thead;
}
TreeNode *sortedListToBST(ListNode *head)
{
    if (head == NULL)
        return NULL;
    return toBST(head, NULL);
}