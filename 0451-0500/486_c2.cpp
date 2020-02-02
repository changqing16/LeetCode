#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

//都是很朴素的思想，我为什么就想不到呢

int utill(vector<int> &v, vector<vector<int>> &dp, int i, int j)
{
    if (i > j)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];

    int a = v[i] + min(utill(v, dp, i + 1, j - 1), utill(v, dp, i + 2, j));
    int b = v[j] + min(utill(v, dp, i, j - 2), utill(v, dp, i + 1, j - 1));

    dp[i][j] = max(a, b);
    return dp[i][j];
}

bool PredictTheWinner(vector<int> &nums)
{
    int len = nums.size();
    vector<vector<int>> dp(len, vector<int>(len, -1));

    int myBest = utill(nums, dp, 0, len - 1);
    return 2 * myBest >= accumulate(nums.begin(), nums.end(), 0);
}

int main()
{
}