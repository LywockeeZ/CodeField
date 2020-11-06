#include <iostream>
#include <cstring>

using namespace std;

const int N = 510, M = 10010;

int dist[N], backup[N];
int n, m, k;

struct Edge
{
    int a, b, w;
}edges[M];

int bellman_ford()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    
    //从一点开始，一次扩展一条边的网状扩展，
    for(int i = 0; i < k; i++)
    {
        memcpy(backup, dist, sizeof dist);
        for(int j = 0; j < m; j++)
        {
            int a = edges[j].a, b = edges[j].b, w = edges[j].w;
            dist[b] = min(dist[b], backup[a] + w);
        }
    }
    
    if(dist[n] > 0x3f3f3f3f / 2) return -1;
    
    return dist[n];
}

int main()
{
    cin >> n >> m >> k;
    
    for(int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edges[i].a = a, edges[i].b = b, edges[i].w = c;
    }
    
    int t = bellman_ford();
    if(t == -1) cout << "impossible" << endl;
    else cout << t;
    
    return 0;
}