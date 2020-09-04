#include <iostream>
#include <string>
using namespace std;

const int N = 1e5 + 10;
int q[N], hh = 0, tt = -1;
int m;

void push(int x)
{
    q[++tt] = x;
}

void pop()
{
    ++hh;
}

int main()
{
    string op;
    int x;

    cin >> m;

    while(m--)
    {
        cin >> op;
        if(op == "push")
        {
            cin >> x;
            push(x);
        }   
        else if(op == "pop")
        {
             pop();
        }
        else if(op == "empty")
        {
             if(tt < hh) cout << "YES" << endl;
             else cout << "NO" << endl;
        }
        else
        {
            cout << q[hh] << endl;
        }               
    }
    return 0;
}