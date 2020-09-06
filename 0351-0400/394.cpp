#include <iostream>
#include <stack>
#include <string.h>
#include <string>
#include <vector>
using namespace std;

string decodeString(string s)
{
    char *ans = (char *)malloc(sizeof(char) * 10000);
    int index = 0;
    stack<pair<int, int>> nums;
    int len = s.size(), num = 0, k, start, end;
    for (int i = 0; i < len; i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            num = num * 10 + s[i] - '0';
        }
        else if (s[i] == '[')
        {
            nums.push({num, index});
            num = 0;
        }
        else if (s[i] == ']')
        {
            k = nums.top().first;
            start = nums.top().second;
            nums.pop();
            end = index;
            for (int j = 1; j < k; j++)
            {
                for (int x = start; x < end; x++)
                {
                    ans[index] = ans[x];
                    index++;
                }
            }
        }
        else
        {
            ans[index] = s[i];
            index++;
        }
    }
    ans[index] = 0;
    string str = ans;
    return str;
}
int main()
{
    string s = "ee3[a2[c]]";
    string ans = decodeString(s);
    cout << ans << endl;
    return 0;
}
