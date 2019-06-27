#include <cstring>
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

string convert(string s, int numRows)
{
    int size = s.size();
    char res[size + 1];
    if (numRows == 1)
        return s;
    int len = 0;
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0, k = i; k < size; j++)
        {
            res[len++] = s[k];
            k += ((i == 0 || (j % 2 == 0)) && (i != numRows - 1)) ? 2 * (numRows - i - 1) : 2 * i;
        }
    }
    res[size] = '\000';//c++的char机制呀
    return res;
}

int main()
{
    string s = "oqmsboagu";
    string ans = convert(s, 9);
    cout << ans << endl;
}