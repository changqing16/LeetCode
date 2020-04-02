#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

bool dfs(int cur, vector<char> &status, unordered_map<int, vector<int>> &graph)
{
    if (status[cur] == 1)
        return true;

    else if (status[cur] == 2)
        return false;
    status[cur] = 2;

    if (graph.count(cur) == 0)
    {
        status[cur] = 1;
        return true;
    }

    for (int i = 0; i < graph[cur].size(); i++)
        if (!dfs(graph[cur][i], status, graph))
            return false;

    status[cur] = 1;
    return true;
}

bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
{
    vector<char> status(numCourses, 0);
    unordered_map<int, vector<int>> graph;
    for (int i = 0; i < prerequisites.size(); i++)
    {
        graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
    }

    vector<int> tmp;
    for (int i = 0; i < numCourses; i++)
    {
        if (!dfs(i, status, graph))
            return false;
    }
    return true;
}
