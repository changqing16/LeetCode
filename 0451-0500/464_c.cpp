#include <iostream>

#include <vector>
using namespace std;
bool dfs(int M, int T, int k, vector<char> &mem)
{
    if (T <= 0)
        return false;
    if (mem[k] != 0)
        return mem[k] - 1;
    for (int i = 0; i < M; i++)
    {
        if (!(k & 1 << i) && !dfs(M, T - i - 1, k | (1 << i), mem))
            return mem[k] = true;
    }
    return mem[k] = false;
}

bool canIWin(int maxChoosableInteger, int desiredTotal)
{
    int sum = maxChoosableInteger * (maxChoosableInteger + 1) / 2;
    if (maxChoosableInteger >= desiredTotal)
        return true;
    if (sum < desiredTotal)
        return false;
    if (sum == desiredTotal)
        return sum % 2;
    vector<char> mem(1 << (maxChoosableInteger + 1), 0);
    return dfs(maxChoosableInteger, desiredTotal, 0, mem);
}

int main()
{
    cout << canIWin(10, 40) << endl;
}