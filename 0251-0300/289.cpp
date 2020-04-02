#include <algorithm>
#include <cstring>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

void gameOfLife(vector<vector<int>> &board)
{
    int n = board.size();
    int m = board[0].size();
    vector<vector<int>> dir = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    int count, curx, cury;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            count = 0;
            for (int k = 0; k < 8; k++)
            {
                curx = i + dir[k][0];
                cury = j + dir[k][1];
                if (curx >= 0 && cury >= 0 && curx < n && cury < m && board[curx][cury] > 0)
                    count++;
            }

            if (board[i][j] == 1 && (count < 2 || count > 3))
                board[i][j] = 2;
            else if (board[i][j] == 0 && count == 3)
                board[i][j] = -1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == -1)
                board[i][j] = 1;
            else if (board[i][j] == 2)
                board[i][j] = 0;
        }
    }
}