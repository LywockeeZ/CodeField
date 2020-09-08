#include<iostream>
using namespace std;

const int N = 1e5 + 10;

int son[N][26], cnt[N], idx;
int n;

void insert(char *str)
{
    int p = 0;
    for(int i = 0; str[i]; i++)
    {
        int u = str[i] - '0';
        if(!son[p][u]) son[p][u] = ++idx;
        p = son[p][u];
    }
    cnt[p]++;
}

int query(char *str)
{
    int p = 0;
    for(int i = 0; str[i]; i++)
    {
        int u = str[i] - '0';
        if(!son[p][u]) return 0;
        p = son[p][u];
    }
    return cnt[p];
}

int main()
{
    char op;
    char str[N];
    cin >> n;
    while(n--)
    {
        cin >> op >> str;
        if(op == 'I') insert(str);
        else cout << query(str) << endl;       
    }
    return 0;
}

