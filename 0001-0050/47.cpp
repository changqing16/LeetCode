#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> permuteUnique(vector<int> &nums)
{
    vector<int> cur = nums;
    vector<vector<int>> result;
    do
    {
        result.push_back(cur);
        next_permutation(cur.begin(), cur.end());
    } while (cur != nums);

    return result;
}