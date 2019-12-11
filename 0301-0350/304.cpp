#include <iostream>
#include <vector>

using namespace std;

class NumMatrix
{
private:
    vector<vector<int>> result;

public:
    NumMatrix(vector<vector<int>> &matrix)
    {
        if (matrix.empty())
            return;

        int m = matrix.size();
        int n = matrix[0].size();
        result = vector<vector<int>>(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                result[i][j] = matrix[i - 1][j - 1] + result[i - 1][j] + result[i][j - 1] - result[i - 1][j - 1];
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        return result[row2 + 1][col2 + 1] + result[row1][col1] - result[row1][col2 + 1] - result[row2 + 1][col1];
    }
};

int main()
{
    vector<vector<int>> nums = {
        {3, 0, 1, 4, 2},
        {5, 6, 3, 2, 1},
        {1, 2, 0, 1, 5},
        {4, 1, 0, 1, 7},
        {1, 0, 3, 0, 5}};

    NumMatrix *obj = new NumMatrix(nums);

    cout << obj->sumRegion(2, 1, 4, 3) << endl;
}