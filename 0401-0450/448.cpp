#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<int> &nums, int i)
{
    int tmp;
    while (nums[i] != 0)
    {
        tmp = nums[i] - 1;
        nums[i] = 0;
        i = tmp;
    }
}

vector<int> findDisappearedNumbers(vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        dfs(nums, i);
    }
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++)
    {
        cout<<nums[i]<<" ";
        if (nums[i] != 0)
            ans.push_back(i + 1);
    }
    cout<<endl;
    return ans;
}

int main()
{
    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
    findDisappearedNumbers(nums);
}
