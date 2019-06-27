#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <time.h>
#include <vector>
using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
    int size = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    int j, end = size - 1;

    for (int i = 0; i < end; i++)
    {
        if (nums[i] == 0)
        {
            if (i + 2 < size && nums[i + 2] == 0)
            {
                vector<int> single(3, 0);
                ans.push_back(single);
            }
            return ans;
        }
        if (nums[i] > 0)
            return ans;
        if (i >= 1 && nums[i] == nums[i - 1])
            continue;
        j = end;
        while (i < j)
        {
            if (nums[j] <= 0)
                break;
            while (j < size - 1 && nums[j] == nums[j + 1])
                j--;
            int sum = (nums[i] + nums[j]) * -1;

            if (sum > nums[j])
                break;
            else if (sum < nums[i])
            {
                j--;
                end--;
                continue;
            }

            int top = j - 1, base = i + 1, find = -1;
            while (top >= base)
            {
                int mid = (top + base) / 2;
                if (nums[mid] == sum)
                {
                    find = mid;
                    break;
                }
                else if (nums[mid] < sum)
                    base = mid + 1;
                else
                    top = mid - 1;
            }
            if (find != -1)
            {
                vector<int> single(3);
                single[0] = nums[i];
                single[1] = nums[find];
                single[2] = nums[j];
                ans.push_back(single);
            }
            j--;
        }
    }
    return ans;
}

int main()
{
    int tmp[] = {-1, 0, 1, 2, -1, -4};
    vector<int> nums(tmp, tmp + sizeof(tmp) / sizeof(int));

    //clock_t start, finish;

    //vector<int> nums(10000, 0);
    // int len = 0;
    // for (int i = -4079; i < 5921; i++)
    // {
    //     nums[len++] = i;
    // }
    //start = clock();

    vector<vector<int>> ans = threeSum(nums);
    //finish = clock();
    //cout << 1000 * (finish - start) / CLOCKS_PER_SEC << endl;
    //getchar();
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }
}