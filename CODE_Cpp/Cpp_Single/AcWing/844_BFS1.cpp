#include<iostream>
#include<cstring>
using namespace std;

typedef pair<int , int> PII;

const int N = 110;
int g[N][N], st[N][N], hh = 0, tt = 0;
int m, n;

int bfs()
{
    PII q[N * N];
    q[0] = {0, 0};
    st[0][0] = 0;

    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

    while(hh <= tt)
    {
        auto t = q[hh++];
        for(int i = 0; i < 4; i++)
        {
            int x = t.first + dx[i], y = t.second + dy[i];
            if(x >= 0 && x < n && y >= 0 && y < m && g[x][y] == 0 && st[x][y] == -1)
            {
                q[++tt] = {x, y};
                st[x][y] = st[t.first][t.second] + 1;
            }
        }
    }

    return st[n - 1][m - 1];
}

int main()
{
    memset(st, -1, sizeof st);

    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> g[i][j];

    cout << bfs() << endl;
    return 0;
}