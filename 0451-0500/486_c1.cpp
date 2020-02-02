#include <iostream>
#include <vector>
using namespace std;

bool PredictTheWinner(vector<int> &nums)
{
    vector<int> dp(nums.size());
    for (int s = nums.size(); s >= 0; s--)
        for (int e = s + 1; e < nums.size(); e++)
            dp[e] = max(nums[s] - dp[e], nums[e] - dp[e - 1]);
    return dp[nums.size() - 1] >= 0;
}

// public boolean PredictTheWinner(int[] nums) { //dp[i][j]代表此状态此player比对手的多多少
//     int n = nums.length;
//     int[][] dp = new int[n][n];
//     for (int i = 0; i < n; i++) { dp[i][i] = nums[i]; }
//     for (int len = 1; len < n; len++) {
//         for (int i = 0; i < n - len; i++) {
//             int j = i + len;
//             dp[i][j] = Math.max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]);
//         }
//     }
//     return dp[0][n - 1] >= 0;
// }