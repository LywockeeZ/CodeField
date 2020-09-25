#include<iostream>
#include<cstring>

using namespace std;

const int N = 100010;
int h[N], ne[N], e[N], idx = 0;
int n, m;

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int bfs()
{
    int q[N], d[N], hh = 0, tt = -1;
    memset(d, -1, sizeof d);

    q[++tt] = 1;
    d[1] = 0;

    while(hh <= tt)
    {
        int t = q[hh++];
        for(int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if(d[j] == -1)
            {
                q[++tt] = j;
                d[j] = d[t] + 1;
            }
        }
    }

    return d[n];
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

    cout << bfs() << endl;
    return 0;
}