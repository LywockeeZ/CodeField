#include <iostream>
#include <cstring>

using namespace std;

const int N = 510;

int dist[N];
int g[N][N];
bool st[N];
int m, n;

int dijkstra()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    //每个点都迭代一遍
    for(int i = 0; i < n; i++)
    {
        int t = -1;
        for(int j = 1; j <= n; j++)//从第一个点开始到第n个点进行比较
            if(!st[j] && (t == -1 || dist[t] > dist[j]))//先找出未标记中的最小的
                t = j;
        
        //用t更新一下到每个点的最短距离
        for(int j = 1; j <= n; j++)
            dist[j] = min(dist[j], dist[t] + g[t][j]);

        st[t] = true;
    }

    if(dist[n] == 0x3f3f3f3f) return -1;
    else return dist[n];

}

int main()
{
    memset(g, 0x3f, sizeof g);
    cin >> n >> m;

    while(m --)
    {
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = min(g[a][b], c);
    }

    int t = dijkstra();
    cout << t;

    return 0;
}