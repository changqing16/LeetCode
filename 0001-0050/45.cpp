#include <iostream>
#include <vector>
using namespace std;

int trap(vector<int> &height)
{
    int p1 = 0, p2 = 0;
    int ans = 0, cur = 0;
    for (; p2 < height.size(); p2++)
    {
        if (height[p2] >= height[p1])
        {
            p1 = p2;
            ans += cur;
            cur = 0;
        }
        else
        {
            cur += height[p1] - height[p2];
        }
    }

    p1 = p2 = height.size() - 1;
    cur = 0;
    for (; p2 >= 0; p2--)
    {
        if (height[p2] > height[p1])
        {
            p1 = p2;
            ans += cur;
            cur = 0;
        }
        else
        {
            cur += height[p1] - height[p2];
        }
    }
    return ans;
}

int main()
{
    vector<int> nums = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << trap(nums) << endl;
}