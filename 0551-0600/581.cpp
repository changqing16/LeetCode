#include <iostream>
#include <vector>

using namespace std;

int findUnsortedSubarray(vector<int> &nums)
{
    int start = 0, end = 0;
    int cur = nums.size() - 1;
    for (int i = nums.size() - 2; i >= 0; i--)
    {
        if (nums[i] <= nums[cur])
        {
            cur = i;
        }
        else
        {
            start = i;
        }
    }
    cur = 0;
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] < nums[cur])
        {
            end = i;
        }
        else
        {
            cur = i;
        }
    }
    return end - start + 1;
}
