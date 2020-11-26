#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 1e5 + 10;
int a[N];

int main()
{
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++) cin >> a[i];
    
    sort(a, a + n);
    
    LL sum = 0;
    for(int i = 0; i < n; i++) sum += a[i] * (n - i - 1);//第一个人被计算n-1次
    
    cout << sum;
    
    return 0;
}