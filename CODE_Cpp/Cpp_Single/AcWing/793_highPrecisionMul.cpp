#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

void removeZero(vector<int> &A)
{
    while(A.size() > 1 && A.back() == 0) A.pop_back();
}

vector<int> Mul(vector<int> &A, int b)
{
    int t = 0;
    vector<int> C;

    //当A每一位都乘完后，就依次向前放入t，直到t放完
    for(int i = 0; i <= A.size() - 1 || t; i++ )
    {
        if(i < A.size()) t += A[i] * b;;
        C.push_back(t % 10);
        t /= 10;
    }

    removeZero(C);
    return C;
}

int main()
{
    vector<int> A, B, C;
    string a;
    int b;
    cin >> a >> b ;
    for(int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');
    
    C = Mul(A, b);  

    for(int i = C.size() - 1; i >= 0; i--) printf("%d", C[i]);

    return 0;
}