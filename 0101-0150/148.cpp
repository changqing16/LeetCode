#include <iostream>
#include <vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *first = new ListNode(-1);
    ListNode *merge(ListNode *head1, ListNode *head2)
    {
        ListNode *index;
        index = first;
        while (head1 != NULL && head2 != NULL)
        {
            if (head1->val < head2->val)
            {
                index->next = head1;
                head1 = head1->next;
            }
            else
            {
                index->next = head2;
                head2 = head2->next;
            }
            index = index->next;
        }
        index->next = (head1) ? head1 : head2;

        return first->next;
    }

    ListNode *split(ListNode *head)
    {
        ListNode *slow = head, *fast = head->next, *head2;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        head2 = slow->next;
        slow->next = NULL;
        return head2;
    }

    ListNode *sortList(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode *head2 = split(head);

        head = sortList(head);
        head2 = sortList(head2);

        head = merge(head, head2);

        return head;
    }
};