#include<iostream>
#include<cstring>
using namespace std;

//
const int N = 100003;

int h[N], ne[N], e[N], idx = 0;

void insert(int x)
{
    int t = (x % N + N) % N;
    e[idx] = x;
    ne[idx] = h[t];
    h[t] = idx++;
}

bool find(int x)
{
    int t = (x % N + N) % N;
    for(int i = h[t]; i != -1; i = ne[i])
        if(e[i] == x) return true;
    return false;
}

int main()
{
    memset(h, -1, sizeof h);

    int n, x;
    char op;

    cin >> n;

    while(n--)
    {
        cin >> op >> x;

        if(op == 'I')
        {
            insert(x);
        }
        else
        {
            if(find(x)) cout << "Yes" << endl;
                else cout << "No" << endl;
        }
    }

    return 0;
}