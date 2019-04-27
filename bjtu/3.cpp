#include <iostream>

using namespace std;
int main()
{
    int n;
    int total = 0, cur;
    while (cin >> n)
    {
        total = 0;
        while (n >= 5)
        {
            cur = n / 5;
            total += cur;
            n = n - cur * 3;
        }
        cout << total << endl;
    }
    return 0;
}