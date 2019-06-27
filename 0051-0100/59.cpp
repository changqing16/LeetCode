#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generateMatrix(int n)
{
    vector<vector<int>> ans(n, vector<int>(n));
    int x = 0, y = 0;
    int xMin = 0, xMax = n - 1, yMin = 0, yMax = n - 1;

    int index = 1;

    while (xMin < xMax && yMin < yMax)
    {
        while (x < xMax)
            ans[y][x++] = index++;

        while (y < yMax)
            ans[y++][x] = index++;

        while (x > xMin)
            ans[y][x--] = index++;

        while (y > yMin)
            ans[y--][x] = index++;
        xMin++;
        yMin++;
        xMax--;
        yMax--;
        x++;
        y++;
    }
    if (ans[x][y] == 0)
        ans[x][y] = index++;
    return ans;
}

int main()
{
    vector<vector<int>> ans;
    for (int i = 3; i < 6; i++)
    {
        ans = generateMatrix(i);
        for (int j = 0; j < i; j++)
        {
            for (int k = 0; k < i; k++)
            {
                cout << ans[j][k] << ",";
            }
            cout << endl;
        }
    }
}