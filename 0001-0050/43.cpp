#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
using namespace std;

class Solution
{
  public:
    struct bigInteger
    {
        int digit[1000];
        int size;

        void init()
        {
            for (int i = 0; i < 1000; i++)
                digit[i] = 0;
            size = 0;
        }

        void set(string str)
        {
            init();
            int L = str.length();
            for (int i = L - 1, j = 0, t = 0, c = 1; i >= 0; i--)
            {
                t += (str[i] - '0') * c;
                j++;
                c *= 10;
                if (j == 4 || i == 0)
                {
                    digit[size++] = t;
                    j = 0;
                    t = 0;
                    c = 1;
                }
            }
        }

        void output()
        {
            for (int i = size - 1; i >= 0; i--)
            {
                if (i != size - 1)
                    printf("%04d", digit[i]);
                else
                    printf("%d", digit[i]);
            }
            printf("\n");
        }

        string toString()
        {
            char ans[1000];
            int index = 0;
            for (int i = size - 1; i >= 0; i--)
            {
                if (i != size - 1)
                    index += sprintf(ans + index, "%04d", digit[i]);
                else
                    index += sprintf(ans + index, "%d", digit[i]);
            }
            string str = ans;
            return str;
        }

        bigInteger operator+(const bigInteger &A) const
        {
            bigInteger ret;
            ret.init();
            int carry = 0;
            for (int i = 0; i < A.size || i < size; i++)
            {
                int tmp = A.digit[i] + digit[i] + carry;
                carry = tmp / 10000;
                tmp %= 10000;
                ret.digit[ret.size++] = tmp;
            }
            if (carry != 0)
            {
                ret.digit[ret.size++] = carry;
            }
            return ret;
        }

        bigInteger operator*(int x) const
        {
            bigInteger ret;
            ret.init();
            int carry = 0;
            for (int i = 0; i < size; i++)
            {
                int tmp = x * digit[i] + carry;
                carry = tmp / 10000;
                tmp %= 10000;
                ret.digit[ret.size++] = tmp;
            }
            if (carry != 0)
            {
                ret.digit[ret.size++] = carry;
            }
            return ret;
        }

        bigInteger operator*(const bigInteger &A) const
        {
            bigInteger ret;
            ret.init();
            bigInteger tmp;
            int cur;
            for (int i = 0; i < A.size; i++)
            {
                tmp = *this * A.digit[i];
                cur = tmp.size;
                for (int j = cur + i - 1; j >= i; j--)
                    tmp.digit[j] = tmp.digit[j - i];
                for (int j = 0; j < i; j++)
                    tmp.digit[j] = 0;
                tmp.size = cur + i;
                ret = tmp + ret;
            }
            return ret;
        }
    };

    string multiply(string num1, string num2)
    {
        string tmp = "0";
        if (num1 == tmp || num2 == tmp)
            return tmp;
        bigInteger n1, n2, n3;
        n1.set(num1);
        n2.set(num2);
        n3 = n1 * n2;
        string ans = n3.toString();
        return ans;
    }
};

int main()
{
    string num1 = "234635";
    string num2 = "111112345";
    string str = Solution().multiply(num1, num2);
    cout << str << endl;
}
