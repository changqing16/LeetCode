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
    vector<vector<int>> help(A.size(), vector<int>(A.size(), 2));

    unordered_map<int, int> um;
    for (int i = 0; i < A.size(); i++)
    {
        um[A[i]] = i;
    }
    int ans = 0;

    for (int i = 0; i < A.size() - 2; i++)
    {
        for (int j = i + 1; j < A.size() - 1; j++)
        {
            auto it = um.find(A[i] + A[j]);
            if (it != um.end())
            {
                help[j][it->second] = help[i][j] + 1;
                ans = max(ans, help[j][it->second]);
            }
        }
    }
    if (ans < 3)
        return 0;

    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8};
    cout << lenLongestFibSubseq(nums) << endl;
}