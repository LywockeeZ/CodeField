#include <iostream>

using namespace std;

const int N = 1e6+10;

int primes[N], cnt;
bool st[N];

//朴素法筛质数
/*
void get_primes(int x)
{
    for(int i = 2; i <= x; i ++)
    {
        if(st[i]) continue;
        primes[cnt++] = i;
        for(int j = i + i; j <= x; j += i)
            if(!st[j]) st[j] = true;
    }
}
*/

//线性筛法筛质数
void get_primes(int x)
{
    for(int i = 2; i <= x; i++)
    {
        if(!st[i]) primes[cnt++] = i;
        //找到所有与i相乘的小于n的质数，因为要找质数，所以操控的时质数数组的下标
        for(int j = 0; primes[j] <= x/i; j++)
        {
            //用最小质因数依次将后面大的数筛掉
            st[primes[j] * i] = true;
            if(i % primes[j] == 0) break;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    
    get_primes(n);
    
    cout << cnt;
    
    return 0;
}