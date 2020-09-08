#include<iostream>
using namespace std;

const int N = 1e5 + 10;
int p[N];

int find(int x)
{
    if(p[x] == x) return x;
    else p[x] = find(p[x]);
}

int main()
{
    char op;
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++) p[i] = i;

    while(m--)
    {
        int a, b;
        cin >> op >> a >> b;;
        if(op == 'Q') 
        {
            if(find(a) == find(b)) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
        else p[find(a)] = find(b);
    }
    return 0;
}