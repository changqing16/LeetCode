#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

struct List
{
    int key;
    int value;
    List *prev;
    List *next;
    List(int x, int y) : key(x), value(y), prev(NULL), next(NULL) {}
};

class LRUCache
{
private:
    unordered_map<int, List *> items;
    int capacity_;
    int size;
    List *head;
    List *end;

    void move(List *cur)
    {
        cur->prev->next = cur->next;
        if (cur == end)
        {
            end = cur->prev;
            end->next = NULL;
        }
        else
            cur->next->prev = cur->prev;

        cur->next = head;
        head->prev = cur;
        cur->prev = NULL;
        head = cur;
    }

public:
    LRUCache(int capacity)
    {
        capacity_ = capacity;
        size = 0;
        head = NULL;
        end = NULL;
    }

    int get(int key)
    {
        if (items.count(key) == 0)
            return -1;
        List *cur = items[key];
        if (cur != head)
            move(cur);
        return head->value;
    }

    void put(int key, int value)
    {
        List *cur;

        List *tmp;
        if (items.count(key) != 0)
        {
            cur = items[key];
            cur->value = value;
            if (cur != head)
                move(cur);
            return;
        }

        cur = new List(key, value);
        items[key] = cur;
        cur->next = head;
        if (head != NULL)
            head->prev = cur;
        head = cur;

        if (size < capacity_)
        {
            size++;
            if (end == NULL)
                end = cur;
        }
        else
        {
            tmp = end->prev;
            items.erase(end->key);
            delete end;
            end = tmp;
            end->next = NULL;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */