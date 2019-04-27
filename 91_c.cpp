#include <string.h>

int numDecodings(char *s)
{
    int len = strlen(s);
    if (s[0] == '0')
        return 0;
    int sub1 = 1;
    int sub2 = 1;
    int tmp;
    for (int i = len - 2; i >= 0; i++)
    {
        if (s[i + 1] == '0')
            sub1 = 0;
        if (s[i] == '1' || s[i] == '2' && s[i + 1] <= '6')
        {
            tmp = sub1;
            sub1 = sub1 + sub2;
            sub2 = tmp;
        }
        else
            sub2 = sub1;
    }
    return sub1;
}