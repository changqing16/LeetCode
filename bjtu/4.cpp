#include <cmath>
#include <iostream>
using namespace std;

int arr[100];

int s(int x)
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
    int a, b, c;
    int count;
    int ans = 10;
    while (cin >> a >> b >> c)
    {
        count = 0;
        for (int i = 1; i <= 81; i++)
        {
            ans = b * pow(i, a) + c;
            if (s(ans) == i)
                arr[count++] = ans;
        }
        cout << count << endl;
        for (int i = 0; i < count; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    return 0;
}
