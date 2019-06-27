#include <iostream>
#include <vector>
using namespace std;

void rotate(vector<vector<int>> &matrix) //先转置再前后列交换
{
    int n = matrix.size();
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
            swap(matrix[i][j], matrix[j][i]);
    for (int j = 0; j < n / 2; j++)
        for (int i = 0; i < n; i++)
        {
            printf("(%d,%d) to (%d,%d)\n", i, j, i, n - 1 - j);
            swap(matrix[i][j], matrix[i][n - 1 - j]);
        }
}

void print(vector<vector<int>> &matrix)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix.size(); j++)
        {
            printf("%2d,", matrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int tmp = 1;
    vector<vector<int>> ans;
    for (int i = 0; i < 4; i++)
    {
        ans.push_back(vector<int>());
        for (int j = 0; j < 4; j++)
        {
            ans[i].push_back(tmp++);
        }
    }
    print(ans);
    rotate(ans);
    print(ans);
}