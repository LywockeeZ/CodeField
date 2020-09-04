#include <iostream>
#include <string>

using namespace std;

const int N = 1e5 + 10;
int e[N], r[N], l[N], idx, m;

void init()
{
    r[0] = 1;
    l[1] = 0;
    idx = 2;
}

void insert(int k, int x)
{
    e[idx] = x;
    l[idx] = k, r[idx] = r[k];
    l[r[k]] = idx, r[k] = idx++ ;
}

void remove(int k)
{
    l[r[k]] = l[k], r[l[k]] = r[k];
}

int main()
{
    string op;
    int x, k;

    init();
    
    cin >> m;
    while(m--)
    {
        cin >> op;;
        if(op == "L") 
        {
            cin >> x;
            insert(0, x);
        }
        else if(op == "R")
        {
            cin >> x;
            insert(l[1], x);
        }
        else if(op == "D")
        {
            cin >> k;
            //idx是从2开始，所以第k个对应的idx为k+1
            remove(k + 1);
        }
        else if(op == "IL")
        {
            cin >> k >> x;
            insert(l[k + 1], x);
        }
        else
        {
            cin >> k >> x;
            insert(k + 1, x);
        }
        
    }

    
    for(int i = r[0]; i != 1; i = r[i])
        cout << e[i] << " ";
    return 0;
}