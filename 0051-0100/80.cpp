#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates(vector<int> &nums)
{
    if (nums.size() < 3)
        return nums.size();
    int loc = 2, next = 2, pre = nums[1];
    bool flag = (nums[0] == nums[1]);
    while (next < nums.size())
    {
        if (loc != next)
        {
            cout << "loc: " << loc << ",next: " << next << endl;
            nums[loc] = nums[next];
        }

        if (nums[next] == pre)
        {
            if (flag)
            {
                cout << "in flag: "
                     << "loc: " << loc << ",next: " << next << endl;
                loc--;
                while (nums[next + 1] == nums[next])
                    next++;
                flag = false;
            }
            else
                flag = true;
        }
        else
        {
            flag = false;
            pre = nums[next];
        }
        loc++;
        next++;
    }
    return loc;
}

int main()
{
    vector<int> nums = {1, 1, 2, 2, 3, 3, 3, 3, 4, 4};
    int len = removeDuplicates(nums);
    for (int i = 0; i < len; i++)
        cout << nums[i] << ",";
    cout << endl;
    return 0;
}