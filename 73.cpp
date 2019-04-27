#include <iostream>
#include <vector>

using namespace std;

void setZeroes(vector<vector<int>> &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();
    bool row[m];
    bool col[n];
    for (int i = 0; i < m; i++)
        row[i] = false;
    for (int j = 0; j < n; j++)
        col[j] = false;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (matrix[i][j] == 0)
            {
                row[i] = true;
                col[j] = true;
            }
    for (int i = 0; i < m; i++)
        if (row[i])
            for (int j = 0; j < n; j++)
                matrix[i][j] = 0;

    for (int i = 0; i < n; i++)
        if (col[i])
            for (int j = 0; j < m; j++)
                matrix[j][i] = 0;
}