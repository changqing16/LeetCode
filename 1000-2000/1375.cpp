#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int numTimesAllBlue(vector<int> &light)
{
    int ans = 0;
    int len = light.size();
    priority_queue<int, vector<int>, greater<int>> min_heap;
    int cur = 0;
    for (int k = 0; k < len; k++)
    {
        if (light[k] - 1 == cur)
        {
            cur++;
            while (!min_heap.empty() && min_heap.top() - 1 == cur)
            {
                min_heap.pop();
                cur++;
            }
        }
        else
            min_heap.push(light[k]);
        
        if (min_heap.empty())
            ans++;
    }
    return ans;
}

int main()
{
    vector<int> nums = {2, 1, 4, 3, 6, 5};
    cout << numTimesAllBlue(nums) << endl;
    return 0;
}