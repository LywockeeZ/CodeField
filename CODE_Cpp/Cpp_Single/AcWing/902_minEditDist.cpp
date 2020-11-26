#include <iostream>

using namespace std;

const int N = 1010;
int f[N][N];
char a[N], b[N];

int main()
{
    int n, m;
    cin >> n >> a + 1;
    cin >> m >> b + 1;
    //注意n，m的位置，第二维是m，第一维是n
    for(int i = 1; i <= m; i++) f[0][i] = i;
    for(int i = 1; i <= n; i++) f[i][0] = i;
    
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
        {
            f[i][j] = min(f[i - 1][j] + 1, f[i][j - 1] + 1);
            f[i][j] = min(f[i][j], f[i - 1][j - 1] + (a[i] != b[j]));
        }
            
    cout << f[n][m];
    
    return 0;
}