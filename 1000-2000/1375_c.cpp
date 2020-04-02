#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int numTimesAllBlue(vector<int> &light)
{
    int ans = 0;
    int m = 1;
    for (int i = 0; i < light.size(); i++)
    {
        m = max(m, light[i]);
        if (m == i + 1)
            ans++;
    }
    return ans;
}