#include <iostream>
#include <vector>

using namespace std;

int numSquares(int n)
{
    vector<int> square;
    int num = 0;
    for (int i = 1; num <= n; i++)
    {
        square.push_back(num);
        num = i * i;
    }

    vector<int> result(n + 1);
    result[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        result[i] = i;
        for (int j = 1; j < square.size() && square[j] <= i; j++)
            result[i] = min(result[i], result[i - square[j]] + 1);
    }
    return result[n];
}

int main()
{
    cout << numSquares(13) << endl;
}
