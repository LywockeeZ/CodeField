#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;

struct Range
{
    int l, r;
    bool operator < (const Range &w) const
    {
        return r < w.r;
    }
}ranges[N];

int main()
{
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++) cin >> ranges[i].l >> ranges[i].r;
    
    sort(ranges, ranges + n);
    
    int res = 0, ed = -2e9;
    for(auto range : ranges)
        if(range.l > ed) res++, ed = range.r;
        
    cout << res;
    
    return 0;
}