#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

int quick_select(vector<int> &array, int begin, int end)
{
    // 在 begin 到 end 间随机找一个数 当 划分用的 key
    int rand_location = rand() % (end - begin + 1) + begin;
    int key = array[rand_location];
    // 把这个 key 移到 end 的位置，方便做双下标前移动
    swap(array[rand_location], array[end]);
    int i = begin - 1;
    for (int j = begin; j < end; ++j)
    {
        if (array[j] >= key)
        {
            i++;
            swap(array[i], array[j]);
        }
    }
    swap(array[i + 1], array[end]);
    return i + 1;
}

int findKthLargest(vector<int> &nums, int k)
{
    int left = 0, right = nums.size() - 1;
    while (true)
    {
        int ans = quick_select(nums, left, right);
        if (ans == k - 1)
            return nums[ans];
        else if (ans < k - 1)
            left = ans + 1;
        else
            right = ans - 1;
    }
    return 0;
}

// void heapify(vector<int> &arr, int n, int i)
// {
//     int largest = i;
//     int l = 2 * i + 1;
//     int r = 2 * i + 2;
//     if (l < n && arr[l] > arr[largest])
//         largest = l;
//     if (r < n && arr[r] > arr[largest])
//         largest = r;
//     if (largest != i)
//     {
//         swap(arr[i], arr[largest]);
//         heapify(arr, n, largest);
//     }
// }

// int findKthLargest(vector<int> &arr, int k)
// {
//     // 建立堆
//     int n = arr.size();
//     for (int i = n / 2 - 1; i >= 0; i--)
//         heapify(arr, n, i);

//     // 一个个从堆顶取出元素
//     int i;
//     for (i = n - 1; i > n - k; i--)
//     {
//         swap(arr[0], arr[i]);
//         heapify(arr, i, 0);
//     }
//     return arr[0];
// }

int main()
{
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    cout << findKthLargest(nums, 2) << endl;
}
