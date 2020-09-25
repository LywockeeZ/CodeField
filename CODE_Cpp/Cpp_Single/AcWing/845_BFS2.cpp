#include<iostream>
#include<queue>
#include<unordered_map>
#include<algorithm>

using namespace std;

string start;

int bfs(string start)
{
    string end = "12345678x";

    queue<string> q;
    unordered_map<string, int> d;

    q.push(start);
    d[start] = 0;

    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

    while(q.size() != 0)
    {
        auto t = q.front();
        int k = t.find('x');

        for(int i = 0; i < 4; i++)
        {
            int a = k/3 + dx[i], b = k%3 + dy[i];
            if(a >= 0 && a < 3 && b >= 0 && b < 3)
            {
                swap(t[k], t[a*3 + b]);
                if(!d[t])
                {
                    q.push(t);
                    d[t] = d[q.front()] + 1;
                    if(t == end) return d[t];
                }
                swap(t[k], t[a*3 + b]);
            }                  
        }
        q.pop();
    }
    return -1;
}

int main()
{
    char c;
    for(int i = 0; i < 9; i++)
    {
        cin >> c;
        start += c;
    }

    cout << bfs(start) << endl;
    return 0;
}