#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> findAnagrams(string s, string p)
{
    vector<int> ans;
    int start = 0, end = 0, len = s.size(), ps = p.size();
    char c;
    if (ps > len)
        return ans;

    unordered_map<char, int> hash;
    for (int i = 0; i < ps; i++)
    {
        if (hash.count(p[i]) != 0)
            hash[p[i]]++;
        else
            hash[p[i]] = 1;
    }
    int count = hash.size();

    while (end < len)
    {
        c = s[end];
        if (hash.count(c) != 0)
        {
            hash[c]--;
            if (hash[c] == 0)
                count--;
        }
        end++;
        while (count == 0)
        {
            c = s[start];
            if (hash.count(c) != 0)
            {
                hash[c]++;
                if (hash[c] > 0)
                    count++;
            }
            if (end - start == ps) //效率是高，根本不需要考虑其他字符的，厉害
                ans.push_back(start);
            start++;
        }
    }
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