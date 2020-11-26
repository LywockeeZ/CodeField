#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 1e5 + 10;

struct Range
{
    int l, r;
    bool operator < (const Range &w) const
    {
        return l < w.l;
    }
}ranges[N];

int main()
{
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++) cin >> ranges[i].l >> ranges[i].r;
    
    sort(ranges, ranges + n);
    
    //用小顶堆，方便获取最小的max_r
    priority_queue<int, vector<int>, greater<int>> heap;
    for(int i = 0; i < n; i++)
    {
        auto range = ranges[i];
        if(heap.empty() || heap.top() > range.l) heap.push(range.r);
        else
        {
            heap.pop();
            heap.push(range.r);
        }
    }
    
    cout << heap.size();
    
    return 0;
}
