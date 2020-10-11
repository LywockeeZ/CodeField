#include<iostream>
using namespace std;

const int N = 1e5 + 10, M = 31 * N;
int a[N], son[M][2], idx = 0;

void insert(int x)
{
    int p = 0;
    for(int i = 30; i >= 0; i--)
    {
        int u = x >> i & 1;
        if(!son[p][u]) son[p][u] = ++idx;
        p = son[p][u];
    }
}

int query_xor(int x)
{
    int p = 0, res = 0;
    for(int i = 30; i >= 0; i--)
    {
        int u = x >> i & 1;
        if(son[p][!u]) 
        {
            p = son[p][!u];
            res = 2 * res + 1;
        }
        else 
        {
            p = son[p][u];
            res *= 2;
        }
    }

    return res;
}

int main()
{
    int n, res = 0;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        insert(a[i]);
    }

    for(int i = 0; i < n; i++) res = max(res, query_xor(a[i]));

    cout << res;

    return 0;
}