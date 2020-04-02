#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

double dfs(int root, vector<vector<int>> &tree, int t, int target, int prev)
{
    if (t < 0)
        return 0;
    if (root == target)
    {
        if (t == 0)
            return 1;

        bool flag = true;
        for (int i = 0; i < tree[root].size(); i++)
        {
            if (tree[root][i] != prev)
            {
                flag = false;
            }
        }
        return flag ? 1 : 0;
    }
    double ans;
    for (int i = 0; i < tree[root].size(); i++)
    {
        if (tree[root][i] != prev)
        {
            ans = dfs(tree[root][i], tree, t - 1, target, root);
            if (ans != 0)
                return ans / (tree[root].size() - 1);
        }
    }
    return 0;
}

double frogPosition(int n, vector<vector<int>> &edges, int t, int target)
{
    vector<vector<int>> tree(n + 1, vector<int>());
    for (int i = 0; i < edges.size(); i++)
    {
        tree[edges[i][0]].push_back(edges[i][1]);
        tree[edges[i][1]].push_back(edges[i][0]);
    }

    return dfs(1, tree, t, target, -1);
}