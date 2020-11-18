#include <iostream>

using namespace std;

const int N = 510, INF = 1e9;

int a[N][N], f[N][N];
int n;

int main()
{
    cin >> n;
    
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= i; j++)
            cin >> a[i][j];
            
    //每次要用左上[i-1][j - 1]和右上[i - 1][j]计算，所以边界要多初始化一行
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= i + 1; j++)
            f[i][j] = -INF;
            
    f[1][1] = a[1][1];
    for(int i = 2; i <= n; i++)
        for(int j = 1; j <= i; j++)
            f[i][j] = max(f[i - 1][j - 1] + a[i][j], f[i - 1][j] + a[i][j]);
            
    int res = -INF;
    for(int i = 1; i <= n; i++) res = max(res, f[n][i]);
    
    cout << res << endl;
    
    return 0;
}