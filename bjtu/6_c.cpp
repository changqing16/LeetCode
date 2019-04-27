#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
#define N 1000000000
int dp[301][301], sum[301], init[301];

int f(int a[], int x, int y)
{
    int i, res = 0;
    for (i = x; i <= y; i++)
        res += a[i];
    return res;
}
int main()
{
    int n, i, j, m, k, s1, s2;
    cin >> n;
    memset(dp, -1, sizeof(dp));

    for (i = 1; i <= n; i++)
    {
        cin >> init[i];
        sum[i] = sum[i - 1] + init[i];
        dp[i][i] = 0;
    }
    for (m = 1; m < n; m++)
    {
        for (i = 1; i + m <= n; i++)
        {
            j = i + m;
            for (k = i; k < j; k++)
            {
                s1 = f(init, i, k);
                s2 = f(init, k + 1, j);
                if (min(s1, s2) >= 10 && max(s1, s2) % min(s1, s2) == 0)
                    continue;
                else
                {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + sum[j] - sum[i - 1]);
                }
            }
        }
    }
    if (dp[1][n] >= N)
        dp[1][n] = -1;
    cout << dp[1][n] << endl;
    return 0;
}