#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;
int minSwap(vector<int> &A, vector<int> &B)
{
    vector<int> ans0(A.size(), 2000); //不换
    vector<int> ans1(A.size(), 2000); //换
    ans0[0] = 0;
    ans1[0] = 1;
    for (int i = 1; i < A.size(); i++)
    {
        if (A[i] > A[i - 1] && B[i] > B[i - 1])
        {
            ans0[i] = min(ans0[i], ans0[i - 1]);     //前一个没换的情况下，这个不换
            ans1[i] = min(ans1[i], ans1[i - 1] + 1); //前一个换了的情况下，这个再换
        }
        if (A[i] > B[i - 1] && B[i] > A[i - 1])
        {
            ans1[i] = min(ans1[i], ans0[i - 1] + 1); //前一个没换的情况下，这个再换
            ans0[i] = min(ans0[i], ans1[i - 1]);     //前一个换了的情况下，这个不换
        }
    }
    return min(ans0[A.size() - 1], ans1[A.size() - 1]);
}
int main()
{
    vector<int> A = {1, 3, 5, 4};
    vector<int> B = {1, 2, 3, 7};
    cout << minSwap(A, B) << endl;
}