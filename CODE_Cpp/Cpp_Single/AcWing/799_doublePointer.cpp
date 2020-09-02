#include<iostream>
using namespace std;

const int N = 1e5 + 10;
int a[N], b[N], n;

int main()
{
    cin >> n;
    for(int i = 0; i < n ; i++) scanf("%d", &a[i]);

    int res;
    for(int i = 0, j = 0; i < n ; i++)
    {
        b[a[i]]++;//b数组主要用来统计出现个数
        while(j < i && b[a[i]] > 1) b[a[j++]]--;//j向前移动到i，同时将统计个数清零
        res = max(res, i - j + 1);
    }
    
    cout << res << endl;    
    return 0;
}