#include <iostream>
#include <vector>
using namespace std;

int minPathSum(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    int help[n][m];
    int i, j;
    help[0][0] = grid[0][0];
    for (i = 1; i < n; i++)
        help[i][0] = grid[i][0] + help[i - 1][0];

    for (i = 1; i < m; i++)
        help[0][i] = grid[0][i] + help[0][i - 1];

    for (i = 1; i < n; i++)
        for (j = 1; j < m; j++)
        {
            help[i][j] = min(help[i - 1][j], help[i][j - 1]) + grid[i][j];
        }
    return help[n - 1][m - 1];
}

int main()
{
    vector<vector<int>> ans(3, vector<int>(3));
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            ans[i][j] = 0;
        }
    }
    ans[1][1] = 1;
    cout << minPathSum(ans) << endl;
}