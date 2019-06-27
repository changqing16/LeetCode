#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> permute(vector<int> &nums)
{
    vector<int> cur = nums;
    vector<vector<int>> result;
    do
    {
        result.push_back(cur);
        next_permutation(cur.begin(), cur.end());
    } while (cur != nums);

    return result;
}

int main()
{
    vector<int> nums = {1, 1, 2};
    vector<vector<int>> ans = permute(nums);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << ",";
        }
        cout << "]," << endl;
    }
}
