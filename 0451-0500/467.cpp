#include <iostream>
#include <string>
#include <vector>
using namespace std;
int findSubstringInWraproundString(string p)
{
    if (p.size() <= 1)
        return p.size();
    vector<int> help(26, 0); //以此字符为始的最长连续串长度。
    int start = 0;
    for (int i = 1; i < p.size(); i++)
    {
        if (p[i] - p[i - 1] != 1 && p[i] - p[i - 1] != -25)
        {
            help[p[start] - 'a'] = max(help[p[start] - 'a'], i - start);
            start = i;
        }
    }
    help[p[start] - 'a'] = max(help[p[start] - 'a'], (int)p.size() - start);
    for (int i = 0; i < 26; i++)
    {
        for (int j = 1; j < help[i]; j++)
        {
            if (help[(i + j) % 26] < help[i] - j)
                help[(i + j) % 26] = help[i] - j;
            else
                break;
        }
    }
    int ans = 0;
    for (auto const &n : help)
    {
        cout << n << ",";
        ans += n;
    }
    cout << endl;
    return ans;
}

int main()
{
    string p = "abc";
    cout << findSubstringInWraproundString(p) << endl;
    return 0;
}