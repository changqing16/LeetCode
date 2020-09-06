#include <cstring>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
int mark[256];
int lengthOfLongestSubstring(string s)
{
    memset(mark, -1, sizeof(int) * 256);
    int start = 0, cur, ans = 0;
    for (int i = 0; i < s.size(); i++)
    {
        cur = mark[(int)s[i]];
        while (start <= cur)
        {
            mark[(int)s[start++]] = -1;
        }
        mark[(int)s[i]] = i;
        ans = max(ans, i - start + 1);
    }
    return ans;
}

int main()
{
    string s = "abcabcbb";
    cout << lengthOfLongestSubstring(s) << endl;
}