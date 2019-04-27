#include <iostream>

using namespace std;

#define M 199

int all[M][M];
bool flag = false;

void init()
{
    int i, j;
    for (i = 1; i < M; i++)
    {
        all[i][0] = 1;
        all[i][1] = i;
        all[i][i] = 1;
    }

    for (i = 2; i < M - 1; i++)
    {
        for (j = 2; j < i; j++)
        {
            all[i][j] = all[i - 1][j] + all[i - 1][j - 1];
        }
    }
}

int uniquePaths(int n, int m)
{
    if (!flag)
    {
        flag = true;
        init();
    }
    return all[m + n - 2][n - 1];
}

int main()
{
    cout << uniquePaths(2, 3) << endl;
    cout << all[3][1] << endl;
    cout << all[5][2] << endl;
}