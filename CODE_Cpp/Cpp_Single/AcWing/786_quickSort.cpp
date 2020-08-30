#include<iostream>
using namespace std;

const int N = 1e6 + 10;
int n, k, q[N];

void quick_sort(int q[], int l, int r)
{
    if(l >= r) return;

    int i = l - 1, j = r + 1, x = q[(l + r) >> 1];
    while (i < j)
    {
        do i++; while(q[i] < x);
        do j--; while(q[j] > x);
        if (i < j)
        {
            int temp = q[i];
            q[i] = q[j];
            q[j] = temp;
        }        
    }

    quick_sort(q, l, j);
    quick_sort(q, j + 1, r);
}

int main()
{
    
    scanf("%d", &n);
    scanf("%d", &k);
    for(int i = 0; i < n ; i++) scanf("%d", &q[i]);

    quick_sort(q, 0, n - 1);

    cout <<q[k - 1]<< endl;
}