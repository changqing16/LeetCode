#include <iostream>
#include <vector>
using namespace std;

bool *help;
int length;

bool DFS(vector<int> &nums, int index)
{
    if (help[index])
        return false;
    if (nums[index] + index >= length - 1)
        return true;
    for (int i = nums[index]; i > 0; i--)
        if (DFS(nums, index + i))
            return true;
    help[index] = true;
    return false;
}

bool canJump(vector<int> &nums)
{
    length = nums.size();
    if (nums[0] >= length - 1)
        return true;

    help = new bool[length]{false};

    for (int j = nums[0]; j > 0; j--)
    {
        if (DFS(nums, j) == true)
        {
            delete[] help;
            return true;
        }
    }

    delete[] help;
    return false;
}

int main()
{
    vector<int> nums = {3, 0, 8, 2, 0, 0, 1};
    cout << canJump(nums) << endl;
}