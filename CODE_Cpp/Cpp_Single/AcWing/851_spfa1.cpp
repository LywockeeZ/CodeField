#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int N = 150010;
int n, m;
int e[N], ne[N], h[N], w[N], idx;
int dist[N], cnt[N];
bool st[N];

void add(int a, int b, int c)
{
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

bool spfa()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    
    queue<int> q;
    
    for(int i = 1; i <= n; i++)
    {
        q.push(i);
        st[i] = true;
    }
    
    while(q.size())
    {
        int t = q.front();
        q.pop();
        st[t] = false;
        
        for(int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if(dist[j] > dist[t] + w[i])
            {
                dist[j] = dist[t] + w[i];
                cnt[j] = cnt[t] + 1;
                if(cnt[j] >= n) return true;
                if(!st[j])
                {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }
    
    return false;
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
    
    bool t = spfa();
    
    if(t) cout << "Yes";
    else cout << "No";
    
    return 0;
}