#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int findNumberOfLIS(vector<int> &nums)
{
    int len = nums.size();
    int ans = 0, maxLen = 0;

    vector<int> help(len, 1);
    vector<int> times(len, 1);
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[i] > nums[j])
            {
                if (help[i] == help[j] + 1)
                    times[i] += times[j];
                else if (help[i] < help[j] + 1)
                {
                    times[i] = times[j];
                    help[i] = help[j] + 1;
                }
            }
        }
        if (maxLen == help[i])
            ans += times[i];
        if (maxLen < help[i])
        {
            maxLen = help[i];
            ans = times[i];
        }
    }
    return ans;
}

int main()
{
    vector<int> nums = {2, 2, 2, 2, 2};
    cout << findNumberOfLIS(nums) << endl;
}