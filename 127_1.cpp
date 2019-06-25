#include <cstring>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

//还是那个快呀！ 127_c.cpp


int L;
unordered_map<string, vector<string>> allComboDict;

int visitWordNode(queue<pair<string, int>> &Q, unordered_map<string, int> &visited, unordered_map<string, int> &othersVisited)
{
    auto node = Q.front();
    Q.pop();
    string word = node.first;
    int level = node.second;

    for (int i = 0; i < L; i++)
    {
        string newWord = word.substr(0, i) + '*' + word.substr(i + 1, L);
        if (allComboDict.count(newWord) == 0)
            allComboDict.insert({newWord, vector<string>()});
        for (string adjacentWord : allComboDict.at(newWord))
        {
            if (othersVisited.count(adjacentWord) != 0)
            {
                return level + othersVisited.at(adjacentWord);
            }

            if (visited.count(adjacentWord) == 0)
            {
                visited.insert({adjacentWord, level + 1});
                Q.push({adjacentWord, level + 1});
            }
        }
    }
    return -1;
}
int ladderLength(string beginWord, string endWord, vector<string> &wordList)
{
    bool once = false;
    for (int i = 0; i < wordList.size(); i++)
    {
        if (endWord == wordList[i])
        {
            once = true;
            break;
        }
    }
    if (!once)
        return 0;
    L = beginWord.size();
    for (string word : wordList)
    {
        for (int i = 0; i < L; i++)
        {
            string newWord = word.substr(0, i) + '*' + word.substr(i + 1, L);
            if (allComboDict.count(newWord) == 0)
                allComboDict.insert({newWord, vector<string>()});
            allComboDict.at(newWord).push_back(word);
        }
    }
    queue<pair<string, int>> Q_begin;
    queue<pair<string, int>> Q_end;
    Q_begin.push({beginWord, 1});
    Q_end.push({endWord, 1});

    unordered_map<string, int> visitedBegin;
    unordered_map<string, int> visitedEnd;
    visitedBegin.insert({beginWord, 1});
    visitedEnd.insert({endWord, 1});

    while (!Q_begin.empty() && !Q_end.empty())
    {
        int ans = visitWordNode(Q_begin, visitedBegin, visitedEnd);
        if (ans > -1)
            return ans;

        ans = visitWordNode(Q_end, visitedEnd, visitedBegin);
        if (ans > -1)
            return ans;
    }
    return 0;
}
int main()
{
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    cout << ladderLength(beginWord, endWord, wordList) << endl;
}