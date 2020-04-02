#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

string generateTheString(int n)
{
    char str[n + 1];
    str[n] = 0;
    if (n % 2 == 0)
    {
        for (int i = 0; i < n - 1; i++)
        {
            str[i] = 'a';
        }
        str[n - 1] = 'b';
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            str[i] = 'a';
        }
    }
    string ans = str;
    return ans;
}

int main()
{
    cout << generateTheString(4) << endl;
    return 0;
}