#include <deque>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int constrainedSubsetSum(vector<int> &nums, int k)
{
    int len = nums.size();
    queue<int> dp;        //以第i个数结尾的序列和最大值, 队列最大容量为k + 1(只需存储距离为k范围内的值)
    deque<int> max_stack; //单调栈
    int ans = nums[0];
    max_stack.push_back(0);
    for (int i = 0; i < len; i++)
    {
        dp.push(max(nums[i], nums[i] + max_stack.front()));
        if (dp.size() == k + 1)
        { //队满
            if (dp.front() == max_stack.front())
                max_stack.pop_front();
            dp.pop();
        }
        ans = max(ans, dp.back());
        while (!max_stack.empty() && max_stack.back() < dp.back()) //单调栈调整
            max_stack.pop_back();
        max_stack.emplace_back(dp.back());
    }
    return ans;
}