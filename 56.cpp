#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Interval
{
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

static bool cmp(const Interval &a, const Interval &b)
{
    return a.start < b.start;
}

vector<Interval> merge(vector<Interval> &intervals)
{
    vector<Interval> ans;
    if (intervals.size() == 0)
        return ans;
    sort(intervals.begin(), intervals.end(), cmp);
    ans.push_back(Interval(intervals[0].start, intervals[0].end));
    int length = 0;
    for (int i = 1; i < intervals.size(); i++)
    {
        if (intervals[i].start > ans[length].end)
        {
            ans.push_back(Interval(intervals[i].start, intervals[i].end));
            length++;
        }
        else
        {
            ans[length].end = max(ans[i].end, intervals[i].end);
        }
    }
    return ans;
}