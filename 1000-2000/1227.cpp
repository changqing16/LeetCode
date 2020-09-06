#include <iostream>
#include <vector>
using namespace std;

int countSquares(vector<vector<int>> &matrix)
{
    int ans = 0;
    int m = matrix.size();
    int n = matrix[0].size();
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (matrix[i][j] == 1 && i > 0 && j > 0)
                matrix[i][j] = min(matrix[i - 1][j - 1], min(matrix[i - 1][j], matrix[i][j - 1])) + 1;

            ans += matrix[i][j];
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>> matrix = {{1, 0, 1}, {1, 1, 0}, {1, 1, 0}};
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            cout << matrix[i][j] << ",";
        }
        cout << endl;
    }
    cout << countSquares(matrix) << endl;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            cout << matrix[i][j] << ",";
        }
        cout << endl;
    }
}