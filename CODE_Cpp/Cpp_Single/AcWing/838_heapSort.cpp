#include<iostream>
#include<cstdio>
using namespace std;

const int N = 100010;
int h[N], siz = 0;

void heap_swap(int a, int b)
{
    swap(h[a], h[b]);
}

void down(int x)
{
    int t = x;
    if(x * 2 <= siz && h[x] > h[x * 2]) t = x * 2;
    if(x * 2 + 1 <= siz && h[t] > h[x * 2 + 1]) t = x * 2 + 1;
    if(t != x)
    {
        heap_swap(t, x);
        down(t);
    }
}

void up(int x)
{
    while(x / 2 && h[x / 2] > h[x])
    {
        heap_swap(x, x / 2);
        x >>= 1;
    }
}

int main()
{
    int n, m;

    cin >> n >> m;
    for(int i = 1; i <= n; i++) scanf("%d", &h[i]);
    siz = n;

    for(int i = n / 2; i; i--) down(i);

    while(m--)
    {
        cout << h[1] << ' '; 
        h[1] = h[siz--];
        down(1);
    }
    return 0;
}