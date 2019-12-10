#include <iostream>
#include <vector>

using namespace std;

int maximalSquare(vector<vector<char>> &matrix)
{
    if (matrix.empty())
        return 0;
    int m = matrix.size(), n = matrix[0].size(), sz = 0, pre, temp;
    vector<int> cur(n, 0);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            temp = cur[j];
            if (!i || !j || matrix[i][j] == '0')
                cur[j] = matrix[i][j] - '0';

            else
                cur[j] = min(pre, min(cur[j], cur[j - 1])) + 1; //只用一个矩阵，牛逼！现在的cur[j]其实是上次的值，也就是A[i-1,j]的值

            sz = max(cur[j], sz); //用pre保存cur[j]的值就不难理解了，现在temp相当于cur[i-1,j]的值，再将temp赋值给pre，
            pre = temp;           //在下次迭代时pre相当于A[i-1,j-1]的值
        }
    }
    return sz * sz;
}