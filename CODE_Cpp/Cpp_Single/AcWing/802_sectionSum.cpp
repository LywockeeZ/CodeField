#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef pair<int, int> PII;
const int N = 3e5 + 10;
int q[N], s[N];
int n, m;
vector<int> alls;
vector<PII> add, query;

int find(int x)
{
    int l = 0, r = alls.size() - 1;
    while(l < r)
    {
        int mid = l + r >> 1;
        if(alls[mid] >= x) r = mid;
        else l = mid + 1;
    }
    return l;
}

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        int x, c;
        cin >>  x >> c;
        add.push_back({x, c});
        alls.push_back(x);
    }

    for(int i = 0; i < m; i++)
    {
        int l, r;
        cin >> l >> r;
        query.push_back({l, r});
        alls.push_back(l);
        alls.push_back(r);
    }

    sort(alls.begin(), alls.end());
    alls.erase(unique(alls.begin(), alls.end()), alls.end());

    for(auto item : add)
    {
        int x = find(item.first);
        q[x] += item.second;
    }

    for(int i = 1; i <= alls.size(); i++) s[i] = s[i - 1] + q[i];

    for(auto item : query)
    {
        int l = find(item.first), r = find(item.second);
        cout << s[r] - s[l - 1] << endl;
    }

    return 0;
}