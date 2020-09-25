#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int MaxValue(int a, int b, int c = 0)
{
    return a > b ? (a > c ? a : c) : (b > c ? b : c);
}

void SortPrint(int &a, int &b, int &c)
{
    if(a > b) swap(a, b);
    if(a > c) swap(a, c);
    if(b > c) swap(b, c);
    
    cout << a << ' ' << b << ' ' << c << endl;
}

void SortValue(vector<int> &a)
{
    sort(a.begin(), a.end());
}

void SortValue(vector<double> &a)
{
    sort(a.begin(), a.end());
}

template <typename T>
void SortValue(vector<T> &a)
{
    sort(a.begin(), b.end());
}

class Date
{
    private :
        int year, month, day;
    
        Date(int a, int b, int c)
        {
            year = a, month = b, day = c; 
        }

    public :
        void SetDate(int a, int b, int c);
        void PrintDate();
};

void Date::SetDate(int a, int b, int c)
{
    year = a, month = b, day = c;
}

void Date::PrintDate()
{
    cout << year << month << day;
}

class Circle
{
    private:
        int radius;
        Circle(int r)
        {
            radius = r;
        }
    public:
        double GetArea()
        {
            return 3.14 * radius * radius;
        }

};

class Rectangle
{
    private:
        int length, width, height;
        Rectangle()
        {
            cout << "Please input length, width, height :";
            cin >> length >> width >> height;
        }
    public:
        int GetVolum()
        {
            return length * width * height;
        }
};

int main()
{
    return 0;
}