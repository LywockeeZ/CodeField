#include<iostream>
#include<cstdio>
using namespace std;

const int N = 1e5 + 10;
int a[N], q[N];

int main()
{
    int n, k;
    cin >> n >> k;

    int hh = 0, tt = -1;
    for(int i = 0; i < n; i++) 
    {
        scanf("%d", &a[i]);

        //队列中放的是下标，用来判断第i个元素放入是否使框满
        if(hh <= tt && i - k + 1 > q[hh]) hh++;

        while(hh <= tt && a[q[tt]] >= a[i]) tt--;
        q[++tt] = i;
        if(i >= k - 1) cout << a[q[hh]] << ' ';
    }

    cout << endl;

    hh = 0, tt = -1;
    for(int i = 0; i < n; i++) 
    {
        scanf("%d", &a[i]);

        if(hh <= tt && i - k + 1 > q[hh]) hh++;

        while(hh <= tt && a[q[tt]] <= a[i]) tt--;
        q[++tt] = i;
        if(i >= k - 1) cout << a[q[hh]] << ' ';
    }


    
    return 0;
}