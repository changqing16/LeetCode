#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

int mod = 1000000007;
const int dx[4] = {1, 0, 0, -1};
const int dy[4] = {0, 1, -1, 0};
struct pairhash
{
public:
    template <typename T, typename U>
    std::size_t operator()(const std::pair<T, U> &x) const
    {
        return std::hash<T>()(x.first) ^ std::hash<U>()(x.second);
    }
};
struct min_heap_cmp
{
    bool operator()(pair<int, int> &a, pair<int, int> &b)
    {
        return a > b;
        //return a.second > b.second;
    }
};

static bool cmp(const pair<int, int> &x, const pair<int, int> &y)
{
    return x.second < y.second; //sort中是升序
}

//并查集
vector<int> fa;

int find(int x)
{
    return x == fa[x] ? x : (fa[x] = find(fa[x]));
}

void merge(int i, int j)
{
    fa[find(i)] = find(j);
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string str;
    getline(cin, str); //读入一行

    unordered_map<pair<int, int>, int, pairhash> hahs_map;

    priority_queue<int, vector<int>, greater<int>> min_heap1;
    priority_queue<pair<int, int>, vector<pair<int, int>>, min_heap_cmp> min_heap2;
}

int get(int n, int m)
{
    vector<vector<float>> dp(n + 1, vector<float>(m + 1));
    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            dp[i][j] += (float)i / (i + j); //A取红球
            if (j > 1)                      //C取红球
                dp[i][j] += (float)j / (i + j) * (j - 1) / (i + j - 1) * i / (i + j - 2) * dp[i - 1][j - 2];

            if (j > 2) //C取蓝球
                dp[i][j] += (float)j / (i + j) * (j - 1) / (i + j - 1) * (j - 2) / (i + j - 2) * dp[i][j - 3];
        }
    }
    return dp[n][m];
}

void swap(int *array, int pos_i, int pos_j)
{
    int tmp = array[pos_i];
    array[pos_i] = array[pos_j];
    array[pos_j] = tmp;
}
int partition(int *array, int begin, int end);
// 尾递归版 这个可以减少栈空间的使用
void quick_sort_tail(int *array, int begin, int end)
{
    while (begin < end)
    {
        int r = partition(array, begin, end);
        quick_sort_tail(array, begin, r - 1);
        begin = r + 1;
    }
}

int partition(int *array, int begin, int end)
{
    // 在 begin 到 end 间随机找一个数 当 划分用的 key
    int rand_location = rand() % (end - begin + 1) + begin;
    int key = array[rand_location];
    // 把这个 key 移到 end 的位置，方便做双下标前移动
    swap(array, rand_location, end);
    int i = begin - 1;
    for (int j = begin; j < end; ++j)
    {
        if (array[j] <= key)
        {
            i++;
            swap(array, i, j);
        }
    }
    swap(array, i + 1, end);
    return i + 1;
}

void heapify(vector<int> &arr, int n, int i)
{
    int largest = i;   // 将最大元素设置为堆顶元素
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2

    // 如果 left 比 root 大的话
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // I如果 right 比 root 大的话
    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);

        // 递归地定义子堆
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int> &arr, int n)
{
    // 建立堆
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // 一个个从堆顶取出元素
    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int upper_bound(vector<int> &nums, int target, int s, int e) //返回第一个大于target的元素，其中e是取不到的
{
    int mid;
    while (s < e)
    {
        mid = s + (e - s) / 2;
        if (nums[mid] <= target)
            s = mid + 1;
        else
            e = mid;
    }
    return s;
}
int lower_bound(vector<int> &nums, int target, int s, int e) //返回第一个大于target的元素，其中e是取不到的
{
    int mid;
    while (s < e)
    {
        mid = s + (e - s) / 2;
        if (nums[mid] < target)
            s = mid + 1;
        else
            e = mid;
    }
    return s;
}