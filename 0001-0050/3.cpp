#include <cstring>
#include <stdio.h>
#include <string>
using namespace std;
int mark[256];
int lengthOfLongestSubstring(string s)
{
    int size = s.size();
    char str[size];
    strcpy(str, s.c_str());

    int count = 0, ans = 0, pre = 0;

    for (int i = 0; i < 256; i++)
        mark[i] = -1;


    memset(mark, -1, 256);
    for (int i = 0; i < size; i++)
    {
        int change = str[i];
        if (pre <= mark[change])
        {
            pre = mark[change] + 1;
            count = i - pre; //这儿少加了1，在后面加了
        }
        mark[change] = i;
        count++;
        if (count > ans)
            ans = count;
    }
    return ans;
}

int main()
{
    int str[10];
    printf("%d",sizeof(str));
}