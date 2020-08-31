#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

bool cmp(vector<int> &A, vector<int> &B)
{
    if(A.size() != B.size()) return A.size() >= B.size();
    for(int i = A.size() - 1; i >=0; i--)
        if(A[i] != B[i]) return A[i] > B[i];

    return true;
}

void removeZero(vector<int> &A)
{
    while(A.size() > 1 && A.back() == 0) A.pop_back();
}

vector<int> Sub(vector<int> &A, vector<int> &B)
{
    int t = 0;
    vector<int> C;

    for(int i = 0; i <= A.size() - 1; i++ )
    {
        t = A[i] - t;
        if(i < B.size()) t -= B[i];
        //这一步一次性包含了两种情况，t小于0与t大于0
        C.push_back((t + 10) % 10);
        if(t < 0) t = 1;
            else t = 0;
    }

    removeZero(C);
    return C;
}

int main()
{
    vector<int> A, B, C;
    string a, b;
    cin >> a >> b ;
    for(int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');
    for(int i = b.size() - 1; i >= 0; i--) B.push_back(b[i] - '0');

    if(cmp(A, B)) C = Sub(A, B);
    else
    {
         C = Sub(B, A);
         printf("-");
    }
    

    for(int i = C.size() - 1; i >= 0; i--) printf("%d", C[i]);

    return 0;
}