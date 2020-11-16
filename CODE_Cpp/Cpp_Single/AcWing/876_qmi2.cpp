#include <iostream>

using namespace std;

typedef long long LL;

LL qmi(int a, int k, int p)
{
    LL res = 1 % p, t = a;
    while(k)
    {
        if(k & 1) res = res * t % p;
        k >>= 1;
        t = t * t % p;
    }
    
    return res;
}

int main()
{
    int n;
    cin >> n;
    
    while(n--)
    {
        int a, p;
        cin >> a >> p;
        //a与p必须互质，否则无解
        if(a % p) cout << qmi(a, p - 2, p) << endl;
        else cout << "impossible" << endl;
    }
}