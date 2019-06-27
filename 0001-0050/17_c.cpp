#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

vector<string> letterCombinations(string digits)
{
    queue<string> ans;
    vector<string> tmp;
    if (digits.size() == 0)
        return tmp;
    string mapping[] = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    ans.push("");
    for (int i = 0; i < digits.length(); i++)
    {
        int x = digits[i] - '0';
        while (ans.front().length() == i)
        {
            string tmp = ans.front();
            ans.pop();
            for (int j = 0; j < mapping[x].length(); j++)
            {
                ans.push(tmp + mapping[x][j]);
            }
        }
    }
    vector<string> last(ans.size());
    int len = 0;
    while (!ans.empty())
    {
        last[len++] = ans.front();
        ans.pop();
    }
    return last;
}

int main()
{
    string question = "2345";
    vector<string> ans = letterCombinations(question);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}