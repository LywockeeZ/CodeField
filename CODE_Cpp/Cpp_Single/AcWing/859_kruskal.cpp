#include <iostream>
#include <algorithm>

using namespace std;

const int N = 200010, INF = 0x3f3f3f3f;

int p[N];
int n, m;

struct Edge
{
    int a, b, w;
    bool operator < (const Edge &W) const
    {
        return w < W.w;
    }
}edges[N];


int find(int x)
{
    if(x != p[x]) p[x] = find(p[x]);
    
    return p[x];
}


int kruskal()
{
    int res = 0, cnt = 0;
    
    sort(edges, edges + m);
    
    for(int i = 0; i < m; i++)
    {
        int a = edges[i].a, b = edges[i].b, w = edges[i].w;
        if(find(a) != find(b))
        {
            p[find(b)] = find(a);
            res += w;
            cnt++;
        }
    }
    //n个点的生成树一定有n - 1条边，如果不够说明有到达不了的点
    if(cnt < n - 1) return INF;
    
    return res;
}


int main()
{
    cin >> n >> m;
    
    for(int i = 1; i <= n; i++) p[i] = i;
    
    for(int i = 0; i < m; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        edges[i].a = a, edges[i].b = b, edges[i].w = w;
    }
    
    int t = kruskal();
    
    if(t == INF) cout << "impossible" << endl;
    else cout << t << endl;
    
    return 0;
}