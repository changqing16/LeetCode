#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int rows = matrix.size();
    if (rows == 0 || matrix[0].size() == 0)
        return false;
    int cols = matrix[0].size();
    int help[rows];
    for (int i = 0; i < rows; i++)
        help[i] = matrix[i][0];
    int pos = lower_bound(help, help + rows, target) - help;
    if (pos < rows && help[pos] == target)
        return true;
    if (pos != 0)
    {
        pos -= 1;
        if (binary_search(matrix[pos].begin(), matrix[pos].end(), target))
            return true;
    }

    auto it = lower_bound(matrix[0].begin(), matrix[0].end(), target);
    pos = distance(matrix[0].begin(), it);
    if (pos < cols && matrix[0][pos] == target)
        return true;

    if (pos != 0)
    {
        pos -= 1;
        for (int i = 0; i < rows; i++)
            help[i] = matrix[i][pos];
        if (binary_search(help, help + rows, target))
            return true;
    }
    return false;
}

int main()
{
    vector<vector<int>> matrix = {{1, 3, 5, 7, 9}, {2, 4, 6, 8, 10}, {11, 13, 15, 17, 19}, {12, 14, 16, 18, 20}, {21, 22, 23, 24, 25}};
    cout << searchMatrix(matrix, 13) << endl;
    cout << searchMatrix(matrix, 12) << endl;
    cout << searchMatrix(matrix, 33) << endl;
}