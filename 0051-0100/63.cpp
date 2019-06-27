#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
    int n = obstacleGrid.size();
    int m = obstacleGrid[0].size();
    if (obstacleGrid[0][0] == 1 || obstacleGrid[n - 1][m - 1] == 1)
        return 0;

    int help[n][m];
    int i, j;
    memset(help, 0, sizeof help);
    help[0][0] = 1;
    for (i = 1; i < n; i++)
        if (obstacleGrid[i][0] == 0)
            help[i][0] = help[i - 1][0];

    for (i = 1; i < m; i++)
        if (obstacleGrid[0][i] == 0)
            help[0][i] = help[0][i - 1];

    for (i = 1; i < n; i++)
        for (j = 1; j < m; j++)
        {
            if (obstacleGrid[i][j] == 0)
                help[i][j] = help[i - 1][j] + help[i][j - 1];
            else
                help[i][j] = 0;
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
    cout << uniquePathsWithObstacles(ans) << endl;
}