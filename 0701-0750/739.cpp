#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> dailyTemperatures(vector<int> &T)
{
    vector<int> ans(T.size());
    stack<pair<int, int>> s;
    for (int i = T.size() - 1; i >= 0; i--)
    {
        while (!s.empty() && s.top().first <= T[i])
        {
            s.pop();
        }
        if (!s.empty())
            ans[i] = s.top().second - i;
        else
            ans[i] = 0;
        s.push({T[i], i});
    }
    return ans;
}