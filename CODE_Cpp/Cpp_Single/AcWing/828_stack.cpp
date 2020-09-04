#include <iostream>
#include <string>
using namespace std;

const int N = 1e5 + 10;
int stk[N], t = 0;
int m;

void push(int x)
{
    stk[++t] = x;
}

void pop()
{
    t--;
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
             if(t > 0) cout << "NO" << endl;
             else cout << "YES" << endl;
        }
        else
        {
            cout << stk[t] << endl;
        }               
    }

    return 0;
}