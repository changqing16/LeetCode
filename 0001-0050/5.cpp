#include <cstring>
#include <iostream>
#include <string>
using namespace std;
string longestPalindrome(string s)
{
    int size = s.size();
    if (size == 1)
        return s;

    char str[size];
    strcpy(str, s.c_str());
    int before, after, count, ans = 0;
    int start;
    bool flag;
    for (int i = 1; i < size; i++)
    {
        count = 1;
        if (str[i] == str[i - 1])
        {
            before = i - 2;
            count = 2;
            flag = true;
        }
        else
        {
            before = i - 1;
            flag = false;
        }
        after = i + 1;
        while (before >= 0 && after < size)
        {
            if (str[before] == str[after])
                count += 2;
            else
                break;
            if (flag && str[before + 1] != str[after])
                flag = false;
            before--;
            after++;
        }

        if (flag && after < size && str[before + 1] == str[after])
        {
            after++;
            count++;
            while (before >= 0 && after < size)
            {
                if (str[before] == str[after])
                    count += 2;
                else
                    break;
                before--;
                after++;
            }
        }

        if (count > ans)
        {
            ans = count;
            start = before + 1;
        }
    }
    return s.substr(start, ans);
}

int main()
{
    string s = "sssooosss";
    string ans = longestPalindrome(s);
    cout << ans << endl;
}