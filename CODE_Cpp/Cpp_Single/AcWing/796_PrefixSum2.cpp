#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

const int N = 1000 + 10;
int a[N][N], s[N][N], n, m, q;
vector<int> res;

int main()
{
    cin >> n >> m >> q;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            scanf("%d", &a[i][j]);
            s[i][j] = s[i][j - 1] + s[i - 1][j] - s[i - 1][j - 1]+ a[i][j];
        }
    }

    int x1, x2, y1, y2;
    for(int i = q; i > 0; i--)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        res.push_back(s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1]);
    }

    for(int i = 0; i < res.size(); i++) cout << res[i] << endl;

    return 0;
}