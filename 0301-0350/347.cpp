#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

struct cmp
{
    bool operator()(pair<int, int> &a, pair<int, int> &b)
    {
        return a.second > b.second;
    }
};

vector<int> topKFrequent(vector<int> &nums, int k)
{
    vector<int> ans(k);
    map<int, int> frequent;
    for (int i = 0; i < nums.size(); i++)
    {
        frequent[nums[i]]++;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> topK;

    for (auto kv : frequent)
    {
        if (topK.size() == k)
        {
            if (kv.second > topK.top().second)
            {
                topK.pop();
                topK.push(kv);
            }
        }
        else
        {
            topK.push(kv);
        }
    }
    for (int i = k - 1; i >= 0; i--)
    {
        ans[i] = topK.top().first;
        topK.pop();
    }
    return ans;
}
int main()
{
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    vector<int> ans = topKFrequent(nums, 2);
    for (auto &i : ans)
        cout << i << ",";
    cout << endl;
    return 0;
}