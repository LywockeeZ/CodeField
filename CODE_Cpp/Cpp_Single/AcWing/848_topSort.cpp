#include<iostream>
#include<cstring>

using namespace std;

const int N = 100010;
int q[N], d[N], e[N], h[N], ne[N], idx;
int n, m;

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
    d[b]++;
}

bool topSort()
{
    int hh = 0, tt = -1;

    for(int i = 1; i <= n; i++)
        if(d[i] == 0) q[++tt] = i;

    while(hh <= tt)
    {
        int t = q[hh++];
        for(int i = h[t]; i != -1; i = ne[i])
        {
            d[e[i]]--;
            if(d[e[i]] == 0) q[++tt] = e[i];
        } 
    }
    //当所有节点都入队，说明存在拓扑序列，否则不存在
    return tt == n - 1; 
}

int main()
{
    memset(h, -1, sizeof h);

    cin >> n >> m;

    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        add(a, b);
    }

    if(topSort())
    {
        for(int i = 0; i < n; i++)
            cout << q[i] << ' ';
    }
    else cout << "-1";
    return 0;
}