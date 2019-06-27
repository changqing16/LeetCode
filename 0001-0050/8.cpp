#include <cstring>
#include <stdio.h>
#include <string>
using namespace std;

int myAtoi(string str)
{
    int size = str.size();
    if (size == 0)
        return 0;
    char ans[size];
    bool positive = true, first = false;
    int len = 0;
    for (int i = 0; i < size; i++)
    {
        if (!first)
        {
            if (str[i] == '-' || str[i] == '+')
            {
                first = true;
                positive = str[i] == '+' ? true : false;
            }
            else if (str[i] > 47 && str[i] < 58)
            {
                first = true;
                ans[len++] = str[i];
            }
            else
                return 0;
        }
        else
        {
            if (str[i] > 47 && str[i] < 58)
                ans[len++] = str[i];
            else
                break;
        }
    }

    if (len > 10)
    {
        if (positive)
            return INT_MAX;
        else
            return INT_MIN;
    }

    long long last = 0;
    long long c = 1;

    for (int i = len - 1; i >= 0; i--)
    {
        last += (ans[i] - '0') * c;
        if (last > INT_MAX)
            break;
        c *= 10;
    }
    if (positive)
    {
        if (last > INT_MAX)
            return INT_MAX;
        else
            return last;
    }
    else
    {
        last *= -1;
        if (last < INT_MIN)
            return INT_MIN;
        else
            return last;
    }
}

int main()
{
    char str[20];
    while (scanf("%s", str) != EOF)
    {
        int ans = myAtoi(str);
        printf("%d\n", ans);
    }
}