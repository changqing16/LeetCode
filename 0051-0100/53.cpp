#include <iostream>
#include <vector>
using namespace std;

// class Solution
// {
// public
//     int maxSubArray(int[] nums)
//     {
//         int n = nums.length;
//         int currSum = nums[0], maxSum = nums[0];

//         for (int i = 1; i < n; ++i)
//         {
//             currSum = Math.max(nums[i], currSum + nums[i]);
//             maxSum = Math.max(maxSum, currSum);
//         }
//         return maxSum;
//     }
// }

int maxSubArray(vector<int> &nums)
{
    int ans = nums[0];
    int cur = 0;
    int p2 = 0;

    while (p2 < nums.size())
    {
        if (cur + nums[p2] > 0)
        {
            cur = cur + nums[p2];
            ans = max(cur, ans);
        }
        else
        {
            ans = max(cur, ans);
            cur = 0;
        }
        p2++;
    }
    return ans;
}
int main()
{
    vector<int> nums = {-2, -1};
    cout << maxSubArray(nums) << endl;
    return 0;
}