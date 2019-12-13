#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
int coinChange(vector<int> &coins, int amount)
{
    sort(coins.begin(), coins.end());
    vector<int> result(amount + 1, amount + 1);
    result[0] = 0;

    for (int i = 1; i <= amount; i++)
        for (int j = 0; j < coins.size() && coins[j] <= i; j++)
            result[i] = min(result[i], result[i - coins[j]] + 1);

    if (result[amount] > amount)
        return -1;
    else
        return result[amount];
}
// int coinChange(vector<int> &coins, int amount) //基于coins而不是amount
// {
//     vector<int> A(amount + 1, amount + 1);
//     A[0] = 0;
//     for (int coin : coins)
//     {
//         for (int i = coin; i <= amount; i++)
//         {
//             A[i] = min(A[i], A[i - coin] + 1);
//         }
//     }
//     return A[amount] > amount ? -1 : A[amount];
// }

int main()
{
    vector<int> coins = {1, 2, 5};
    cout << coinChange(coins, 11) << endl;
}