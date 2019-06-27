#include <iostream>
#include <vector>
using namespace std;

bool canJump(vector<int> &nums)
{
    int i = 0;
    int length = nums.size();
    for (int reach = 0; i < length && i <= reach; ++i)
        reach = max(i + nums[i], reach);
    return i == length;
}