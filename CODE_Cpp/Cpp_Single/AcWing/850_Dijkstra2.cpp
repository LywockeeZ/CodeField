#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

typedef pair<int, int> PII;

const int N = 150010;
int n, m;
int e[N], ne[N], h[N], w[N], idx;
int dist[N];
bool st[N];

void add(int a, int b, int c)
{
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

int dijkstra()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    //建立小顶堆,堆中存放的是从1号点到某点的距离及该点的编号组成的对
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, 1});
    
    while(heap.size())
    {
        auto t = heap.top();
        heap.pop();
        
        int var = t.second, distance = t.first;
        if(st[var]) continue;
        st[var] = true;
        
        //在该点能到达的所有点中更新距离
        for(int i = h[var]; i != -1; i = ne[i])
        {   
            int j = e[i];
            if(dist[j] > distance + w[i])
            {
                dist[j] = distance + w[i];
                heap.push({dist[j], j});
            }
        }
    }
    
    if(dist[n] == 0x3f3f3f3f) return -1;
    
    return dist[n];
}

int main()
{
    memset(h, -1, sizeof h);
    
    cin >> n >> m;
    
    while(m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }
    
    cout << dijkstra();
    
    return 0;
}