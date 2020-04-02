#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

void dfs(vector<int> &nums, vector<int> &cur, int n, vector<vector<int>> &ans)
{
    if (cur.size() > 1)
        ans.push_back(cur);

    unordered_set<int> hash;//把hash放进每步的dfs中而不是整体的hash，巧妙的思想
    for (int i = n; i < nums.size(); i++)
    {
        if ((cur.empty() || nums[i] >= cur.back()) && hash.count(nums[i]) == 0)
        {
            cur.push_back(nums[i]);
            dfs(nums, cur, i + 1, ans);
            cur.pop_back();
            hash.insert(nums[i]);
        }
    }
}

vector<vector<int>> findSubsequences(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> cur;
    dfs(nums, cur, 0, ans);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << ",";
        }
        cout << endl;
    }
    return ans;
}

int main()
{
    vector<int> nums = {4, 6, 7, 7};
    findSubsequences(nums);
}