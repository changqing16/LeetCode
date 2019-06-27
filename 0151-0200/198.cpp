#include <stdio.h>

int rob(int *nums, int numsSize)
{
    if (numsSize == 0)
        return 0;
    if (numsSize == 1)
        return nums[0];
    if (numsSize == 2)
    {
        if (nums[0] > nums[1])
            return nums[0];
        else
            return nums[1];
    }
    int f[numsSize];
    f[0] = nums[0];
    if (nums[0] > nums[1])
        f[1] = nums[0];
    else
        f[1] = nums[1];
    for (int i = 2; i < numsSize; i++)
    {
        if (f[i - 1] > f[i - 2] + nums[i])
            f[i] = f[i - 1];
        else
            f[i] = f[i - 2] + nums[i];
    }
    return f[numsSize - 1];
}