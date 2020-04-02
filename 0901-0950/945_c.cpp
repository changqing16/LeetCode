#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

int minIncrementForUnique(vector<int> &A)
{
    map<int, int> count;
    for (int a : A)
        count[a]++;
    int res = 0, need = 0;
    for (auto x : count)
    {
        res += x.second * max(need - x.first, 0) + x.second * (x.second - 1) / 2;
        need = max(need, x.first) + x.second;
    }
    return res;
}

unordered_map<int, int> root;
int minIncrementForUnique2(vector<int> &A)
{
    int res = 0;
    for (int a : A)
        res += find(a) - a;
    return res;
}
int find(int x)
{
    return root[x] = root.count(x) ? find(root[x] + 1) : x;
}