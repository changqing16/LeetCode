#include <iostream>
#include <string>
#include <vector>

using namespace std;

string longestPalindrome(string s)
{
    int len = s.size() * 2 + 3;
    char str[len];
    str[0] = '^';
    str[1] = '#';
    str[s.size() * 2 + 2] = '$';

    for (int i = 0; i < s.size(); i++)
    {
        str[i * 2 + 2] = s[i];
        str[i * 2 + 3] = '#';
    }

    vector<int> p(len, 0); //以i为中心点的回文子串半径长度，不包含i

    int c = 0, r = 0, i_m; //c是中心位置，r是回文子串右侧终点，i_m是i关于c的对称点

    for (int i = 1; i < len - 1; i++)
    {
        i_m = c * 2 - i;
        if (r > i)
        {
            p[i] = min(r - i, p[i_m]);
        }
        else
        {
            p[i] = 0;
        }

        while (str[i + 1 + p[i]] == str[i - 1 - p[i]])
        {
            p[i]++;
        }

        if (i + p[i] > r)
        {
            c = i;
            r = i + p[i];
        }
    }
    int maxLen = 0;
    int centerIndex = 0;
    for (int i = 1; i < len - 1; i++)
    {
        if (p[i] > maxLen)
        {
            maxLen = p[i];
            centerIndex = i;
        }
    }
    int start = (centerIndex - maxLen) / 2;
    return s.substr(start, maxLen);
}
int main()
{
    string s = "teest";
    cout << longestPalindrome(s) << endl;
}