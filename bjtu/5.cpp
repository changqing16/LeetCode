#include <limits.h>
#include <math.h>
#include <stdio.h>
int s(long x)
{
    int sum = 0;
    while (x > 0)
    {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}

int main()
{
    int n, d, m, k;
    int total;
    long mm, ans;
    while (scanf("%d%d%d%d", &n, &d, &m, &k) != EOF)
    {
        total = 0;
        mm = pow(10, n);
        for (int i = 0; i <= INT_MAX; i++)
        {
            ans = m * i + k;
            if (ans >= mm)
                break;
            if (s(ans) <= d)
                total++;
        }
        printf("%d\n", total);
    }
    return 0;
}