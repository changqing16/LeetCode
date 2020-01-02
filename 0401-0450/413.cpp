#include <iostream>
#include <vector>
using namespace std;

int numberOfArithmeticSlices(vector<int> &A)
{
    if (A.size() < 3)
        return 0;
    int index = 1;
    int start = 0;
    int diff = A[1] - A[0];
    int ans = 0;
    int n;

    while (index < A.size())
    {
        while (index + 1 < A.size() && A[index + 1] - A[index] == diff)
            index++;

        if (index - start >= 2)
        {
            n = index - start - 1;
            ans += (n * (n + 1)) / 2;
        }
        start = index;
        if (index + 1 < A.size())
            diff = A[index + 1] - A[index];
        index++;
    }
    return ans;
}
int main()
{
    vector<int> A = {1, 2, 3};
    cout << numberOfArithmeticSlices(A) << endl;
}