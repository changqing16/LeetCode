#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool isPalindrome(ListNode *head)
{
    ListNode *slow = head, *fast = head, *cur;
    ListNode *dummy = new ListNode(-1);
    while (fast != NULL && fast->next != NULL)
    {
        cur = slow;
        slow = slow->next;
        fast = fast->next->next;

        cur->next = dummy->next;
        dummy->next = cur;
    }
    if (fast != NULL)
        slow = slow->next;
    fast = dummy->next;
    
    while (slow != NULL)
    {
        if (slow->val != fast->val)
            return false;
        slow = slow->next;
        fast = fast->next;
    }
    return true;
}