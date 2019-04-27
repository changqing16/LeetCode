#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int n, tmp, min, min2;
    while (cin >> n)
    {
        priority_queue<int, vector<int>, greater<int>> heap;
        for (int i = 0; i < n; i++)
        {
            cin >> tmp;
            heap.push(tmp);
        }
        for (int i = 0; i < heap.size(); i++)
        {
            min = heap.top();
            if (min >= 10)
            {
            }
            else
            {
                heap.pop();
                min2 = heap.top();
                heap.pop();
                heap.push(min + min2);
            }
        }
    }
}
