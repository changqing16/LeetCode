#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

int maxArea(vector<int> &height)
{
    int max = 0, tmp, ans = 0, cur, max2;
    int size = height.size();
    for (int i = 0; i < size; i++)
    {
        if (max < height[i])
            max = height[i];
        else
            continue;
        max2 = 0;
        for (int j = size - 1; j > i; j--)
        {
            if (max2 < height[j])
                max2 = height[j];
            else
                continue;
            tmp = height[i] < height[j] ? height[i] : height[j];
            cur = tmp * (j - i);
            if (cur > ans)
                ans = cur;
        }
    }
    return ans;
}