#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool *visited;

bool helper(string s, vector<string> &wordDict, int pos)
{
    if (pos == s.size())
    {
        return true;
    }
    if (visited[pos])
        return false;
    else
        visited[pos] = true;
    for (int i = 0; i < wordDict.size(); i++)
    {
        bool flag = false;
        int cur = 0;
        while (cur < wordDict[i].size())
        {
            if (s[pos + cur] != wordDict[i][cur])
            {
                flag = true;
                break;
            }
            cur++;
        }
        if (!flag)
        {
            if (helper(s, wordDict, pos + cur))
            {
                return true;
            }
        }
    }
    return false;
}

bool wordBreak(string s, vector<string> &wordDict)
{
    visited = new bool[s.size()]();
    return helper(s, wordDict, 0);
}
int main()
{
    string s = "AAAAAAA";
    vector<string> wordDict = {"A", "AA", "AAAA", "AAAAA"};
    if (wordBreak(s, wordDict))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
}