#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;
//topological sort 拓扑排序
bool canFinish(int n, vector<pair<int, int>> &pre)
{
    vector<vector<int>> adj(n, vector<int>());
    vector<int> degree(n, 0);
    for (auto &p : pre)
    {
        adj[p.second].push_back(p.first);
        degree[p.first]++;
    }
    queue<int> q;
    for (int i = 0; i < n; i++)
        if (degree[i] == 0)
            q.push(i);
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        n--;
        for (auto next : adj[curr])
            if (--degree[next] == 0)
                q.push(next);
    }
    return n == 0;
}