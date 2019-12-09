#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int maxProduct(vector<int> &nums)
{
    int r = nums[0], imin = nums[0], imax = nums[0];
    for (size_t i = 1; i < nums.size(); i++)
    {
        if (nums[i] < 0)
            swap(imax, imin);
        imax = max(nums[i], imax * nums[i]);
        imin = min(nums[i], imin * nums[i]);

        r = max(r, imax);
    }
    return r;
}

int main()
{
    vector<int> nums = {2, 3, -2, 4};
    cout << maxProduct(nums) << endl;
}