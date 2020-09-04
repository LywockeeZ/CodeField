#include<iostream>
#include<cstdio>
using namespace std;

const int N = 1e5 + 10;
int a[N], stk[N], tt = 0;
int m;

void push(int x)
{
    stk[++tt] = x;
}

void pop()
{
    tt--;
}

int main()
{
    cin >> m;
    for(int i = 0; i < m; i++) 
    {
        scanf("%d", &a[i]);
        while(tt && stk[tt] >= a[i]) pop();
        if(!tt) 
        {
            push(a[i]);
            cout << -1 << ' ';
        }
        else 
        {
            cout << stk[tt] << ' ';
            push(a[i]);
        }
    }

    return 0;
}
