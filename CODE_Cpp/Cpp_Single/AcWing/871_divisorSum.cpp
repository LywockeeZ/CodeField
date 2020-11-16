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
    for(auto prime : primes)
    {
        int s = prime.first, a = prime.second;
        //这里要将t定义为LL防止溢出
        LL t = 1;
        while(a--) t = (t * s + 1) % N;
        res = res * t % N;
    }
    
    cout << res;
    
    return 0;
}
