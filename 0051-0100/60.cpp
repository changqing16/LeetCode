#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int help[9] = {1, 2, 6, 24, 120, 720, 5040, 40320, 362880};

void change(int rest, int n, char ans[]);

string getPermutation(int n, int k)
{
    if (n == 1)
        return "1";
    char ans[n + 1];
    ans[n] = 0;
    k--;
    int first = k / help[n - 2] + 1;
    int rest = k % help[n - 2];
    ans[0] = first + '0';
    for (int i = 1; i < n; i++)
    {
        if (i >= first)
            ans[i] = i + '1';
        else
            ans[i] = i + '0';
    }
    change(rest, n - 1, &ans[1]);
    return string(ans);
}

void change(int rest, int n, char ans[])
{
    if (n == 1)
        return;
    int loc = rest / help[n - 2];
    int k = rest % help[n - 2];
    int tmp = ans[loc];
    for (int i = loc; i > 0; i--)
    {
        ans[i] = ans[i - 1];
    }
    ans[0] = tmp;
    change(k, n - 1, &ans[1]);
}

int main()
{
    cout << getPermutation(5, 76) << endl;
    return 0;
}