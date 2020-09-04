#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int e[N], ne[N], head, idx, m;

void init()
{
    head = -1;
    idx = 0;
}

void insert(int x)
{
    e[idx] = x, ne[idx] = head, head = idx++;
}

void insert(int k, int x)
{
    e[idx] = x, ne[idx] = ne[k], ne[k] = idx++;
}

void remove(int k)
{
    ne[k] = ne[ne[k]];
}

int main()
{
    char op;
    int x, k;

    init();
    
    cin >> m;
    while(m--)
    {
        cin >> op;;
        if(op == 'H') 
        {
            cin >> x;
            insert(x);
        }
        else if(op == 'D')
        {
            cin >> k;
            //注意idx从0开始
            if(k == 0) head = ne[head];
            else remove(k - 1);
        }
        else 
        {
            cin >> k >> x;
            insert(k - 1, x);
        }
    }

    for(int i = head; i != -1; i = ne[i])
        cout << e[i] << " ";
    return 0;
}