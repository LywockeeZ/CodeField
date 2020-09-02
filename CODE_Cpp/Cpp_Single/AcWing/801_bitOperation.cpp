#include<iostream>
#include<cstdio>
using namespace std;

const int N = 1e5 + 10;
int a[N] , n;

int lowbit(int a)
{
    return a & (-a);
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++) 
    {
        scanf("%d", &a[i]);
        int count = 0;
        while(a[i] != 0)
        {
            a[i] -= lowbit(a[i]);
            count ++;
        }
        cout << count << " ";
    }
    
    return 0;
}