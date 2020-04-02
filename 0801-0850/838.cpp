#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

string pushDominoes(string dominoes)
{
    int start = 0;
    for (int i = 1; i < dominoes.size(); i++)
    {
        if (dominoes[i] == 'R')
        {
            if (dominoes[start] == 'R')
            {
                for (int j = start + 1; j < i; j++)
                {
                    dominoes[j] = 'R';
                }
            }
            start = i;
        }
        else if (dominoes[i] == 'L')
        {
            if (dominoes[start] == 'R') //先中间走
            {
                int left = start + 1, right = i - 1;
                while (left < right)
                {
                    dominoes[left++] = 'R';
                    dominoes[right--] = 'L';
                }
            }
            else
            {
                for (int j = start; j < i; j++)
                {
                    dominoes[j] = 'L';
                }
            }
            start = i;
        }
    }
    if (dominoes[start] == 'R')
    {
        for (int j = start + 1; j < dominoes.size(); j++)
        {
            dominoes[j] = 'R';
        }
    }
    return dominoes;
}

int main()
{
    string s = ".L.R...LR..L..";
    cout << pushDominoes(s) << endl;
}