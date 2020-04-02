#include <algorithm>
#include <iostream>
#include <iterator>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int lenLongestFibSubseq(vector<int> &A)
{
    vector<vector<int>> dp(A.size(), vector<int>(A.size(), 0));
    int ans = 0;
    for (int i = 1; i < A.size(); i++)
    {
        int l = 0, r = i - 1;
        while (l < r)
        {
            int sum = A[l] + A[r];
            if (sum > A[i])
                r--;
            else if (sum < A[i])
                l++;
            else
            {
                dp[r][i] = dp[l][r] + 1;
                ans = max(ans, dp[r][i]);
                r--;
                l++;
            }
        }
    }

    return ans == 0 ? 0 : ans + 2;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8};
    cout << lenLongestFibSubseq(nums) << endl;
}