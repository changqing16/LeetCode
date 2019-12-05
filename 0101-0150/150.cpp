#include <iostream>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;

stack<int> operand;
stack<char> op;
set<string> ops = {"+", "-", "*", "/"};

int evalRPN(vector<string> &tokens)
{
    int num, num1, num2;
    for (size_t i = 0; i < tokens.size(); i++)
    {
        if (ops.count(tokens[i]) == 0)
        {
            num = stoi(tokens[i]);
            operand.push(num);
        }
        else
        {
            num2 = operand.top();
            operand.pop();
            num1 = operand.top();
            operand.pop();
            if (tokens[i] == "+")
            {
                num = num1 + num2;
            }
            else if (tokens[i] == "-")
            {
                num = num1 - num2;
            }
            else if (tokens[i] == "*")
            {
                num = num1 * num2;
            }
            else
            {
                num = num1 / num2;
            }
            operand.push(num);
        }
    }
    int ans = operand.top();
    operand.pop();
    return ans;
}

int main()
{
    vector<string> ss = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    cout << evalRPN(ss) << endl;
}