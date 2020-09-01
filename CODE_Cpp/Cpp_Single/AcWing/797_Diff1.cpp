#include<iostream>
#include<cstdio>
using namespace std;

const int N = 1e5 + 10;
int b[N], n, m;

void insert(int l, int r, int c)
{
    b[l] += c;
    b[r + 1] -= c;
}

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++) 
    {
        int t;
        scanf("%d", &t);
        insert(i, i, t);
    }

    int l, r, c;
    while(m--)
    {
        cin >> l >> r >> c;
        insert(l, r, c);
    }

    for(int i = 1; i <= n ; i++)
    {
        b[i] += b[i - 1];
        printf("%d ", b[i]);
    } 
    
    return 0;
}