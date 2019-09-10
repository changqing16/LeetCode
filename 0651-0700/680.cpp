#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

bool validP(char *str, int start, int end)
{
    while (start++ < end--)
    {
        if (str[start] != str[end])
            return false;
    }
    return true;
}

bool validPalindrome(char *s)
{

    int start = -1, end = strlen(s);
    while (start++ < end--)
    {
        if (s[start] != s[end])
            return validP(s, start - 1, end) || validP(s, start, end + 1);
    }
    return true;
}

int main()
{
    char *s = "abcca";
    cout << validPalindrome(s) << endl;
}