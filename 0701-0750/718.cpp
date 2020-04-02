#include <iostream>
#include <string>
#include <vector>

using namespace std;
int findLength(vector<int> &A, vector<int> &B)
{
    if (A.size() < B.size())
    {
        vector<int> tmp = A;
        A = B;
        B = tmp;
    }
    vector<int> dp(B.size() + 1, 0);
    int ans = 0, tmp, prev;
    for (int i = A.size() - 1; i >= 0; i--)
    {
        prev = 0;
        for (int j = B.size() - 1; j >= 0; j--)
        {
            tmp = dp[j];
            if (A[i] == B[j])
            {
                dp[j] = prev + 1;
                if (ans < dp[j])
                    ans = dp[j];
            }
            else
                dp[j] = 0;
            prev = tmp;
        }
    }
    return ans;
}

int main()
{
    vector<int> A = {1, 2, 3, 2, 1};
    vector<int> B = {3, 2, 1, 4, 7};
    cout << findLength(A, B) << endl;
}