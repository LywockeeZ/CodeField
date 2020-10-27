#include <iostream>

using namespace std;

class People
{
    protected:
        static int num;
        int age = 0;
        int height = 0;
        int weight = 0;
    public:
        People(int ht, int wt, int ag):age(ag),height(ht),weight(wt)
        {
            num++;
        }

        void Eating(){weight++;}
        void Sporting(){height++;}
        void Sleeping(){age++, height++, weight++;}
        void Show()
        {
            cout << "age:" << age << endl;
            cout << "height:" << height << endl;
            cout << "weight:" << weight << endl;
        }

        static int ShowNum()
        {
            cout << num << endl;
        }

};
int People::num = 0;

class Student
{
    private:
        string _name;
        string _num;
        int mathScore;
        int englishScore;
        static int mathTotalScore;
        static int englishTotalScore;
        static int count;

    public:
        static void showStatic();
        void showBase()
        {
            cout << "姓名：" << _name << endl;
            cout << "学号：" << _num << endl;
            cout << "数学成绩：" << mathScore << endl;
            cout << "英语成绩：" << englishScore << endl;
        }

        Student(string name, string num, int math, int english):
            _name(name), _num(num), mathScore(math), englishScore(english)
        {
            mathTotalScore += math;
            englishTotalScore += english;
        }        
};
int Student::mathTotalScore = 0;
int Student::englishTotalScore = 0;
void Student::showStatic()
{
    cout << "数学总成绩：" << mathTotalScore << endl;
    cout << "英语总成绩：" << englishTotalScore << endl;
}

class Dog
{
    private:
        string _name;
        string _sex;
        int _age = 0;
        int _weight = 0;
    public:
        Dog(string name, string sex, int age, int weight)
        {
            _name = name;
            _sex = sex;
            _age = age;
            _weight = weight;
        }
        void showDog()
        {
            cout << "名字：" << _name << endl;
            cout << "性别：" << _sex << endl;
            cout << "年龄：" << _age << endl;
            cout << "体重：" << _weight << endl;
        }
};

class Account
{
    private:
        string _num;
        string _name;
        string _pwd;
        int restNum;
        double ratio;
};

int main()
{
    return 0;
}