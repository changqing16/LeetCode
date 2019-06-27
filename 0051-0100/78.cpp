#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> result;
    vector<int> tmp0;
    result.push_back(tmp0);
    vector<int> tmp1(1);
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        tmp1[0] = nums[i];
        result.push_back(tmp1);
    }
    for (int k = 2; k < n; k++)
    {
        int i = 0;
        vector<int> p(k, 0);
        vector<int> tmp(k);
        while (i >= 0)
        {
            p[i]++;
            if (p[i] > n)
                --i;
            else if (i == k - 1)
            {
                for (int j = 0; j < k; j++)
                    tmp[j] = nums[p[j] - 1];
                result.push_back(tmp);
            }
            else
            {
                ++i;
                p[i] = p[i - 1];
            }
        }
    }
    if (n > 1)
        result.push_back(nums);
    return result;
}

int main()
{
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = subsets(nums);
    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
            cout << result[i][j] << ",";
        cout << endl;
    }
}

// vector<vector<int>> subsets(vector<int> &S)
// {
//     sort(S.begin(), S.end());
//     int elem_num = S.size();
//     int subset_num = pow(2, elem_num);
//     vector<vector<int>> subset_set(subset_num, vector<int>());
//     for (int i = 0; i < elem_num; i++)
//         for (int j = 0; j < subset_num; j++)
//             if ((j >> i) & 1)
//                 subset_set[j].push_back(S[i]);
//     return subset_set;
// }