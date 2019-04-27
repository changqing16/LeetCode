#include <iostream>
using namespace std;

int main()
{
    int n;
    int n1, n2, tmp;
    while (cin >> n)
    {
        n1 = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> tmp;
            if (tmp == 1)
                n1++;
        }
        n2 = n - n1;
        if (n1 >= n2)
            cout << n2 + (n1 - n2) / 3 << endl;
        else
            cout << n1 << endl;
    }
    return 0;
}