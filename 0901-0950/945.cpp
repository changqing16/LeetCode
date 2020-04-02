#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>
using namespace std;
int minIncrementForUnique(vector<int> &A)
{
    if (A.size() < 2)
        return 0;
    sort(A.begin(), A.end());
    int ans = 0, prev = A[0];
    for (int i = 1; i < A.size(); i++)
    {
        if (A[i] <= prev)
        {
            ans += prev + 1 - A[i];
            prev = prev + 1;
        }
        else
            prev = A[i];
    }
    return ans;
}

int main()
{
    vector<int> ans = {1, 2, 2};
    cout << minIncrementForUnique(ans) << endl;
    return 0;
}