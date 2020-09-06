#include <iostream>
#include <vector>

using namespace std;

// class Solution {
// public:
//     int rob(vector<int>& nums) {
//         int n = nums.size(); 
//         if (n < 2) return n ? nums[0] : 0;
//         return max(robber(nums, 0, n - 2), robber(nums, 1, n - 1));
//     }
// private:
//     int robber(vector<int>& nums, int l, int r) {
//         int pre = 0, cur = 0;
//         for (int i = l; i <= r; i++) {
//             int temp = max(pre + nums[i], cur);
//             pre = cur;
//             cur = temp;
//         }
//         return cur;
//     }
// };

int rob(vector<int> &nums)
{

    if (nums.size() == 0)
        return 0;
    if (nums.size() == 1)
        return nums[0];

    if (nums.size() == 2)
        return max(nums[0], nums[1]);

    int r1 = 0, r2, now;
    r2 = nums[0];
    for (size_t i = 1; i < nums.size() - 1; i++)
    {
        now = max(r1 + nums[i], r2);
        r1 = r2;
        r2 = now;
    }
    int now1;
    r1 = 0;
    r2 = nums[1];
    for (size_t i = 2; i < nums.size(); i++)
    {
        now1 = max(r1 + nums[i], r2);
        r1 = r2;
        r2 = now1;
    }
    return max(now, now1);
}

int main()
{
    vector<int> nums = {0, 0};
    cout << rob(nums) << endl;
}