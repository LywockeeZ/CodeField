#include <iostream>
#include <string>

using namespace std;
string s;
string g;

int count(string s)
{
    int res = 1;
    auto p = s.begin();
    while(p != s.end())
    {
        int  t = *p - 'A' + 1;
        res = (res * t) % 47;
        p++;
    }
    
    return res;
}

int main()
{
    cin >> s;
    cin >> g;
    
    if(count(s) == count(g)) cout << "GO" << endl;
    else cout << "STAY" << endl;
}