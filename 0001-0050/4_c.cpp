#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    int m = nums1.size();
    int n = nums2.size();

    if (m > n)
    {
        swap(m, n);
        swap(nums1, nums2);
    }

    int start = 0, end = m, half_len = (m + n + 1) / 2;

    int i, j, max_of_left = 0, min_of_right = 0;
    while (start <= end)
    {
        i = (start + end) / 2;
        j = half_len - i;
        if (i < m && nums2[j - 1] > nums1[i])
        {
            start = i + 1;
        }
        else if (i > 0 && nums1[i - 1] > nums2[j])
        {
            end = i - 1;
        }
        else
        {
            if (i == 0)
                max_of_left = nums2[j - 1];
            else if (j == 0)
                max_of_left = nums1[i - 1];
            else
                max_of_left = max(nums1[i - 1], nums2[j - 1]);

            if ((m + n) % 2 == 1)
                return max_of_left;

            if (i == m)
                min_of_right = nums2[j];
            else if (j == n)
                min_of_right = nums1[i];
            else
                min_of_right = min(nums1[i], nums2[j]);
            cout << max_of_left + min_of_right << endl;
            return ((double)(max_of_left + min_of_right)) / 2.0;
        }
    }
    return 0;
}

int main()
{
    vector<int> A = {1, 2};
    vector<int> B = {3, 4};
    cout << findMedianSortedArrays(A, B) << endl;
    return 0;
}