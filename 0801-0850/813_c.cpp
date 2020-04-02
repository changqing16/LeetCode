#include <iostream>
#include <vector>

using namespace std;
double largestSumOfAverages(vector<int> &A, int K)
{
    vector<int> sum(A.size() + 1);
    for (int i = 0; i < A.size(); i++)
        sum[i + 1] = sum[i] + A[i];
    vector<double> dp(A.size(), 0);

    for (int groups = 1; groups <= K; groups++)
    {
        for (int s = 0; s + groups <= A.size(); s++)
        {
            if (groups == 1)
            {
                dp[s] = (double)(sum.back() - sum[s]) / (sum.size() - s - 1);
                continue;
            }
            for (int e = s; e + groups <= A.size(); e++)
            {
                dp[s] = max(dp[s], dp[e + 1] + (double)(sum[e + 1] - sum[s]) / (e - s + 1));
            }
        }
    }
    return dp[0];
}
int main()
{
    vector<int> ans = {9, 1, 2, 3, 9};
    cout << largestSumOfAverages(ans, 3) << endl;
}