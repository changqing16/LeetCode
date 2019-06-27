#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int m = matrix.size();
    if (m == 0)
        return false;
    int n = matrix[0].size();

    int i = 0, j = n - 1;
    while (i < m && j >= 0)
    {
        if (matrix[i][j] == target)
            return true;
        else if (matrix[i][j] > target)
            j--;
        else
            i++;
    }
    return false;
}
int main()
{
    vector<vector<int>> matrix = {
        {1, 2, 5, 7, 9},
        {2, 3, 4, 8, 17},
        {10, 11, 13, 15, 19},
        {12, 14, 16, 18, 20},
        {21, 22, 23, 24, 25}};

    cout << searchMatrix(matrix, 13) << endl;
}