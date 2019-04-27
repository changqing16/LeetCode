#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n, m, l;
bool flag;
int go[][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
char **bb;
char *str;

void DFS(int x, int y, int time)
{
    if (flag)
        return;
    int nx, ny;
    for (int i = 0; i < 4; i++)
    {
        nx = x + go[i][0];
        ny = y + go[i][1];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m)
            continue;
        if (bb[nx][ny] != str[time])
            continue;
        if (time == l - 1)
        {
            flag = true;
            return;
        }
        bb[nx][ny] ^= 128;
        DFS(nx, ny, time + 1);
        bb[nx][ny] ^= 128;
    }
    return;
}

bool exist(char **board, int boardRowSize, int boardColSize, char *word)
{
    n = boardRowSize;
    m = boardColSize;
    l = strlen(word);
    if (l == 1)
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (board[i][j] == word[0])
                    return true;
        return false;
    }

    bb = board;
    str = word;
    flag = false;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == word[0])
            {
                board[i][j] ^= 128;
                DFS(i, j, 1);
                board[i][j] ^= 128;
            }
            if (flag)
                return true;
        }
    return false;
}

int main()
{
    char *board[] = {"ABCE", "SFCS", "ADEE"};

    char *word = "ABCB";
    if (exist(board, 2, 30, word) == true)
        printf("true\n");
    else
        printf("false\n");
    return 0;
}