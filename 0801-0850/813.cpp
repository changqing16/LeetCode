#include <iostream>
#include <vector>

using namespace std;

double dfs(vector<int> &sum, int c, int k, vector<vector<double>> &dp)
{
    if (k == 0)
    {
        return (double)(sum.back() - sum[c]) / (sum.size() - c - 1);
    }
    if (dp[c][k] != 0)
        return dp[c][k];
    for (int i = c; i < sum.size() - k - 1; i++)
    {
        dp[c][k] = max(dp[c][k], (double)(sum[i + 1] - sum[c]) / (i - c + 1) + dfs(sum, i + 1, k - 1, dp));
    }
    return dp[c][k];
}

double largestSumOfAverages(vector<int> &A, int K)
{
    vector<int> sum(A.size() + 1);
    sum[0] = 0;
    for (int i = 0; i < A.size(); i++)
    {
        sum[i + 1] = sum[i] + A[i];
    }
    vector<vector<double>> dp(A.size(), vector<double>(A.size(), 0));
    return dfs(sum, 0, K - 1, dp);
}

int main()
{
    vector<int> ans = {9, 1, 2, 3, 9};
    cout << largestSumOfAverages(ans, 3) << endl;
}