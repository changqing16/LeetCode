#include <iostream>
#include <string>
#include <vector>

using namespace std;
int minDistance(string word1, string word2)
{
    if (word1.size() < word2.size())
    {
        string tmp = word1;
        word1 = word2;
        word2 = tmp;
    }
    int prev, tmp;

    vector<int> hp(word2.size() + 1, 0);

    for (int i = 1; i <= word1.size(); i++)
    {
        prev = 0;
        for (int j = 1; j <= word2.size(); j++)
        {
            tmp = hp[j];
            if (word1[i - 1] == word2[j - 1])
                hp[j] = prev + 1;
            else
                hp[j] = max(hp[j - 1], hp[j]);

            prev = tmp;
        }
    }
    cout << hp[word2.size()] << endl;
    return word1.size() + word2.size() - 2 * hp[word2.size()];
}

int main()
{
    string word1 = "mark";
    string word2 = "karma";
    cout << minDistance(word1, word2) << endl;
    return 0;
}