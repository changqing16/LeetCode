#include <algorithm>
#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include<memory>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    vector<vector<string>> ans;
    vector<int *> help;
    vector<int> en;
    bool flag = true;
    for (int i = 0; i < strs.size(); i++)
    {
        flag = true;
        int len = strs[i].length();
        for (int j = 0; j < ans.size(); j++)
        {
            if (en[j] == len)
            {
                flag = false;
                int tmp[26] = {0};
                for (int k = 0; k < len; k++)
                {
                    int ss = strs[i].at(k) - 'a';
                    tmp[ss]++;
                    if (tmp[ss] > help[j][ss])
                    {
                        flag = true;
                        break;
                    }
                }
                if (!flag)
                {
                    ans[j].push_back(strs[i]);
                    break;
                }
            }
        }
        if (flag)
        {
            ans.push_back(vector<string>());
            ans[ans.size() - 1].push_back(strs[i]);
            int *arr = (int *)malloc(26 * sizeof(int));
            memset(arr, 0, 26 * sizeof(int));
            for (int k = 0; k < len; k++)
            {
                arr[strs[i].at(k) - 'a']++;
            }
            help.push_back(arr);
            en.push_back(len);
        }
    }
    return ans;
}

int main()
{
    vector<string> test;
    test.push_back("eat");
    test.push_back("tea");
    test.push_back("tan");
    test.push_back("ate");
    test.push_back("nat");
    test.push_back("bat");
    vector<vector<string>> ans = groupAnagrams(test);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << ",";
        }
        cout << endl;
    }
}