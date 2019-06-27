#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

int threeSumClosest(vector<int> &nums, int target)
{
    int ans = 0, diff = INT_MAX;
    int size = nums.size();
    sort(nums.begin(), nums.begin() + size);

    for (int i = 0; i < size; i++)
    {
        int tmp = target - nums[i];
        int front = i + 1;
        int back = size - 1;
        while (front < back)
        {
            int sum = nums[front] + nums[back];
            if (sum < tmp)
            {
                front++;
                if (diff > tmp - sum)
                {
                    diff = tmp - sum;
                    ans = target - diff;
                }
            }
            else if (sum > tmp)
            {
                back--;
                if (diff > sum - tmp)
                {
                    diff = sum - tmp;
                    ans = diff + target;
                }
            }
            else
                return target;
        }
    }
    return ans;
}

int main()
{
    vector<int> nums(4, 1);
    printf("%d", threeSumClosest(nums, 0));
}