#include <algorithm>
#include <climits>
#include <iostream>
using namespace std;

int countPrimes(int n)
{
    if (n == 0)
        return 0;
    int prime[n];
    int primeSize;
    bool mark[n];

    for (int i = 1; i < n; i++)
        mark[i] = false;
    primeSize = 0;
    for (int i = 2; i < n; i++)
    {
        if (mark[i] == true)
            continue;
        prime[primeSize++] = i;
        for (int j = i * i; j < n && i < 46341; j += i)
            mark[j] = true;
    }
    return primeSize;
}
int main()
{
    cout << countPrimes(10) << endl;
    return 0;
}