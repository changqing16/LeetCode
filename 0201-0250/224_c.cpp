#include <iostream>
#include <stack>
#include <string>
using namespace std;

int calculate(string s)
{
    int result = 0;
    int sign = 1;
    int num = 0;

    stack<int> nums;
    nums.push(sign);

    char c;
    for (size_t i = 0; i < s.size(); i++)
    {
        c = s.at(i);
        if (c >= '0' && c <= '9')
            num = num * 10 + (c - '0');

        else if (c == '+' || c == '-')
        {
            result += sign * num;
            sign = nums.top() * (c == '+' ? 1 : -1);
            num = 0;
        }
        else if (c == '(')
            nums.push(sign);

        else if (c == ')')
            nums.pop();
    }

    result += sign * num;
    return result;
}

int main()
{
    string s = "1 + 1 ";
    cout << calculate(s) << endl;
}