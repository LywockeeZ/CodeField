#include <iostream>
#include <cstring>

using namespace std;

const int N = 12, M = 1 << N;

long long f[N][M];
//true代表该状态合法
bool st[M];

int main()
{
    int n, m;
    
    while(cin >> n >> m, n||m)
    {
        memset(f, 0, sizeof f);
        
        //预处理出所有合法状态
        for(int i = 0; i < 1 << n; i++)
        {
            st[i] = true;
            //存储连续0的个数
            int cnt = 0;
            //判断是否有连续奇数个0
            for(int j = 0; j < n; j++)
                //连续的零结束进入
                if(i >> j & 1)
                {
                    //如果是奇数则不合法
                    if(cnt & 1) st[i] = false;
                    cnt = 0;
                }
                else cnt++;
            //对高位都是零的情况的判断
            if(cnt & 1) st[i] = false;
        }
        
        //开始DP
        //第0列应该没有捅进来的，只有一种方案
        f[0][0] = 1;
        for(int i = 1; i <= m; i++)
            //枚举所有状态
            for(int j = 0; j < 1 << n; j++)
                //当前的每个状态都与前一列的每个状态匹配，保留合法匹配数
                for(int k = 0; k < 1 << n; k++)
                    if(!(j & k) && st[j | k]) f[i][j] += f[i - 1][k];
        
        //最后一列的下一列应该没有捅过来的
        cout << f[m][0] << endl;
    }
    
    
}