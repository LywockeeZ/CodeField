#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef pair<int, int> PII;
vector<PII> sec;
vector<PII> res;
int n;

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;
        sec.push_back({l, r});
    }

    sort(sec.begin(), sec.end());

    int st = -2e9, ed = -2e9;
    for(int i = 0; i < sec.size(); i++)
    {
        if(sec[i].first <= ed) ed = max(ed, sec[i].second);
        else 
        {
            //每次下一区间的头大于当前维护的尾，就将当前维护区间加入答案，初始的区间不加入
            if(st != -2e9) res.push_back({st, ed});
            st = sec[i].first;
            ed = sec[i].second;           
        }
    }
    //将最后一个区间加入，同时防止输入为空时，将初始区间加入
    if(st != -2e9) res.push_back({st, ed});

    cout << res.size() << endl;

    return 0;
}
