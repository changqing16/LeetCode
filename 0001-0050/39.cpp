#include <algorithm>
#include <stdio.h>
#include <vector>
using namespace std;

vector<vector<int>> ans;
int length;

void help(vector<int> &candidates, int cur[], int target, int loc, int len);

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    length = candidates.size();
    sort(candidates.begin(), candidates.begin() + length);
    int cur[target / candidates[0]];

    for (int i = 0; i < length; i++)
    {
        if (candidates[i] <= target)
        {
            cur[0] = candidates[i];
            help(candidates, cur, target - candidates[i], i, 1);
        }
        else
            break;
    }
    return ans;
}

void help(vector<int> &candidates, int cur[], int target, int loc, int len)
{
    if (target == 0)
    {
        vector<int> one(cur, cur + len);
        ans.push_back(one);
        return;
    }
    for (int i = loc; i < length; i++)
    {
        if (candidates[i] <= target)
        {
            cur[len] = candidates[i];
            help(candidates, cur, target - candidates[i], i, len + 1);
        }
        else
            break;
    }
}