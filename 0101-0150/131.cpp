#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> palin;

void find_palin(string &str)
{
    int len = str.size();
    int start, end;
    for (int i = 0; i < len - 2; i++)
    {
        for (int j = i + 2; j < len; j++)
        {
            start = i;
            end = j;
            while (start <= end)
            {
                if (str.at(start) == str.at(end))
            }
        }
    }
}

vector<vector<string>> partition(string s)
{
    vector<vector<string>> ans;
}