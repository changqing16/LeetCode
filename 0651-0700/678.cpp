#include <iostream>
#include <stack>
#include <vector>
using namespace std;

bool checkValidString(string s)
{
    stack<int> left;
    stack<int> count;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            left.push(i);
        }
        else if (s[i] == ')')
        {
            if (!left.empty())
            {
                left.pop();
            }
            else if (!count.empty())
            {
                count.pop();
            }
            else
            {
                return false;
            }
        }
        else
        {
            count.push(i);
        }
    }
    while (!left.empty())
    {
        if (!count.empty() && left.top() < count.top())
        {
            left.pop();
            count.pop();
        }
        else
        {
            return false;
        }
    }
    return true;
}

int main()
{
    string s = "(())((())()()(*)(*()(())())())()()((()())((()))(*";
    cout << checkValidString(s) << endl;
}