#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int integerBreak(int n)
{
    vector<int> ans(n + 1);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i / 2; j++)
        {
            ans[i] = max(ans[i], max(j, ans[j]) * max(i - j, ans[i - j]));
        }
    }
    return ans[n];
}

// int integerBreak(int n) //尽可能多的3 O(log(n))
// {
//     if (n == 2)
//         return 1;
//     if (n == 3)
//         return 2;
//     int num_3 = (int)n / 3;
//     int remainder = n % 3;
//     if (remainder == 1)
//     {
//         remainder = 4;
//         num_3--;
//     }
//     else if (remainder == 0)
//         remainder = 1;
//     return (int)pow(3, num_3) * remainder;
// }

int main()
{
    cout << integerBreak(10) << endl;
}