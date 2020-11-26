#include <iostream>
#include <algorithm>

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
    int st, ed, n;
    cin >> st >> ed >> n;
    
    for(int i = 0; i < n; i++) cin >> ranges[i].l >> ranges[i].r;
    
    sort(ranges, ranges + n);
    
    int res = 0;
    bool success = false;
    for(int i = 0; i < n; i++)
    {
        int j = i, r = -2e9;
        //找到第一个不满足条件的
        while(j < n && ranges[j].l <= st)
        {
            r = max(r, ranges[j].r);
            j++;
        }
        
        //如果左边小于起点的最大右边仍小于起点，则找不到
        if(r < st)
        {
            res = -1;
            break;
        }
        
        res++;
        
        if(r >= ed)
        {
            success = true;
            break;
        }
        
        i = j - 1;
        st = r;
    }
    
    if(!success) res = -1;

    cout << res;
    
    return 0;
}