#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int wiggleMaxLength(vector<int> &nums)
{
    if (nums.size() < 2)
        return nums.size();

    vector<int> tmp1(nums.size(), 0);
    vector<int> tmp2(nums.size(), 0);
    int m = 0, n = 0, m1, n1;

    int ans = 0;

    for (int i = 1; i < nums.size(); i++)
    {
        m1 = m;
        n1 = n;
        if (nums[i] - nums[m1] > 0)
        {
            tmp2[i] = tmp1[m1] + 1;
            n = i;
            ans = max(ans, tmp2[i]);
        }
        if (nums[i] - nums[n1] < 0)
        {
            tmp1[i] = tmp2[n1] + 1;
            ans = max(ans, tmp1[i]);
            m = i;
        }
    }

    return ans + 1;
}

int main()
{
    vector<int> nums = {1, 1, 1, 2, 2, 2, 1, 1, 1, 3, 3, 3, 2, 2, 2};
    cout << wiggleMaxLength(nums) << endl;
}