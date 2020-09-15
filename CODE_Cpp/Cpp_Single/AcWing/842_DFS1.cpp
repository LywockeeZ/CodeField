#include<iostream>
#include<cstring>
using namespace std;

const int N = 8;
int path[N], b[N], n, idx = 0;

void dfs(int u)
{
    if(u == n) 
    {
        for(int i = 0; i < n; i++) cout << path[i] << ' ';
        cout << endl;
        return;
    }

    for(int i = 1; i <= n; i++)
    {
        if(b[i] != 1)
        {
            b[i] = 1;
            path[u] = i;
            dfs(u + 1);
            path[u] = 0;
            b[i] = 0;
        }
    }
}

int main()
{
    cin >> n;
    dfs(0);
    return 0;
}