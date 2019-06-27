#include <stdio.h>

int digitSquareSum(int n)
{
    int sum = 0, tmp;
    while (n)
    {
        tmp = n % 10;
        sum += tmp * tmp;
        n /= 10;
    }
    return sum;
}

bool isHappy(int n)
{
    int slow, fast;
    slow = fast = n;
    do
    {
        slow = digitSquareSum(slow); //根据题意，如果不是的话，将是无限循环，可以用判断链表的方法来判断是否是无限循环
        fast = digitSquareSum(fast); //厉害厉害！！！
        fast = digitSquareSum(fast);
        if (fast == 1)
            return 1;
    } while (slow != fast);
    return 0;
}

int main()
{
    bool temp = isHappy(2);
    if (temp)
    {
        printf("true");
    }
    else
    {
        printf("false");
    }
    return 0;
}