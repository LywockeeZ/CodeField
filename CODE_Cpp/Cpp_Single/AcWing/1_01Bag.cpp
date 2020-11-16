#include <iostream>

using namespace std;

const int N = 1010;

int f[N], v[N], w[N];
int n, m;

int main()
{
    cin >> n >> m;
    
    for(int i = 1; i <= n; i++) cin >> v[i] >> w[i];
    
    //朴素版本，未优化，速度很慢
    /*
    for(int i = 1; i <= n; i++)
        for(int j = 0; j <= m; j++)
        {
            f[i][j] = f[i - 1][j];
            if(j >= v[i]) f[i][j] = max(f[i][j], f[i - 1][j - v[i]] + w[i]);
        }
    */
    
    //优化到一维，利用滚动数组，如果j从小到大更新，计算i-1层时，前面已经被更新
    //计算会出错，所以j应从后向前遍历，这样每次计算i-1，都用的是前面未更新的数
    for(int i = 1; i <= n; i++)
        for(int j = m; j >= v[i]; j--)
            f[j] = max(f[j], f[j - v[i]] + w[i]);
            
    cout << f[m];
    
    return 0;
}