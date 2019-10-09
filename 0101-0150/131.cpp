#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n = 8;
vector<vector<int>> nums;
vector<vector<string>> ans;

void checkPalindrome(string s, int i, int j)
{
    while (i >= 0 && j < s.size() && s[i] == s[j])
    {
        nums[i].push_back(j);
        i--;
        j++;
    }
}

void countSubstrings(string s)
{
    int len = s.size();
    if (len == 0)
        return;
    for (int i = 0; i < len; i++)
    {
        checkPalindrome(s, i, i);
        checkPalindrome(s, i, i + 1);
    }
}

void help(string s, vector<string> &pre, int start)
{
    if (start == n)
    {
        ans.push_back(pre);
        return;
    }
    for (int i = 0; i < nums[start].size(); i++)
    {
        pre.push_back(s.substr(start, nums[start][i] - start + 1));
        help(s, pre, nums[start][i] + 1);
        pre.pop_back();
    }
}

vector<vector<string>> partition(string s)
{
    nums = vector<vector<int>>(s.size());
    n = s.size();
    countSubstrings(s);
    vector<string> cur;
    help(s, cur, 0);
    return ans;
}

int main()
{
    string s = "aaabb";
    // nums = vector<vector<int>>(s.size());
    // countSubstrings(s);
    // for (int i = 0; i < nums.size(); i++)
    // {
    //     for (int j = 0; j < nums[i].size(); j++)
    //     {
    //         cout << i << " " << nums[i][j] << endl;
    //     }
    // }
    vector<vector<string>> tt = partition(s);
    for (int i = 0; i < tt.size(); i++)
    {
        for (int j = 0; j < tt[i].size(); j++)
        {
            cout << tt[i][j] << " ";
        }
        cout << endl;
    }
}