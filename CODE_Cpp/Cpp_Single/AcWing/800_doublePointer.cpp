#include<iostream>
#include<cstdio>
using namespace std;

const int N = 1e5 + 10;
long int a[N], b[N], x;
int n, m;

int main()
{
    cin >> n >> m >> x;
    for(int i = 0; i < n ; i++) scanf("%d", &a[i]);
    for(int i = 0; i < m ; i++) scanf("%d", &b[i]);

    //二分查找：在第二个序列中查找 x - a[i]
    //int i, j;
    // for(i = 0, j = 0; i < n ; i++)
    // {
    //     if(a[i] + b[0] <= x && a[i] + b[m -1] >= x)
    //     {
    //         int t = x - a[i], l = 0, r = m - 1;
    //         while(l < r)
    //         {
    //             int mid = l + r >> 1; 
    //             if(b[mid] >= t) r = mid;
    //             else l = mid + 1;
    //         }
    //         if(b[l] == t) {j = l; break;}
    //     }
    // }

    //双指针
    for(int i = 0, j = m - 1; i < n; i++)
    {
        while(j >= 0 && a[i] + b[j] > x) j--;
        if(j >= 0 && a[i] + b[j] == x) cout << i << " " << j << endl;
    }

    return 0;
}