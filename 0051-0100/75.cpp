#include <iostream>
#include <vector>
using namespace std;

void sortColors(vector<int> &nums)
{
    int a0 = 0, a1 = 0, i;
    for (i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 0)
            a0++;
        else if (nums[i] == 1)
            a1++;
    }
    for (i = 0; i < a0; i++)
        nums[i] = 0;
    for (; i < a1 + a0; i++)
        nums[i] = 1;
    for (; i < nums.size(); i++)
        nums[i] = 2;
}

// void sortColors(int A[], int n)
// {
//     int second = n - 1, zero = 0;
//     for (int i = 0; i <= second; i++)
//     {
//         while (A[i] == 2 && i < second)
//             swap(A[i], A[second--]);
//         while (A[i] == 0 && i > zero)
//             swap(A[i], A[zero++]);
//     }
// }