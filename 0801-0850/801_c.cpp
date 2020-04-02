#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;
int minSwap(vector<int> &A, vector<int> &B)
{
    int swapRecord = 1, fixRecord = 0;
    for (int i = 1; i < A.size(); i++)
    {
        if (A[i - 1] >= B[i] || B[i - 1] >= A[i])
        {
            // In this case, the ith manipulation should be same as the i-1th manipulation
            // fixRecord = fixRecord;
            swapRecord++;
        }
        else if (A[i - 1] >= A[i] || B[i - 1] >= B[i])
        {
            // In this case, the ith manipulation should be the opposite of the i-1th manipulation
            int temp = swapRecord;
            swapRecord = fixRecord + 1;
            fixRecord = temp;
        }
        else
        {
            // Either swap or fix is OK. Let's keep the minimum one
            int num = min(swapRecord, fixRecord);
            swapRecord = num + 1;
            fixRecord = num;
        }
    }
    return min(swapRecord, fixRecord);
}
int main()
{
    vector<int> A = {1, 3, 5, 4};
    vector<int> B = {1, 2, 3, 7};
    cout << minSwap(A, B) << endl;
}