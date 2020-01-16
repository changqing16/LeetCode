#include <iostream>

#include <vector>
using namespace std;

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
    return dfs(maxChoosableInteger, desiredTotal, mem, 0);
}

bool dfs(int M, int T, vector<char> &mem, int k)
{
    if (T <= 0)
        return false;
    if (mem[k] != 0)
        return mem[k] - 1;
    for (int i = 0; i <= M; i++)
    {
        if (!(k & 1 << i) && !dfs(M, T - i - 1, mem, k | (1 << i)))
            return mem[k] = true;
    }
    return mem[k] = false;
}