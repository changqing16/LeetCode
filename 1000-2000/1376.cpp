#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int dfs(vector<vector<int>> &tree, vector<int> &informTime, int root)
{
    int ans = 0;
    for (int i = 0; i < tree[root].size(); i++)
    {
        ans = max(ans, dfs(tree, informTime, tree[root][i]));
    }
    return ans + informTime[root];
}

int numOfMinutes(int n, int headID, vector<int> &manager, vector<int> &informTime)
{
    vector<vector<int>> tree(n, vector<int>());
    for (int i = 0; i < n; i++)
    {
        if (manager[i] != -1)
            tree[manager[i]].push_back(i);
    }
    return dfs(tree, informTime, headID);
}

int main()
{
    int n = 1, headID = 2;
    vector<int> manager = {3, 3, -1, 2};
    vector<int> informTime = {0, 0, 162, 914};

    cout << numOfMinutes(n, headID, manager, informTime) << endl;
    return 0;
}