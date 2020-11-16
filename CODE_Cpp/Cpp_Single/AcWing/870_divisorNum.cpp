#include <iostream>
#include <unordered_map>

using namespace std;

const int N = 1e9 + 7;
unordered_map<int, int> primes;

typedef long long LL;

int main()
{
    int n;
    cin >> n;
    
    while(n--)
    {
        int a;
        cin >> a;
        
        for(int i = 2; i <= a/i; i++)
        {
            while(a % i == 0)
            {
                a /= i;
                primes[i]++;
            }
        }
        if(a > 1) primes[a]++;
    }
    
    LL res = 1;
    //边乘边取模，可以防止溢出
    for(auto prime : primes) res = res * (prime.second + 1) % N;
    
    cout << res;
    
    return 0;
}