#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;
int target; // of each bucket
vector<int> ns;
vector<int> bucket;

// put #n item of ns into some bucket to meet target
bool put(int n)
{
    for (int i = 0; i < bucket.size(); ++i)
    {
        if (bucket[i] + ns[n] > target)
            continue;       // try next bucket
        bucket[i] += ns[n]; // put it in!
        if (n == ns.size() - 1)
            return true; // all items in bucket, no overflow
        if (put(n + 1))
            return true; // move on to next item
        else
        {                       // no solution = wrong bucket
            bucket[i] -= ns[n]; // take it out
            if (bucket[i] == 0)
                return false; // no need to try other empty bucket
        }
    }
    return false; // no bucket fits
}

bool canPartitionKSubsets(vector<int> &nums, int k)
{
    int sum = 0;
    for (int &n : nums)
        sum += n;
    if (sum % k)
        return false; // not divisible
    target = sum / k;
    ns = vector<int>(nums);
    bucket = vector<int>(k, 0);
    // starting with bigger ones makes it faster
    sort(ns.begin(), ns.end(), greater<int>());
    return put(0);
}

int main()
{
    //vector<int> nums = {10, 10, 10, 7, 7, 7, 7, 7, 7, 6, 6, 6};
    //vector<int> nums = {4, 3, 2, 3, 5, 2, 1};
    //vector<int> nums = {1, 1, 2, 4};
    vector<int> nums = {114, 96, 18, 190, 207, 111, 73, 471, 99, 20, 1037, 700, 295, 101, 39, 649};
    if (canPartitionKSubsets(nums, 4))
        cout << "true" << endl;
    else
        cout << "false" << endl;
}