#include <iostream>
#include <string.h>

using namespace std;

const int N = 1010;

int f[N][N], limit;
char str[N][N];

int edit_dist(char *a, char *b)
{
    //注意初始化是从1开始的，所以长度也要从一开始计算，否则会多一个
    int n = strlen(a + 1), m = strlen(b + 1);
    for(int i = 1; i <= n; i++) f[i][0] = i;
    for(int i = 1; i <= m; i++) f[0][i] = i;
    
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
        {
            f[i][j] = min(f[i - 1][j] + 1, f[i][j - 1] + 1);
            f[i][j] = min(f[i][j], f[i - 1][j - 1] + (a[i] != b[j]));
        }
    return f[n][m];
}

int main()
{
    int n, m;
    cin >> n >> m;
    
    for(int i = 0; i < n; i++) cin >> str[i] + 1;
    
    while(m--)
    {
        char s[N];
        cin >> s + 1 >> limit;
        
        int res = 0;
        for(int i = 0; i < n; i++)
            if(edit_dist(str[i], s) <= limit) res++;
        cout << res << endl;
    }
    
    return 0;
}