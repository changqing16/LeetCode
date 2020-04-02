#include <iostream>
#include <string>
#include <vector>
using namespace std;

int characterReplacement(string s, int k)
{
    int start = 0, end = 0, ans = 0, globalMax = 0;
    vector<int> counts(26, 0);
    for (; end < s.size(); end++)
    {
        counts[s[end] - 'A']++;
        globalMax = max(globalMax, counts[s[end] - 'A']);
        if (end - start - globalMax >= k)
        {
            counts[s[start] - 'A']--;
            start++;
        }
        ans = max(ans, end - start + 1);
    }
    return ans;
}

int main()
{
    string s = "AABABBA";
    cout << characterReplacement(s, 1) << endl;
    return 0;
}