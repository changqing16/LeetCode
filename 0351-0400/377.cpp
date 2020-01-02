#include <iostream>
#include <map>
#include <vector>

using namespace std;
int combinationSum4(vector<int> &nums, int target)
{
    vector<int> result(target + 1);
    result[0] = 1;
    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < nums.size(); j++)
        {
            if (i - nums[j] >= 0)
                result[i] += result[i - nums[j]];
        }
    }
    return result[target];
}

int main()
{
    vector<int> nums = {1, 2, 3};
    cout << combinationSum4(nums, 4) << endl;
}