#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void removeZero(vector<int> &A)
{
    while(A.size() > 1 && A.back() == 0) A.pop_back();
}

vector<int> Div(vector<int> &A, int b, int &r)
{
    vector<int> C;
    r = 0;
    for(int i = A.size() - 1; i >= 0 ; i--)
    {
        r = r * 10 + A[i];
        C.push_back(r / b);
        r %= b;
    }
    reverse(C.begin(), C.end());

    removeZero(C);
    return C;
}

int main()
{
    string a;
    vector<int> A, B;
    int b, r; 
    cin >> a >> b;
    for(int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');

    auto C = Div(A, b, r);

    for(int i = C.size() - 1; i >= 0; i--) printf("%d", C[i]);
    printf("\n%d", r);

    return 0;
}