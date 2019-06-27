#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool containsDuplicate(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    for (int i = 1; i < nums.size(); i++)
        if (nums[i - 1] == nums[i])
            return true;
    return false;
}