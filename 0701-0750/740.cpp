#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int rob(vector<int> &nums, int start, int end)
{
    if (end - start == 0)
        return 0;
    if (end - start == 1)
        return nums[start] * start;

    vector<int> f(end - start);
    f[0] = nums[start] * start;
    if (nums[start + 1] * (start + 1) > f[0])
        f[1] = nums[start + 1] * (start + 1);
    else
        f[1] = f[0];

    for (int i = 2; i < end - start; i++)
    {
        if (f[i - 1] > f[i - 2] + nums[start + i] * (start + i))
            f[i] = f[i - 1];
        else
            f[i] = f[i - 2] + nums[start + i] * (start + i);
    }
    return f[end - start - 1];
}

int deleteAndEarn(vector<int> &nums)
{
    int ans = 0;
    vector<int> help(10001, 0);
    for (int i = 0; i < nums.size(); i++)
    {
        help[nums[i]]++;
    }
    int start, index = 1;
    while (index < 10001)
    {
        while (index < 10001 && help[index] == 0)
        {
            index++;
        }
        start = index;
        while (index < 10001 && help[index] != 0)
            index++;
        ans += rob(help, start, index);
    }
    return ans;
}

int main()
{
    vector<int> nums = {2, 2, 3, 3, 3, 4};
    cout << deleteAndEarn(nums) << endl;
}