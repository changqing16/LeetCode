#include <iostream>

using namespace std;
int numTrees(int n)
{
    int help[1000];
    help[0] = help[1] = 1;
    help[2] = 2;
    for (int i = 3; i <= n; i++)
    {
        help[i] = 0;
        for (int j = 0; j < i; j++)
            help[i] += help[j] * help[i - j - 1];
    }
    return help[n];
}

int main()
{
    cout << numTrees(4) << endl;
}