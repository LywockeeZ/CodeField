#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

const int N = 100010;
//ph记录第k个插入点在堆中的位置，hp记录堆中第k个元素是第几次插入的
int h[N], ph[N], hp[N], siz = 0, idx = 0;

void heap_swap(int a, int b)
{
    swap(ph[hp[a]], ph[hp[b]]);
    swap(hp[a], hp[b]);
    swap(h[a], h[b]);
}

void down(int x)
{
    int t = x;
    if(x * 2 <= siz && h[x] > h[x * 2]) t = x * 2;
    if(x * 2 + 1 <= siz && h[t] > h[x * 2 + 1]) t = x * 2 + 1;
    if(t != x)
    {
        heap_swap(t, x);
        down(t);
    }
}

void up(int x)
{
    while(x / 2 && h[x / 2] > h[x])
    {
        heap_swap(x, x / 2);
        x >>= 1;
    }
}

int main()
{
    int n, a, b;
    int m = 0;
    string op;

    cin >> n;

    while(n--)
    {
        cin >> op;
        if(op == "I")
        {
            cin >> a;
            siz++, m++;
            ph[m] = siz, hp[siz] = m; 
            h[siz] = a;
            up(siz);
        }
        else if(op == "PM") printf("%d\n", h[1]);
        else if(op == "DM")
        {
            heap_swap(1, siz);
            siz--;
            down(1);
        }
        else if(op == "D")
        {
            cin >> a;
            a = ph[a];
            heap_swap(a, siz);
            siz--;
            up(a);
            down(a);
        }
        else
        {
            cin >> a >> b;
            a = ph[a];
            h[a] = b;
            up(a);
            down(a);
        }
        
    }
    return 0;
}