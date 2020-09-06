#include <iostream>
#include <vector>
using namespace std;

void moveZeroes(vector<int> &nums)
{
    int p1 = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != 0)
        {
            if (p1 != i)
                swap(nums[p1], nums[i]);

            p1++;
        }
    }

    for (int i = p1; i < nums.size() - 1; i++)
    {
        nums[i] = 0;
    }
}
int main()
{
    vector<int> nums = {0, 1, 0, 3, 12};
    moveZeroes(nums);
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << ",";
    }
    cout << endl;
    return 0;
}