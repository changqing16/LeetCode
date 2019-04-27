#include <iostream>
#include <string>
using namespace std;

bool isIsomorphic(string s, string t)
{
    char ying[127];
    bool used[127];
    for (int i = 0; i < 127; i++)
    {
        ying[i] = 0;
        used[i] = false;
    }

    for (int i = 0; i < s.length(); i++)
    {
        if (ying[s.at(i)] == t.at(i) || (ying[s.at(i)] == 0 && used[t.at(i)] == false))
        {
            ying[s.at(i)] = t.at(i);
            used[t.at(i)] = true;
        }
        else
            return false;
    }
    return true;
}

int main()
{
    string s1 = "add";
    string s2 = "egg";
}