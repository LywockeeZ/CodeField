#include <iostream>
#include <cstring>

using namespace std;

const int N = 20, M = 1 << N;
int f[M][N], w[N][N];

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> w[i][j];
    
    memset(f, 0x3f, sizeof f);
    //第一个点，经过他自己到他自己，状态的第一位为1，所以为f[1][0]
    f[1][0] = 0;
    //枚举所有状态
    for(int i = 1; i < 1 << n; i++)
        for(int j = 0; j < n; j++)
            //到达j点，第j位包含j才有意义
            if(i >> j & 1)
                for(int k = 0; k < n; k++)
                    //到j的所有路径除去j这点，经过k的路径
                    //前面已经保证j这位一定为1，现在检查k位
                    if(i >> k & 1)
                        f[i][j] = min(f[i][j], f[i - (1 << j)][k] + w[k][j]);
                        
    cout << f[(1 << n) - 1][n - 1] << endl;
    
    return 0;
}