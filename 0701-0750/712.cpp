#include <iostream>
#include <string>
#include <vector>

using namespace std;

int minimumDeleteSum(string s1, string s2)
{
    if (s1.size() < s2.size())
    {
        string tmp = s1;
        s1 = s2;
        s2 = tmp;
    }

    vector<int> hp(s2.size() + 1);
    hp[s2.size()] = 0;

    int cur = 0, prev, tmp;
    for (int i = s2.size() - 1; i >= 0; i--)
    {
        cur += s2[i];
        hp[i] = cur;
    }
    cur = 0;
    for (int i = s1.size() - 1; i >= 0; i--)
    {
        prev = cur;
        cur += s1[i];
        hp[s2.size()] = cur;
        for (int j = s2.size() - 1; j >= 0; j--)
        {
            tmp = hp[j];
            if (s1[i] == s2[j])
                hp[j] = prev;
            else
                hp[j] = min(hp[j] + s1[i], hp[j + 1] + s2[j]);
            prev = tmp;
        }
    }
    return hp[0];

    // vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1));
    // dp[s1.size()][s2.size()] = 0;
    // int sum = 0;
    // for (int i = s1.size() - 1; i >= 0; i--)
    // {
    //     sum += s1[i];
    //     dp[i][s2.size()] = sum;
    // }
    // sum = 0;
    // for (int j = s2.size() - 1; j >= 0; j--)
    // {
    //     sum += s2[j];
    //     dp[s1.size()][j] = sum;
    // }
    // for (int i = s1.size() - 1; i >= 0; i--)
    // {
    //     for (int j = s2.size() - 1; j >= 0; j--)
    //     {
    //         if (s1[i] == s2[j])
    //             dp[i][j] = dp[i + 1][j + 1];
    //         else
    //             dp[i][j] = min(dp[i + 1][j] + s1[i], dp[i][j + 1] + s2[j]);
    //     }
    // }
    // return dp[0][0];
}

int main()
{
    string s1 = "ccaccjp";
    string s2 = "fwosarcwge";
    cout << minimumDeleteSum(s1, s2) << endl;
    return 0;
}