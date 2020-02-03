#include <iostream>
#include <vector>

using namespace std;

int findTargetSumWays(vector<int> &nums, int S)
{
    int total = 0;
    for (int i = 0; i < nums.size(); i++)
        total += nums[i];
    
    if (S < -total || S > total)
        return 0;

    int max = total * 2 + 1;
    vector<vector<int>> help(nums.size(), vector<int>(max, 0));

    help[0][total - nums[0]] = 1;
    help[0][total + nums[0]] += 1;
    for (int i = 1; i < nums.size(); i++)
    {
        for (int j = nums[i]; j < max - nums[i]; j++)
        {
            help[i][j + nums[i]] += help[i - 1][j];
            help[i][j - nums[i]] += help[i - 1][j];
        }
    }
    return help[nums.size() - 1][total + S];
}

int main()
{
    vector<int> nums = {1, 1, 1, 1, 1};
    cout << findTargetSumWays(nums, 3) << endl;
}