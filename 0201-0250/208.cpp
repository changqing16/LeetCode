#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class Tree
{
public:
    bool end = false;
    Tree *next[26] = {NULL};
    Tree(bool flag)
    {
        end = flag;
    }
};
class Trie
{
private:
    Tree *root;
    Tree *find(const string &word)
    {
        Tree *cur = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (cur->next[word[i] - 'a'] == NULL)
                return NULL;
            cur = cur->next[word[i] - 'a'];
        }
        return cur;
    }

public:
    /** Initialize your data structure here. */
    Trie()
    {
        root = new Tree(false);
    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        Tree *cur = root;
        for (char c : word)
        {
            if (cur->next[c - 'a'] == NULL)
                cur->next[c - 'a'] = new Tree(false);
            cur = cur->next[c - 'a'];
        }
        cur->end = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        Tree *cur = find(word);
        if (cur != NULL && cur->end == true)
            return true;
        return false;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        Tree *cur = find(prefix);
        if (cur != NULL)
            return true;
        return false;
    }
};