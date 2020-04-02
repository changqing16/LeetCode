#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

int findDuplicate(vector<int> &nums)
{
    int low = 1, high = nums.size() - 1;
    int count, mid;
    while (low < high)
    {
        count = 0;
        mid = (low + high) / 2;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] <= mid)
                count++;
        }
        if (count <= mid)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}

int main()
{
    vector<int> nums = {1, 3, 4, 2, 1};
    cout << findDuplicate(nums) << endl;
    return 0;
}