#include<iostream>
#include<cstring>
using namespace std;

const int N = 10;
int n, col[N], dg[N * 2], udg[N * 2];
char g[N][N];

void dfs(int u)
{
    if(u == n)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
                cout << g[i][j];
            cout << endl;
        }
        cout << endl;
        return;
    }

    for(int i = 0; i < n; i++)
    {
        if(!col[i] && !dg[u + i] && !udg[n - u + i])
        {
            col[i] = dg[u + i] = udg[n - u + i] = 1;
            g[u][i] = 'Q';
            dfs(u + 1);
            g[u][i] = '.';
            col[i] = dg[u + i] = udg[n - u + i] = 0;
        }
    }
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            g[i][j] = '.';
    dfs(0);
    return 0;;
}