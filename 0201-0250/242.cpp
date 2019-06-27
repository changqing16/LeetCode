#include <iostream>
#include <string.h>
#include <string>
using namespace std;

bool isAnagram(string s, string t)
{
    if (s.length() != t.length())
        return false;
    int arr[26] = {0};

    for (int i = 0; i < s.length(); i++)
    {
        arr[s.at(i) - 'a']++;
        arr[t.at(i) - 'a']--;
    }
    for (int i = 0; i < 26; i++)
        if (arr[i] != 0)
            return false;

    return true;
}