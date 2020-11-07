#include <iostream>
#include <cstring>

using namespace std;

const int N = 510, INF = 0X3f3f3f3f;
//这里dist存放的是点到集合的距离
int dist[N], g[N][N];
int n, m;
bool st[N];


int prim()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    int res = 0;
    
    for(int i = 0; i < n; i++)
    {
        int t = -1;
        for(int j = 1; j <= n; j++)
            if(!st[j] && ((t == -1) || dist[t] > dist[j]))
                t = j;
        
        if(i && dist[t] == INF) return INF;
        if(i) res += dist[t];

        st[t] = true;
        
        for(int j = 1; j <=n ; j++) dist[j] = min(dist[j], g[t][j]);
    }
    
    return res;
}


int main()
{
    memset(g, 0x3f, sizeof g);
    cin >> n >> m;
    
    while(m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = g[b][a] = min(g[a][b], c);
    }
    
    int t = prim();
    
    if(t == INF) cout << "impossible" << endl;
    else cout << t << endl;
    
    return 0;
}