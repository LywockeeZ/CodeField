#include <iostream>
#include <cstring>

using namespace std;

const int N = 510, M = 1e5 + 10;

int h[N], ne[M], e[M], idx;
//存放的是右边集合已匹配的左边集合点的编号
int match[N];
int n1, n2, m, res;
bool st[N];

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

bool find(int x)
{
    for(int i = h[x]; i != -1; i = ne[i])
    {
        int j = e[i];
        if(!st[j])
        {
            st[j] = true;
            //如果对方没有匹配，或者已匹配的点可以找到下家，则匹配为当前点
            if(match[j] == 0 || find(match[j])) 
            {
                match[j] = x;
                return true;
            }
            
        }
    }
    
    return false;
}

int main()
{
    memset(h, -1, sizeof h);
    
    cin >> n1 >> n2 >> m;
    
    while(m--)
    {
        int a, b;
        cin >> a >> b;
        add(a, b);
    }
    
    for(int i = 1; i <= n1; i++)
    {
        memset(st, false, sizeof st);
        if(find(i)) res++;
    }
    
    cout << res << endl;
    
    return 0;
}