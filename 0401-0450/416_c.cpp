#include <bitset>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

bool canPartition(vector<int> &nums)
{
    bitset<10001> bits(1); //将int 1的值赋值给bits,也就是将最后一位赋值为1
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum & 1) //不能被2整除
        return false;
    for (auto n : nums)
        bits |= bits << n; //有点东西呀，直接避免了对bitset的一次循环，对vector<char>数组来说是从后往前的。
    return bits[sum >> 1];
}

int main()
{
    vector<int> nums = {1, 5, 11, 5};
    cout << canPartition(nums) << endl;
}