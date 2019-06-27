#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int x;
int y;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
queue<pair<int, int>> Q;

void bfs(int a, int b, vector<vector<char>> &board)
{
    int curx, cury;
    if (board[a][b] == 'O')
    {
        Q.push({a, b});
        board[a][b] = '1';
        while (!Q.empty())
        {
            a = Q.front().first;
            b = Q.front().second;
            Q.pop();
            for (int k = 0; k < 4; k++)
            {
                curx = a + dx[k];
                cury = b + dy[k];
                if (curx >= 0 && curx < x && cury >= 0 && cury < y && board[curx][cury] == 'O')
                {
                    Q.push({curx, cury});
                    board[curx][cury] = '1';
                }
            }
        }
    }
}

void solve(vector<vector<char>> &board)
{
    x = board.size();
    if (x == 0)
        return;
    y = board[0].size();

    bool **help = new bool *[x];
    help[0] = new bool[x * y];
    for (int i = 1; i < x; i++)
        help[i] = help[i - 1] + y;

    for (int i = 0; i < x; i++)
        for (int j = 0; j < y; j++)
            help[i][j] = false;

    for (int i = 0; i < x; i++)
    {
        bfs(i, 0, board);
        bfs(i, y - 1, board);
    }
    for (int i = 0; i < y; i++)
    {
        bfs(0, i, board);
        bfs(x - 1, i, board);
    }
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            if (board[i][j] == '1')
                board[i][j] = 'O';
            else
                board[i][j] = 'X';
        }
    }
}