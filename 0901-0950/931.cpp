#include <iostream>
#include <vector>

using namespace std;

int minFallingPathSum(vector<vector<int>> &A)
{
    vector<int> dp(A.size() + 2);
    dp[0] = 1000000;
    dp[A.size() + 1] = dp[0];
    for (int i = 0; i < A.size(); i++)
    {
        dp[i + 1] = A[0][i];
    }
    int prev, tmp;
    for (int i = 1; i < A.size(); i++)
    {
        prev = 1000000;
        for (int j = 1; j <= A.size(); j++)
        {
            tmp = dp[j];
            prev = min(prev, dp[j]);
            dp[j] = min(prev, dp[j + 1]) + A[i][j - 1];
            prev = tmp;
        }
    }
    int ans = 1000000;
    for (int i = 1; i <= A.size(); i++)
    {
        ans = min(ans, dp[i]);
    }
    return ans;
}