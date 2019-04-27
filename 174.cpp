#include <iostream>
#include <vector>

using namespace std;

// #define FUNC(arr1, arr2, x, y)                    \
//     do                                            \
//     {                                             \
//         arr1[i][j] = dungeon[i][j] + arr1[x][y];  \
//         arr2[i][j] = min(arr1[i][j], arr2[x][y]); \
//     } while (0)

#define print(arr, n, m)                  \
    do                                    \
    {                                     \
        for (int i = 0; i < n; i++)       \
        {                                 \
            for (int j = 0; j < m; j++)   \
                cout << arr[i][j] << ","; \
            cout << endl;                 \
        }                                 \
    } while (0);

int calculateMinimumHP(vector<vector<int>> &dungeon)
{
    int n = dungeon.size();
    int m = dungeon[0].size();
    int help[n][m];
    int help1[n][m];
    int ans[n][m];
    int ans1[n][m];
    int i, j, x, y;

    help[0][0] = help1[0][0] = ans[0][0] = ans1[0][0] = dungeon[0][0];
    for (i = 1; i < n; i++)
    {
        help[i][0] = help1[i][0] = dungeon[i][0] + help[i - 1][0];
        ans[i][0] = ans1[i][0] = min(help[i][0], ans[i - 1][0]);
    }
    for (i = 1; i < m; i++)
    {
        help[0][i] = help1[0][i] = dungeon[0][i] + help[0][i - 1];
        ans[0][i] = ans1[0][i] = min(help[0][i], ans[0][i - 1]);
    }
    for (i = 1; i < n; i++)
    {
        for (j = 1; j < m; j++)
        {
            if (help1[i - 1][j] > help1[i][j - 1])
            {
                x = i - 1;
                y = j;
            }
            else
            {
                x = i;
                y = j - 1;
            }
            // FUNC(help1, ans1, x, y);
            help1[i][j] = dungeon[i][j] + help1[x][y];
            ans1[i][j] = min(help1[i][j], ans1[x][y]);

            int tmp1 = dungeon[i][j] + help[i - 1][j];
            int max1 = min(tmp1, ans[i - 1][j]);
            int tmp2 = dungeon[i][j] + help[i][j - 1];
            int max2 = min(tmp2, ans[i][j - 1]);
            if (max1 > max2)
            {
                help[i][j] = tmp1;
                ans[i][j] = max1;
            }
            else
            {
                help[i][j] = tmp2;
                ans[i][j] = max2;
            }

            // if (ans[i - 1][j] > ans[i][j - 1])
            // {
            //     help[i][j] = dungeon[i][j] + help[i - 1][j];
            //     ans[i][j] = min(help[i][j], ans[i - 1][j]);
            // }
            // else if (ans[i - 1][j] < ans[i][j - 1])
            // {
            //     help[i][j] = dungeon[i][j] + help[i][j - 1];
            //     ans[i][j] = min(help[i][j], ans[i][j - 1]);
            // }
            // else
            // {
            //     if (help[i - 1][j] > help[i][j - 1])
            //     {
            //         help[i][j] = dungeon[i][j] + help[i - 1][j];
            //         ans[i][j] = min(help[i][j], ans[i - 1][j]);
            //     }
            //     else
            //     {
            //         help[i][j] = dungeon[i][j] + help[i][j - 1];
            //         ans[i][j] = min(help[i][j], ans[i][j - 1]);
            //     }
            //}
        }
    }

    print(help, n, m);
    print(ans, n, m);
    print(help1, n, m);
    print(ans1, n, m);

    int a = max(ans[n - 1][m - 1], ans1[n - 1][m - 1]);

    if (a >= 0)
        return 1;
    else
        return 1 - a;
}

int main()
{
    vector<vector<int>> ans = {{1, 2, 1}, {-2, -3, -3}, {3, 2, -2}};
    cout << calculateMinimumHP(ans) << endl;
    return 0;
}