#include <stdio.h>
#include <vector>
using namespace std;

vector<int> searchRange(vector<int> &nums, int target)
{
    vector<int> ans = {-1, -1};
    int loc = -1, top = nums.size() - 1, base = 0, mid;
    while (top >= base)
    {
        mid = (base + top) / 2;
        if (target == nums[mid])
        {
            loc = mid;
            break;
        }
        else if (target < nums[mid])
            top = mid - 1;
        else
            base = mid + 1;
    }


    if (loc != -1)
    {
        int start = loc, end = loc;
        while (start >= 0 && nums[start] == target)
            start--;
        while (end < nums.size() && nums[end] == target)
            end++;
        ans[0] = start + 1;
        ans[1] = end - 1;
    }
    return ans;
}

int main()
{
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    vector<int> ans = searchRange(nums, 8);
    printf("%d %d", ans[0], ans[1]);
}