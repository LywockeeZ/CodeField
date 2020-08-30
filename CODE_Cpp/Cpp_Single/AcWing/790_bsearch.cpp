#include<iostream>
using namespace std;

double n, ans;
const double eps = 1e-8;

bool check(double mid)
{
    if (mid * mid * mid <= n) return true;
        else return false;      
}

double bsearch(double l, double r)
{
    
    while (r - l > eps)
    {
        double mid = (r + l) / 2;
        if(check(mid)) l = mid;
        else r = mid;
    }

    return l;
}

int main()
{
    //scanf("%lf", &n)  double必须用lf输入，不然会出错
    cin >> n;
    ans = bsearch(-1e4, 1e4);

    printf("%lf", ans);
}