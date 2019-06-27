#include <stdio.h>
#include <string>
//大数相加
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *head, *pre, *p, *p1 = l1, *p2 = l2, *p3;
    int temp, f = 0;
    head = new ListNode(-1);
    pre = head;
    while (p1 != NULL && p2 != NULL)
    {
        temp = p1->val + p2->val + f;
        if (temp > 9)
            f = 1;
        else
            f = 0;
        p = new ListNode(temp % 10);
        pre->next = p;
        pre = p;
        p1 = p1->next;
        p2 = p2->next;
    }
    if (p1 != NULL)
        p3 = p1;
    else
        p3 = p2;
    while (p3 != NULL)
    {
        temp = p3->val + f;
        if (temp > 9)
            f = 1;
        else
            f = 0;
        p = new ListNode(temp % 10);
        pre->next = p;
        pre = p;
        p3 = p3->next;
    }
    if (f)
    {
        p = new ListNode(1);
        pre->next = p;
    }
    head = head->next;
    return head;
}
// ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
// {
//     int sum = 0, tmp;
//     sum += add(l1);
//     sum += add(l2);
//     ListNode *head, *pre;
//     head = new ListNode(sum % 10);
//     sum /= 10;
//     pre = head;
//     while (sum)
//     {
//         tmp = sum % 10;
//         ListNode *p = new ListNode(tmp);
//         pre->next = p;
//         pre = p;
//         sum /= 10;
//     }
//     return head;
// }

// int add(ListNode *head)
// {
//     int sum = 0, temp, cur = 0;
//     while (head != NULL)
//     {
//         temp = head->val;
//         for (int i = 0; i < cur; i++)
//         {
//             temp *= 10;
//         }
//         sum += temp;
//         head = head->next;
//         cur++;
//     }
//     return sum;
// }

// int main()
// {
// }