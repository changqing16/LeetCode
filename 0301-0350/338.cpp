#include <iostream>
#include <vector>

using namespace std;
vector<int> countBits(int num)
{
    vector<int> result(num + 1);
    result[0] = 0;
    int start = 1, end = 2;
    int j = 1;
    while (j <= num)
    {
        while (j < end && j <= num)
        {
            result[j] = result[j - start] + 1;
            j++;
        }
        start = end;
        end = start * 2;
    }
    return result;
}

// vector<int> countBits(int num) //还是位运算更快
// {
//     vector<int> result(num + 1);
//     result[0] = 0;
//     for (int i = 0; i <= num; i++)
//         result[i] = result[i >> 1] + (i & 1);
//     return result;
// }

int main()
{
    vector<int> ans = countBits(5);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << ",";
    }
    cout << endl;
    return 0;
}
