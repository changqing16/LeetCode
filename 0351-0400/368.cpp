#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> largestDivisibleSubset(vector<int> &nums)
{
    if (nums.size() == 0 || nums.size() == 1)
        return nums;
    sort(nums.begin(), nums.end());

    vector<int> ans(nums.size(), 0);
    vector<int> path(nums.size(), -1);
    int result = 0, index = 0;

    for (int i = 1; i < nums.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[i] % nums[j] == 0 && ans[j] + 1 > ans[i])
            {

                ans[i] = ans[j] + 1;
                path[i] = j;
            }
        }
        if (ans[i] > result)
        {
            result = ans[i];
            index = i;
        }
    }

    vector<int> tmp;
    while (index != -1)
    {
        tmp.push_back(nums[index]);
        index = path[index];
    }

    return tmp;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    vector<int> tmp = largestDivisibleSubset(nums);
    for (int i = 0; i < tmp.size(); i++)
    {
        cout << tmp[i] << ",";
    }
    cout << endl;
    return 0;
}
