#include <iostream>
#include <string>
using namespace std;

int calculate(string s)
{
    s += '+';
    int num = 0, before, num1;
    char c, op_before = '0', op = '0';
    for (size_t i = 0; i < s.size(); i++)
    {
        c = s.at(i);
        if (c >= '0' && c <= '9')
            num = num * 10 + (c - '0');

        else if (c == '*' || c == '/') //直接计算，如果op_before不为0，则将
        {

            cout << "num: " << num << endl;

            if (op == '+' || op == '-')
            {
                op_before = op;
                before = num1;
                num1 = num;
            }
            else if (op == '*')
                num1 = num1 * num;

            else if (op == '/')
                num1 = num1 / num;

            else
                num1 = num;

            cout << num1 << endl;

            num = 0;
            op = c;
        }
        else if (c == '+' || c == '-')
        {
            cout << "num: " << num << endl;

            if (op == '+')
                num1 = num1 + num;
            else if (op == '-')
                num1 = num1 - num;
            else if (op == '*')
                num1 = num1 * num;
            else if (op == '/')
                num1 = num1 / num;
            else
                num1 = num;

            if (op_before == '+')
                num1 = before + num1;

            else if (op_before == '-')
                num1 = before - num1;
            op_before = '0';
            cout << num1 << endl;

            op = c;
            num = 0;
        }
    }
    return num1;
}

int main()
{
    string s = "1+2*3+4*5+6*7+8*9+10";
    cout << calculate(s) << endl;
}
