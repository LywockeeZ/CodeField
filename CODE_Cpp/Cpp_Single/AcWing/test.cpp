#include <iostream>
#include <cstring>
#include <string>

using namespace std;

const int N = 10;

bool row[N][N], col[N][N], blo[N][N];
string s;

bool dfs(int u)
{
    if(u > 80)
    {
        for(int i = 0; i < 81; i++)
        {
            if(i % 9 == 0) cout << endl;
            cout << s[i] << ' ';
        }
            
        return true;
    }
    
    if(s[u] != '.')
    {
        dfs(u + 1);
        return false;
    }
    
    int r = u / 9, c = u % 9, b = (r / 3 * 3) + c / 3;
    for(int i = 1; i <= 9; i++)
    {
        if(!row[r][i] && !col[c][i] && !blo[b][i])
        {
            auto t = s[u];
            s[u] = i + '0';
            row[r][i] = col[c][i] = blo[b][i] = true;
            if(dfs(u + 1)) return true;
            row[r][i] = col[c][i] = blo[b][i] = false;
            s[u] = t;
        }
    }
    
    return false;
}

int main()
{
    while(cin >> s)
    {
        if(s == "end") break;
        
        memset(row, false, sizeof row);
        memset(col, false, sizeof col);
        memset(blo, false, sizeof blo);
        
        for(int i = 0; i < 81; i++)
            if(s[i] != '.')
            {
                int r = i / 9, c = i % 9, b = (r / 3 * 3) + c / 3;
                int num = s[i] - '0';
                row[r][num] = col[c][num] = blo[b][num] = true;
            }
        
        dfs(0);
    }
    
    return 0;
}