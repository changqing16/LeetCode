#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int numIslands(vector<vector<char>> &grid)
{
    queue<pair<int, int>> todo;
    vector<int> offsets = {0, 1, 0, -1, 0};
    int ans = 0, curx, cury, tmpx, tmpy;
    int m = grid.size();
    int n = m ? grid[0].size() : 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == '1')
            {
                todo.push({i, j});
                grid[i][j] = '0';
                ans++;
                while (!todo.empty())
                {
                    curx = todo.front().first;
                    cury = todo.front().second;
                    todo.pop();
                    for (int k = 0; k < 4; k++)
                    {
                        tmpx = curx + offsets[k];
                        tmpy = cury + offsets[k + 1];
                        if (tmpx >= 0 && tmpx < m && tmpy >= 0 && tmpy < n && grid[tmpx][tmpy] == '1')
                        {
                            grid[tmpx][tmpy] = '0';
                            todo.push({tmpx, tmpy});
                        }
                    }
                }
            }
        }
    }
    return ans;
}