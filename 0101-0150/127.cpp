#include <iostream>
#include <queue>
#include <vector>
using namespace std;

//使用广度优先搜索

bool isAdjacent(string &A, string &B)
{
    int once = false;
    for (int i = 0; i < A.size(); i++)
    {
        if (A.at(i) != B.at(i))
        {
            if (once)
                return false;
            else
                once = true;
        }
    }
    return true;
}

int ladderLength(string beginWord, string endWord, vector<string> &wordList)
{
    int size = wordList.size();
    bool visited[size];
    int ans = 0;
    bool once = false;
    for (int i = 0; i < size; i++)
    {
        visited[i] = false;
        if (!once && wordList[i] == endWord)
            once = true;
    }
    if (!once)
        return 0;

    string cur;
    string first = beginWord;
    queue<string> Q;
    Q.push(beginWord);
    while (!Q.empty())
    {
        cur = Q.front();
        Q.pop();

        if (cur == first)
        {
            ans++;
            first = "";
        }
        if (cur == endWord)
            return ans;

        for (int i = 0; i < size; i++)
        {
            if (!visited[i] && isAdjacent(cur, wordList[i]))
            {
                if (first == "")
                    first = wordList[i];

                Q.push(wordList[i]);
                visited[i] = true;
            }
        }
    }
    return 0;
}

int main()
{
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log"};
    cout << ladderLength(beginWord, endWord, wordList) << endl;
}