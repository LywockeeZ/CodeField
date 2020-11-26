#include <iostream>
#include <vector>

using namespace std;

//得到第i位之前的数
int get_nums(vector<int> nums, int l, int r)
{
    int res = 0;
    for(int i = l; i >= r; i--)
        res =res * 10 + nums[i];
    return res;
}

int power10(int x)
{
    int res = 1;
    while(x--) res *= 10;
    return res;
}

int count(int n, int x)
{
    if(!n) return 0;
    
    vector<int> nums;
    while(n)
    {
        nums.push_back(n % 10);
        n /= 10;
    }
    
    n = nums.size();
    int res = 0;
    //从前到后枚举每一位，0不能在首位
    for(int i = n - 1 - !x; i >= 0; i--)
    {
        //考虑第i位前面
        if(i < n - 1) 
        {
            res += get_nums(nums, n - 1, i + 1) * power10(i);
            //对0，前面要从001开始
            if(!x) res -= power10(i);
        }
        
        //考虑第i位后面，三种情况，第一种情况可忽略
        if(nums[i] == x) res += get_nums(nums, i - 1, 0) + 1;
        else if(nums[i] > x) res += power10(i);
    }
    
    return res;
}

int main()
{
    int a, b;
    while(cin >> a >> b, a || b)
    {
        if(a > b) swap(a, b);
        
        for(int i = 0; i < 10; i++)
            cout << count(b, i) - count(a - 1, i) << ' ';
        
        cout << endl;
    }
    
    return 0;
}