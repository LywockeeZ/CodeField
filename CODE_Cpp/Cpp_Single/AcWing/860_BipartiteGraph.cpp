#include <iostream>
#include <cstring>

using namespace std;

const int N = 2e5 + 10;

int h[N], ne[N], e[N], idx = 0;
int color[N];
int n, m;

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

bool dfs(int u, int c)
{
    //先将自己染色
    color[u] = c;
    //然后将相邻的未染色的边依次染色
    for(int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        //如果未染色则染色，染了色则判定是否矛盾
        if(!color[j])
        {
            if(!dfs(j, 3 - c)) return false;
        }
        else if(color[j] == c) return false;
    }
    return true;
}


int main()
{
    memset(h, -1, sizeof h);
    cin >> n >> m;
    
    while(m --)
    {
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a);
    }
    
    bool flag = false;
    
    for(int i = 1; i <= n; i++)
    {
        if(!color[i])
        {
            if(!dfs(i, 1))
            {
                flag = true;
                break;
            }
        }
    }
    
    if(!flag) cout << "Yes";
    else cout << "No";
    
    return 0;
}