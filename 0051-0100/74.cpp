#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int rows = matrix.size();
    if (rows == 0 || matrix[0].size() == 0)
        return false;

    int help[rows];
    for (int i = 0; i < rows; i++)
        help[i] = matrix[i][0];
    int pos = lower_bound(help, help + rows, target) - help;
    if (pos < rows && help[pos] == target)
        return true;
    if (pos == 0)
        return false;
    pos -= 1;
    return binary_search(matrix[pos].begin(), matrix[pos].end(), target);
}

int main()
{
    vector<vector<int>> matrix = {{1}};
    cout << searchMatrix(matrix, 1) << endl;
}