#include<iostream>
using namespace std;

const int N = 200000;
int p[N], n, k;

int find(int x)
{
    if(p[x] != x) p[x] = find(p[x]);
    else return x;
}

//将y合并到x中
void merge(int x, int y)
{
    p[find(y)] = find(x);
}

int main()
{
    int op, x, y, ans = 0;
    cin >> n >> k;

    //分三段，第一个n是i的同类，第二个n是i的捕食，第三个n是i的天敌
    for(int i = 1; i <= 3 * n; i++) p[i] = i;

    while(k--)
    {      
        cin >> op >> x >> y;
        if(x > n || y > n) ans++;
        else if(op == 1)
        {
            //如果x和y的天敌不在一个集合，并且x和y的捕食不在一个集合，说明是同类，就合并
            if(find(x) != find(y + n + n) && find(x) != find(y + n))
            {
                merge(x, y);
                merge(x + n, y + n);
                merge(x + n + n, y + n + n);
            }    
            else ans++;
        }
        else
        {
            if(x == y) ans++;
            else if(find(x) != find(y) && find(x + n + n) != find(y) )
            {
                merge(x + n, y);//x的捕食域中加入y和他的同类
                merge(y + n + n, x); //y的天敌域中加入x和他的同类
                merge(x + n + n, y + n);//x的天敌域加入y的捕食域，因为x吃y，y只能吃c，c吃x，这样才能构成环形
            }
            else ans++;
        }       
    }
    cout << ans << endl;

    return 0;
}