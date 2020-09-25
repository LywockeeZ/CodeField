#include<iostream>
#include<cstring>

using namespace std;

const int N = 100010, M = 2 * N;
int h[N], e[M], ne[M], idx = 0;
int ans = N, n;
bool st[N];

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

//返回第u个节点为根节点的树中，结点的个数
int dfs(int u)
{
    st[u] = true;

    int sum = 1, res = 0;

    for(int i = h[u]; i != -1; i = ne[i])
    {
        int s, j = e[i];
        if(!st[j])
        {
            s = dfs(j);
            sum += s;
            res = max(s, res);
        }
    }
    res = max(res, n - sum);
    ans = min(res, ans);

    return sum;
}

int main()
{
    memset(h, -1, sizeof h);

    cin >> n;
    for(int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a);
    }

    dfs(1);

    cout << ans << endl;

    return 0;
}