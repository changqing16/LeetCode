#include <iostream>
#include <vector>

using namespace std;

int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{
    int sum = 0, start = 0, tank = 0, tmp;
    for (int i = 0; i < gas.size(); i++)
    {
        tmp = gas[i] - cost[i];
        sum += tmp;
        tank += tmp;
        if (tank < 0)
        {
            start = i + 1;
            tank = 0;
        }
    }
    if (sum < 0)
        return -1;
    else
        return start;
}

int main()
{
    vector<int> gas = {1, 2, 3, 4, 5};
    vector<int> cost = {3, 4, 5, 1, 2};
    cout << canCompleteCircuit(gas, cost) << endl;
}