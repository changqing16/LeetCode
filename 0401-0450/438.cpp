#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

bool check(vector<int> &A)
{
    for (int i = 0; i < 26; i++)
        if (A[i] != 0)
            return false;
    return true;
}

vector<int> findAnagrams(string s, string p)
{
    vector<int> ans;
    int start = 0, end = 0, len = s.size();
    if (p.size() > len)
        return ans;
    vector<int> times(26, 0);
    for (; end < p.size(); end++)
    {
        times[p[end] - 'a']++;
        times[s[end] - 'a']--;
    }

    while (end < len)
    {
        if (check(times))
            ans.push_back(start);

        times[s[end] - 'a']--;
        times[s[start] - 'a']++;
        end++;
        start++;
    }
    if (check(times))
        ans.push_back(start);
    return ans;
}

int main()
{
    string s = "abab";
    string p = "ab";

    vector<int> ans = findAnagrams(s, p);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << ",";
    }
    cout << endl;
    return 0;
}