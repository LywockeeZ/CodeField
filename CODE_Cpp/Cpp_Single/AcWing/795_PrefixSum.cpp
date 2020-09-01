#include<iostream>
#include<vector>
using namespace std;

const int N = 1e5 + 10;
int a[N], s[N], n, m;
vector<int> res;

int main()
{
    cin >> n >> m ;
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        s[i] = s[i - 1] + a[i];
    }

    int l, r;
    for(int i = m; i > 0; i--)
    {
        cin >> l >> r ;
        res.push_back(s[r] - s[l - 1]);
    }

    for(int i = 0; i < res.size(); i++) cout << res[i] << endl;

    return 0;
}