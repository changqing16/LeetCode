#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int longestValidParentheses(string s)
{
    int ans = 0, cur = 0;
    stack<int> help;
    int prev = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            help.push(prev);
            prev = 0;
        }
        else
        {
            if (!help.empty())
            {
                cur = help.top() + 2 + prev;
                prev = cur;
                help.pop();
                ans = max(cur, ans);
            }
            else
            {
                prev = 0;
                while (!help.empty())
                {
                    help.pop();
                }
            }
        }
    }
    return ans;
}

int main()
{
    string str;
    while (cin >> str)
    {
        cout << longestValidParentheses(str) << endl;
    }
}