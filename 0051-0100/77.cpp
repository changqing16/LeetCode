#include <iostream>
#include <vector>

using namespace std;

void func(vector<vector<int>> &ans, int arr[], int n, int k, int pt)
{
    arr[k] = pt;
    if (k == 1)
    {
        vector<int> tmp(arr + 1, arr + arr[0] + 1);
        ans.push_back(tmp);
        return;
    }
    k--;
    for (int i = pt + 1; i <= n - k + 1; i++)
        func(ans, arr, n, k, i);
}

vector<vector<int>> combine(int n, int k)
{
    vector<vector<int>> ans;
    vector<int> now;
    int arr[k + 1];
    arr[0] = k;
    for (int i = 1; i <= n - k + 1; i++)
        func(ans, arr, n, k, i);

    return ans;
}

int main()
{
    vector<vector<int>> ans = combine(4, 2);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << ",";
        }
        cout << endl;
    }
}

// vector<vector<int>> combine(int n, int k)
// {
//     vector<vector<int>> result;
//     int i = 0;
//     vector<int> p(k, 0);
//     while (i >= 0)
//     {
//         p[i]++;
//         if (p[i] > n)
//             --i;
//         else if (i == k - 1)
//             result.push_back(p);
//         else
//         {
//             ++i;
//             p[i] = p[i - 1];
//         }
//     }
//     return result;
// }
