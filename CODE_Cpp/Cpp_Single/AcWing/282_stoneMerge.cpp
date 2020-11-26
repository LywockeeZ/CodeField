#include <iostream>

using namespace std;

const int N = 310, INF = 1e8;
int f[N][N], s[N];

int main()
{
    int n;
    cin >> n;
    
    //计算前缀和
    for(int i = 1; i <= n; i++)
    {
        cin >> s[i];
        s[i] += s[i - 1];
    }
    
    for(int len = 2; len <= n; len++)
        for(int i = 1; i + len - 1 <= n; i++) //要遍历所有区间，所以要滑动窗口
        {
            int l = i, r = i + len - 1;
            f[l][r] = INF;
            for(int k = l; k < r; k++)
                f[l][r] = min(f[l][r], f[l][k] + f[k + 1][r] + s[r] - s[l - 1]);
        }
        
    cout << f[1][n];
    
    return 0;
}