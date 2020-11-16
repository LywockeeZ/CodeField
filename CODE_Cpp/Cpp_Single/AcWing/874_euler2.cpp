#include <iostream>

using namespace std;

const int N = 1e6 + 10;

int primes[N], phi[N], cnt;
bool st[N];

typedef long long LL;

void get_euler(int n)
{
    phi[1] = 1;
    for(int i = 2; i <= n; i++)
    {
        if(!st[i])
        {
            primes[cnt++] = i;
            phi[i] = i - 1;
        }
        for (int j = 0; primes[j] <= n / i; j ++ )
        {
            int t = primes[j] * i;
            st[t] = true;
            if (i % primes[j] == 0)
            {
                phi[t] = phi[i] * primes[j];
                break;
            }
            phi[t] = phi[i] * (primes[j] - 1);
        }
    }
}

int main()
{
    int n;
    cin >> n;
    
    get_euler(n);
    
    LL res = 0;
    for(int i = 1; i <= n; i++) res += phi[i];
    
    cout << res;
    
    return 0;
}