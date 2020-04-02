#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool static smaller(vector<int> &A, vector<int> &B)
{
    if (A[1] == B[1])
        return A[0] < B[0];
    return A[1] < B[1];
}

int findLongestChain(vector<vector<int>> &pairs) //贪心，n个候选项，找最短的。
{
    sort(pairs.begin(), pairs.end(), smaller);
    int ans = 1, before = pairs[0][1];
    for (int i = 1; i < pairs.size(); i++)
    {
        if (before < pairs[i][0])
        {
            ans += 1;
            before = pairs[i][1];
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>> pairs = {
        {1, 2},
        {2, 3},
        {3, 4},
        {4, 5},
        {3, 5},
        {2, 5},
        {1, 5},
        {5, 6},
};
cout << findLongestChain(pairs) << endl;
}