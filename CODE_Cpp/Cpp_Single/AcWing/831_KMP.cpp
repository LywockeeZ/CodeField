#include<iostream>
using namespace std;

const int N = 1e6 + 10;
char p[N], s[N], ne[N];
int n, m;

int main()
{
    cin >> n >> p + 1 >> m >> s + 1;

    for(int i = 2, j = 0; i <= m; i++)
    {
        while(j && p[i] != p[j + 1]) j = ne[j];
        if(p[i] == s[j + 1]) j++;
        ne[i] = j;
    }

    for(int i = 1, j = 0; i <= n; i++)
    {
        while(j && p[i] != s[j + 1]) j = ne[j];
        if(p[i] == s[j + 1]) j++;
        if(j == m) 
        {
            cout << i - m + 1 << " ";
        }
    }

    return 0;
}
