#include <stdio.h>
#include <vector>
using namespace std;

int bin_search(vector<int> &nums, int target, int s, int e)
{
    if (s > e)
        return -1;
    int mid = (s + e) / 2;
    if (target == nums[mid])
    {
        return mid;
    }

    if (target > nums[mid])
    {
        if (target > nums[e] && nums[mid] < nums[e])
            return bin_search(nums, target, s, mid - 1);
        else
            return bin_search(nums, target, mid + 1, e);
    }
    else
    {
        if (target <= nums[e] && nums[mid] > nums[e])
            return bin_search(nums, target, mid + 1, e);
        else
            return bin_search(nums, target, s, mid - 1);
    }
}

int search(vector<int> &nums, int target)
{
    return bin_search(nums, target, 0, nums.size() - 1);
}

int main()
{
    vector<int> nums = {1, 3, 5};
    int ans = search(nums, 1);
    printf("%d", ans);
}