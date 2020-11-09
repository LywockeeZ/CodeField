#include <iostream>

using namespace std;

int n;

bool is_prime(int x)
{
    if(x < 2) return false;
    for(int i = 2; i <= x/i; i++)
        if(x % i == 0) return false;
    return true;
}

int main()
{
    cin >> n;
    
    bool res;
    while(n--)
    {
        int a;
        cin >> a;
        res = is_prime(a);
        
        if(res) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    
    return 0;
}