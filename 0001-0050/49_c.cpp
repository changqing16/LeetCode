#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    int input_size = strs.size();
    if (input_size == 0)
        return vector<vector<string>>{};
    if (input_size == 1)
        return vector<vector<string>>{strs};
    // First 26 prime numbers
    int primes[26]{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43,
                   47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101},
        prod, counter = 0;
    // table stores the index of each anagram class in result
    unordered_map<int, int> table{};
    vector<vector<string>> result{};
    for (string const &i : strs)
    {
        prod = 1;
        for (char const &j : i)
            prod *= primes[j - 'a'];
        // Words in the same anagram class have the same prod
        if (table.find(prod) == table.end())
        {
            result.push_back(vector<string>{i});
            table[prod] = counter++;
        }
        else
        {
            result[table[prod]].push_back(i);
        }
    }
    return result;
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