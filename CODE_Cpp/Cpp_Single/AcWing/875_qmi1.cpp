#include <iostream>

using namespace std;

typedef long long LL;

LL qmi(int a, int b, int p)
{
    LL res = 1 % p, t = a;
    //将指数按二进制分解，分解的过程中求余数
    while(b)
    {
        if(b & 1) res = (LL)res * t % p;
        b >>= 1;
        t = t * t % p;
    }
    
    return res;
}

int main()
{
    int n;
    cin >> n;
    
    while(n -- )
    {
        int a, b, p;
        cin >> a >> b >> p;
        
        cout << qmi(a, b, p) << endl;
    }
}