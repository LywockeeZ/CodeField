#include <iostream>

using namespace std;

const int N = 1010;
int f[N], v[N], w[N];
int n, m;

int main()
{
    cin >> n >> m;
    
    for(int i = 1; i <= n; i++) cin >> v[i] >> w[i];
    
    //朴素做法，未优化版，会超时
    /*
    for(int i = 1; i <= n; i++)
        for(int j = 0; j <= m; j++)
            for(int k = 0; v[i] * k <= j; k++)
                //从k个i-1中选出来最大的放到i
                f[i][j] = max(f[i][j], f[i - 1][j - k * v[i]] + k * w[i]);
    */
    
    //优化到一维,利用滚动数组,将这一维中由旧更新到新
    for(int i = 1; i <= n; i++)
        for(int j = v[i]; j <= m; j++)
            f[j] = max(f[j], f[j - v[i]] + w[i]);
                
    cout << f[m] << endl;
    
    return 0;
}