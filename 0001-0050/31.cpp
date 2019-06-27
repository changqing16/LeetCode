#include <algorithm>
#include <stdio.h>
#include <vector>
using namespace std;

void nextPermutation(vector<int> &nums)
{
    int k = -1, size =nums.size();
    for (int i =size - 2; i >= 0; i--)
    {
        if (nums[i] < nums[i + 1])
        {
            k = i;
            break;
        }
    }
    if (k == -1)
    {
        reverse(nums.begin(), nums.end());
        return;
    }
    int l = -1;
    for (int i =size - 1; i > k; i--)
    {
        if (nums[i] > nums[k])
        {
            l = i;
            break;
        }
    }
    swap(nums[k], nums[l]);
    reverse(nums.begin() + k + 1, nums.end());
}

int main()
{
    vector<int> nums;
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(1);
    // nums.push_back(6);
    // nums.push_back(4);
    // nums.push_back(3);
    // nums.push_back(5);
    // nums.push_back(1);
    // nums.push_back(2);
    nextPermutation(nums);
    for (int i = 0; i <size; i++)
    {
        printf("%d ", nums[i]);
    }
}
