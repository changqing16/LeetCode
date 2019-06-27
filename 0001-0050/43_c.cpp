#include <string>
using namespace std;
class Solution
{
  public:
    string multiply(string num1, string num2)
    {
        string result(num1.length() + num2.length(), '0');
        for (int i = num1.length() - 1; i >= 0; i--)
        {
            int carry = 0;
            for (int j = num2.length() - 1; j >= 0; j--)
            {
                int tmp = result[i + j + 1] - '0' + (num1[i] - '0') * (num2[j] - '0') + carry;
                result[i + j + 1] = '0' + tmp % 10;
                carry = tmp / 10;
            }
            result[i] += carry;
        }
        while (result.length() > 1 && result[0] == '0')
            result = result.substr(1, result.length() - 1);

        return result;
    }
};