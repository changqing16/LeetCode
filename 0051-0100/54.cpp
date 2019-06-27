#include <iostream>
#include <vector>

using namespace std;
vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    vector<int> ans;
    if (matrix.size() == 0)
        return ans;
    if (matrix.size() == 1)
        return matrix[0];
    int x = 0, y = 0;
    int xMin = 0, xMax = matrix[0].size() - 1, yMin = 0, yMax = matrix.size() - 1;

    while (xMin < xMax && yMin < yMax)
    {
        while (x < xMax)
            ans.push_back(matrix[y][x++]);

        while (y < yMax)
            ans.push_back(matrix[y++][x]);

        while (x > xMin)
            ans.push_back(matrix[y][x--]);
        while (y > yMin)
            ans.push_back(matrix[y--][x]);
        xMin++;
        yMin++;
        xMax--;
        yMax--;
        x++;
        y++;
    }

    if (ans.size() < matrix.size() * matrix[0].size())
    {
        if (xMin == xMax && yMin == yMax)
            ans.push_back(matrix[y][x]);
        if (xMin < xMax)
            while (x <= xMax)
                ans.push_back(matrix[y][x++]);
        if (yMin < yMax)
            while (y <= yMax)
                ans.push_back(matrix[y++][x]);
    }
    return ans;
}

int main()
{
    vector<vector<int>> test;
    int ss = 1;
    vector<int> tmp1;
    tmp1.push_back(3);
    vector<int> tmp2;
    tmp2.push_back(2);
    test.push_back(tmp1);
    test.push_back(tmp2);
    // for (int i = 0; i < 3; i++)
    // {
    //     vector<int> tmp;
    //     for (int j = 0; j < 4; j++)
    //     {
    //         tmp.push_back(ss++);
    //     }
    //     test.push_back(tmp);
    // }

    vector<int> ans = spiralOrder(test);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << ",";
    }
    cout << endl;

    return 0;
}