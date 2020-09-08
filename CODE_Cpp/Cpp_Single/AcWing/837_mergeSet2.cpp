#include<iostream>
#include<string>
using namespace std;

const int N = 1e5 + 10;
int p[N], s[N];

int find(int x)
{
    if(p[x] == x) return x;
    else p[x] = find(p[x]);
}

int main()
{
    string op;
    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; i++) p[i] = i, s[i] = 1;

    while(m--)
    {
        int a, b;
        cin >> op;
        if(op == "Q1") 
        {
            cin >> a >> b;
            if(find(a) == find(b)) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
        else if(op == "Q2")
        {
            cin >> a;
            cout << s[find(a)] << endl;
        }       
        else 
        {
            cin >> a >> b;
            a = find(a), b = find(b);
            //注意当a和b不在一个集合时再将数量相加
            if(a != b)
            {                
                p[a] = b;
                s[b] += s[a];
            }
        }
    }
    return 0;
}