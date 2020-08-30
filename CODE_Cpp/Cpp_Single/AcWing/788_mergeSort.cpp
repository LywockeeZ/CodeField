#include<iostream>
#include<cstdio>
using namespace std;

const int N = 1e6 + 10;
int n, q[N], tmp[N];
long int numb = 0;  //为了防止溢出，用long int。

void merge_sort(int q[], int l, int r)
{
    if(l >= r) return;

    int mid = l + r >> 1;
    merge_sort(q, l, mid), merge_sort(q, mid + 1, r);

    int i = l, j = mid + 1, k = 0;
    while (i <= mid && j <= r)
    {
        if(q[i] <= q[j]) 
        {
            tmp[k++] = q[i++];
        }
        else 
        {
            tmp[k++] = q[j++];
            //因为左右两序列都有序，当发现一个在右边序列的数比左边小时，它比左边剩余未比较的都小
            //左边剩余未比较的个数为 mid - i + 1
            numb += mid - i + 1; 
        }
    }

    while (i <= mid){tmp[k++] = q[i++];}
    while (j <= r){tmp[k++] = q[j++];}
    
    for(i = l, j = 0; i <= r; i++, j++) q[i] = tmp[j]; 
    
}

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &q[i]);

    merge_sort(q, 0, n - 1);

    cout << numb << endl;
}