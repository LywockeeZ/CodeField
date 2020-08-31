#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

vector<int> Add(vector<int> &A, vector<int> &B)
{
    int t = 0;
    vector<int> C;
    if(B.size() > A.size()) return Add(B, A);

    for(int i = 0; i <= A.size() - 1; i++ )
    {
        t += A[i];
        if(i < B.size()) t += B[i];
        C.push_back(t % 10);
        t /= 10;
    }

    if(t) C.push_back(t);
    return C;
}

int main()
{
    vector<int> A, B;
    string a, b;
    cin >> a >> b ;
    for(int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');
    for(int i = b.size() - 1; i >= 0; i--) B.push_back(b[i] - '0');

    auto C =  Add(A, B);

    for(int i = C.size() - 1; i >= 0; i--) printf("%d", C[i]);

    return 0;
}