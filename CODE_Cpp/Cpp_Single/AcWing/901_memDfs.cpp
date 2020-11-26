#include <iostream>
#include <cstring>

using namespace std;

const int N = 310;

int f[N][N], h[N][N];
int r, c;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

int dp(int x, int y)
{
    int &v = f[x][y];
    if(v != -1) return v;
    
    //当周围都不能走时，长度为1
    v = 1;
    for(int i = 0; i < 4; i++)
    {
        int a = x + dx[i], b = y + dy[i];
        if(a >= 1 && a <= r && b >= 1 && b <= c && h[x][y] > h[a][b])
            v = max(v, dp(a, b) + 1);
    }
        
    return v;
}

int main()
{
    cin >> r >> c;
    
    for(int i = 1; i <= r; i++)
        for(int j = 1; j <= c; j++)
            cin >> h[i][j];
    
    memset(f, -1, sizeof f);
    
    int res = 0;
    for(int i = 1; i <= r; i++)
        for(int j = 1; j <= c; j++)
            res = max(res, dp(i, j));
    
    cout << res << endl;
    
    return 0;
}