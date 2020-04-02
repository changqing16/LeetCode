#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std; //不是普通的

struct City
{
    int id;
    int cost;
    int stop;

    City(int id_, int cost_, int stop_) : id(id_), cost(cost_), stop(stop_){};

    bool operator<(const City &A) const
    {
        return cost < A.cost;
    }
};
int N = 1000000;

int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int K)
{
    vector<vector<int>> grid(n, vector<int>(n, 0));
    for (auto &f : flights)
    {
        grid[f[0]][f[1]] = f[2];
    }
    priority_queue<City> pq;
    pq.push(City(src, 0, 0));

    vector<int> cost(n, N);
    cost[src] = 0;
    vector<int> stop(n, N);
    stop[src] = 0;
    int newCost, newStop;

    while (!pq.empty())
    {
        City cur = pq.top();
        pq.pop();
        if (cur.id == dst)
            return cur.cost;
        if (cur.stop == K + 1)
            continue;
        for (int i = 0; i < n; i++)
        {
            if (grid[cur.id][i] != 0)
            {
                newCost = cur.cost + grid[cur.id][i];
                newStop = cur.stop + 1;
                if (newCost < cost[i])
                {
                    pq.push(City(i, newCost, newStop));
                    cost[i] = newCost;
                }
                else if (newStop < stop[i])
                {
                    pq.push(City(i, newCost, newStop));
                    stop[i] = newStop;
                }
            }
        }
    }
    return cost[dst] == N ? -1 : cost[dst];
}

int main()
{
    vector<vector<int>> edges = {{0, 1, 1}, {0, 2, 5}, {1, 2, 1}, {2, 3, 1}};
    cout << findCheapestPrice(4, edges, 0, 3, 1) << endl;
}