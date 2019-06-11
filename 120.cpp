#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int minimumTotal(vector<vector<int>> &triangle)
{
    int n = triangle.size();
    for (int i = 1; i < n; i++)
    {
        triangle[i][i] = triangle[i - 1][i - 1] + triangle[i][i];
        for (int j = i - 1; j > 0; j--)
        {
            triangle[i][j] = min(triangle[i - 1][j], triangle[i - 1][j - 1]) + triangle[i][j];
        }
        triangle[i][0] = triangle[i - 1][0] + triangle[i][0];
    }
    return *min_element(triangle[n - 1].begin(), triangle[n - 1].end());
}