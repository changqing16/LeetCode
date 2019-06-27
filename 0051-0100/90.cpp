#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

vector<vector<int>> subsets(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    set<vector<int>> result;
    vector<vector<int>> ans;
    vector<int> tmp0;
    ans.push_back(tmp0);
    vector<int> tmp1(1);
    int n = nums.size();
    tmp1[0] = nums[0];
    ans.push_back(tmp1);
    for (int i = 1; i < n; i++)
    {
        if (nums[i] != nums[i - 1])
        {
            tmp1[0] = nums[i];
            ans.push_back(tmp1);
        }
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

                result.insert(tmp);
            }
            else
            {
                ++i;
                p[i] = p[i - 1];
            }
        }
    }

    for (set<vector<int>>::iterator it = result.begin(); it != result.end(); it++)
    {
        ans.push_back(*it);
    }
    if (n > 1)
        ans.push_back(nums);
    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 2};
    vector<vector<int>> result = subsets(nums);
    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
            cout << result[i][j] << ",";
        cout << endl;
    }
}

        // vector<vector<int> > totalset = {{}};
        // sort(S.begin(),S.end());
        // for(int i=0; i<S.size();){
        //     int count = 0; // num of elements are the same
        //     while(count + i<S.size() && S[count+i]==S[i])  count++;
        //     int previousN = totalset.size();
        //     for(int k=0; k<previousN; k++){
        //         vector<int> instance = totalset[k];
        //         for(int j=0; j<count; j++){
        //             instance.push_back(S[i]);
        //             totalset.push_back(instance);
        //         }
        //     }
        //     i += count;
        // }
        // return totalset;
        // }