#include <iostream>
#include <string>

using namespace std;

//不应该从两边向中间逼近，而应该从中间向两边逼近，如果中间的不是那么两边的都不是了

int count = 0;

void checkPalindrome(string s, int i, int j)
{
    while (i >= 0 && j < s.size() && s[i] == s[j])
    {
        count++;
        i--;
        j++;
    }
}

int countSubstrings(string s)
{
    int len = s.size();
    if (len == 0)
        return 0;
    for (int i = 0; i < len; i++)
    {
        checkPalindrome(s, i, i);
        checkPalindrome(s, i, i + 1);
    }
    return count;
}

int main()
{
    string s = "bbccaacacdbdbcbcbbbcbadcbdddbabaddbcadb";
    cout << countSubstrings(s) << endl;
}