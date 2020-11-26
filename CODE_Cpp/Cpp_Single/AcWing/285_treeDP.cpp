#include <iostream>
#include <cstring>

using namespace std;

const int N = 6010;

int f[N][2], happy[N];
int h[N], ne[N], e[N], idx;
bool has_father[N];

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs(int u)
{
    f[u][1] = happy[u];
    for(int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        dfs(j);
        f[u][0] += max(f[j][0], f[j][1]);
        f[u][1] += f[j][0];
    }
}

int main()
{
    memset(h, -1, sizeof h);
    
    int n;
    cin >> n;
    
    for(int i = 1; i <= n; i++) cin >> happy[i];
    
    for(int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        has_father[a] = true;
        add(b, a);
    }
    
    //找到根节点
    int root = 0;
    for(int i = 1; i <= n; i++) if(!has_father[i]) root = i;
    
    dfs(root);
    
    cout << max(f[root][0], f[root][1]);
    
    return 0;
}