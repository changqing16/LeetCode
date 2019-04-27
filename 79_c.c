#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int R, C;
bool help(char **b, int **mark, char *w, int id, int i, int j)
{
    if (mark[i][j] || w[id] != b[i][j])
        return false;
    if (w[id] == b[i][j] && w[id + 1] == '\0')
        return true;
    mark[i][j] = 1;
    bool f = false;
    if (i > 0)
    {
        f = help(b, mark, w, id + 1, i - 1, j);
        if (f)
            return true;
    }
    if (i + 1 < R)
    {
        f = help(b, mark, w, id + 1, i + 1, j);
        if (f)
            return true;
    }
    if (j > 0)
    {
        f = help(b, mark, w, id + 1, i, j - 1);
        if (f)
            return true;
    }
    if (j + 1 < C)
    {
        f = help(b, mark, w, id + 1, i, j + 1);
        if (f)
            return true;
    }
    mark[i][j] = 0;
    return false;
}

bool exist(char **board, int boardRowSize, int boardColSize, char *word)
{
    R = boardRowSize;
    C = boardColSize;
    int **mark = (int **)malloc(sizeof(int *) * boardRowSize);
    for (int k = 0; k < boardRowSize; k++)
        mark[k] = (int *)calloc(boardColSize, sizeof(int));
    for (int i = 0; i < boardRowSize; i++)
    {
        for (int j = 0; j < boardColSize; j++)
        {
            if (word[0] == board[i][j])
            {
                if (help(board, mark, word, 0, i, j))
                    return true;
            }
        }
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