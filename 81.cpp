#include <stdio.h>
#include <vector>
using namespace std;

bool search(vector<int> &nums, int target)
{
    int low = 0;
    int high = nums.size() - 1;
    while (low <= high)
    {
        while (low <= high && nums[low] == nums[low + 1])
            low++;
        while (low <= high && nums[high] == nums[high - 1])
            high--;
        int mid = low + (high - low) / 2;
        if (nums[mid] == target)
            return true;
        else if (nums[low] <= nums[mid])
        { // left half is sorted
            if (target >= nums[low] && target < nums[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        else
        { // right half is sorted
            if (target > nums[mid] && target <= nums[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    return false;
}

int main()
{
    vector<int> nums = {2,5,6,0,0,1,2};
    bool ans = search(nums, 3);
    printf("%d\n", ans);
}