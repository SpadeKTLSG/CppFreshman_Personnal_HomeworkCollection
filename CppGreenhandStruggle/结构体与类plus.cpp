#include<iostream>
#include<iomanip>
#include <tchar.h>
#include<string>

using namespace std;

//!------------------------------------------
struct student {
    char num[6];
    char name[8];
    float score[4];
    float avr;
};

void input(student *stu, int n) {
    for (int i = 0; i < n; i++) {
        cout << endl << "input the scores of the students now  :  " << endl << "NO. :";
        cin >> stu[i].num;
        cout << "name : ";
        cin >> stu[i].name;
        cout << endl;

        for (int j = 0; j < 3; j++) {
            cout << "score" << j + 1 << ":";
            cin >> stu[i].score[j];
        }
    }
}


void output(student *stu, float average, float max, int maxi, int n) {
    cout << endl << endl << "       NO.      name      score1      score2      score3       average" << endl;
    for (int i = 0; i < n; i++) {
        cout << setw(8) << stu[i].num << "  " << setw(10) << stu[i].name << "          ";
        for (int j = 0; j < 3; j++)
            cout << setw(3) << stu[i].score[j] << "          ";
        cout << stu[i].avr << endl;
    }
    cout << endl << "average = " << average << endl << "The highest score is :" << stu[maxi].name << ",score total:" << max << endl;
}


void suck_students(student *stu, int n) { //N个学生，每个学生有学号，姓名，3门课成绩（假设给定语数英）还有其平均分，最后打印3门课总平均成绩和最高分的人成绩。
    float average = 0, max = 0, sum = 0;
    int maxi = 0;

    input(stu, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++)
            sum = sum + stu[i].score[j];

        stu[i].avr = sum / 3;
        average += stu[i].avr;

        if (sum > max) {
            max = sum;
            maxi = i;
        }
        sum = 0;
    }

    average /= n;
    output(stu, average, max, maxi, n);
}


//!------------------------------------------
struct Person {
    char name[20];
    int count;
};

void ticket_count() {//计票问题：
    Person leader[3] = {"L", 0, "Z", 0, "S", 0};
    char leader_name[20];

    for (int i = 0; i < 10; i++) {
        cin >> leader_name;
        for (auto &j: leader)
            if (strcmp(leader_name, j.name) == 0)
                j.count++;
    }

    for (auto &i: leader)
        cout << endl << i.name << ";" << i.count << endl;
}

//!------------------------------------------
const int N = 5;

struct Book {
    char isbn[10];
    char name[20];
    double price;
    int stock;
};

void sort(Book *p, int len) {//选择排序
    int i, j, min;
    Book temp{};
    for (i = 0; i < len - 1; ++i) {
        min = i;
        for (j = i + 1; j < len; ++j)
            if (p[j].price < p[min].price)
                min = j;
        if (min != i) {
            temp = p[i];
            p[i] = p[min];
            p[min] = temp;
        }
    }
}

void output(Book *p, int len) {
    int i;
    cout << endl << endl << setw(10) << "书号" << setw(20) << "书名" << setw(10) << "单价" << setw(10) << "库存量" << endl << endl;
    for (i = 0; i < len; ++i)
        cout << setw(10) << p[i].isbn << setw(20) << p[i].name << setw(10) << p[i].price << setw(10) << p[i].stock << endl << endl;
}

void bookstores() {//按单价由低到高排序后输出，排序功能和输出功能分别设计函数实现，用结构体指针做参数。
    Book book1[N] = {"1001", "数据结构", 15.9, 100,
                     "1002", "操作系统", 31.5, 200,
                     "1003", "计组", 25.6, 150,
                     "1004", "编译原理", 33.2, 270,
                     "1005", "数据挖掘", 35.8, 300};
    sort(book1, N);
    output(book1, N);
}


//!------------------------------------------

class Student {
public:
    void set();         //输入数据成员的值
    double ave();       //求平均分
    double max();       //求最高分
    void display();     //显示学生基本信息
private:
    int num;             //数据成员：学号、姓名、年龄、三门课分数
    char name[20];
    int age;
    int score[3];
};

void Student::set() {
    int i;

    cout << endl << "num=";
    cin >> num;
    cin.get();
    cout << endl << "name=";
    cin >> name;
    cout << endl << "age=";
    cin >> age;

    for (i = 0; i < 3; i++) {
        cout << endl << "score" << i + 1 << "= ";
        cin >> score[i];
    }
}


double Student::ave() {
    double average = 0;
    for (int i: score)
        average = average + i;

    average = average / 3;
    return average;
}

double Student::max() {
    int i, max = score[0];
    for (i = 1; i < 3; i++)
        if (score[i] > max)
            max = score[i];
    return max;
}

void Student::display() {
    cout << endl << "学号:" << num << endl;
    cout << endl << "姓名:" << name << endl;
    cout << endl << "年龄:" << age << endl;
    for (int i = 0; i < 3; i++)
        cout << endl << "分数" << i + 1 << ":" << score[i] << endl;
    cout << endl;
}


void student_management() {//学生信息的输入及相关信息的输出
    Student stu{};
    double average, maxsocre;
    stu.set();
    cout << endl << "***********************" << endl;
    stu.display();
    cout << endl << "***********************" << endl;

    average = stu.ave();
    maxsocre = stu.max();
    cout << endl << "其平均分是" << average << "分，最高分数是" << maxsocre << "分。" << endl;
}


//!------------------------------------------
class Box {//长方体的First演示
public:
    void get();

    void send();

    void output() const;

private:
    float l, w, h, v;
};

void Box::get() {
    cin >> l;
    cin >> w;
    cin >> h;
    send();
}

void Box::send() {
    v = l * w * h;
    output();
}

void Box::output() const {
    cout << v;
}

int Boxing() {
    Box a{};
    cout << "the result is that: " << endl;
    a.get();
}


//!------------------------------------------
//!对象的指针访问对象成员总结
/*
Time a, * p;
Time &b = a;   //b是a的引用。
p = &a; 
    p->hour       /     (*p).hour      /      a.hour    /     b.hour     三个都是等价的
*/



//!------------------------------------------
class MAX {//找整形数组中的元素的最大值
public:
    void set();

    void maxof();

    void output();

private:
    int a[10];
    int max;
    int i = 0;
};

void MAX::set() {
    for (i = 0; i < 10; i++) {
        cin >> a[i];
    }
    maxof();
}

void MAX::maxof() {
    max = a[0];
    for (i = 0; i < 10; i++) {
        if (a[i] > max)max = a[i];
    }
    output();
}

void MAX::output() {
    cout << endl << max;
}

int maxfuntion() {
    class MAX t;
    t.set();
    return 0;
}


//!------------------------------------------
class Time { //时间停止！
public:
    Time(int, int, int);

    void show() const;

private:
    int h;
    int m;
    int s;
};

int timefunction() {
    int a, b, c;
    cin >> a >> b >> c;
    Time t1(a, b, c);
    t1.show();
    return 0;
}

Time::Time(int a, int b, int c) {//带参数的构造函数
    h = a;
    m = b;
    s = c;
}

void Time::show() const {
    cout << h << "  :   " << m << "  :   " << s << endl;
}


//!------------------------------------------
class Array { //从构造函数和析构函数开始
public:
    Array();

    ~Array();

    int max();       //求最大值
    void display();     //显示数组

private:
    int num{};
    int *p;
};

Array::Array() {   //构造

    int i;
    cout << endl << "输入数组长度:";
    cin >> num;

    p = new int[num];
    cout << endl << "输入" << num << "个数:";
    for (i = 0; i < num; i++)
        cin >> p[i];
}

int Array::max() {
    int maxvalue = p[0];
    for (int i = 1; i < num; i++)
        if (p[i] > maxvalue)
            maxvalue = p[i];
    return maxvalue;
}

void Array::display() {
    cout << endl << "******************************************" << endl << endl;
    for (int i = 0; i < num; i++)
        cout << setw(6) << p[i];
    cout << endl << endl << "******************************************" << endl << endl;
}

Array::~Array() {
    delete[]p;             //去除
    cout << "析构函数已经执行" << endl << endl << endl;
}

void Arrayfunction() {
    Array a;
    int k;
    k = a.max();
    a.display();
    cout << endl << "最大值是" << k << "。" << endl;
}


//!------------------------------------------
class Rectangle { //对象数组举例：三角形
public:
    Rectangle(int l, int w);

    void set();

    int area();

    void display();

private:
    int length;
    int width;
};


Rectangle::Rectangle(int l, int w) {
    length = l;
    width = w;
}


void Rectangle::set() {
    cout << endl << "length=";
    cin >> length;
    cout << endl << "width=";
    cin >> width;
}


void Rectangle::display() {
    cout << endl << "长度：" << length << endl;
    cout << endl << "宽度：" << width << endl;
    cout << endl << "面积：" << area() << endl;
}

int Rectangle::area() {
    return length * width;
}

void RectangleMagic() {
    Rectangle arr[3] =
            {Rectangle(4, 6),
             Rectangle(8, 9),
             Rectangle(2, 3)};

    int i;

    cout << endl << "初始化好的数组对象：" << endl;

    for (i = 0; i < 3; i++) {
        arr[i].display();
        cout << endl << "****************" << endl;
    }


    cout << endl << "重置数组对象：" << endl << endl;

    for (i = 0; i < 3; i++) {
        cout << endl << "第" << i + 1 << "个对象：" << endl;
        arr[i].set();
    }

    cout << endl << "重置以后的数组对象：" << endl << endl;

    for (i = 0; i < 3; i++) {
        arr[i].display();
        cout << endl << "****************" << endl;
    }

    cout << endl << endl;
}


//!------------------------------------------
class Rectangle2 { //对象的动态建立与释放
public:
    Rectangle2(int l, int w);

    Rectangle2();

    void set();

    [[nodiscard]] int area() const;

    void display() const;

    ~Rectangle2() {
        cout << "hhh";
    }               //析构函数

private:
    int length;
    int width;
};


Rectangle2::Rectangle2(int l, int w) : length(l), width(w) {}    //有参构造函数

Rectangle2::Rectangle2() : length(0), width(0) {}   //无参构造函数

void Rectangle2::set() {
    cout << endl << "length=";
    cin >> length;
    cout << endl << "width=";
    cin >> width;
}

int Rectangle2::area() const {
    return length * width;
}

void Rectangle2::display() const {
    cout << endl << "长度：" << length << endl;
    cout << endl << "宽度：" << width << endl;
    cout << endl << "面积：" << area() << endl;
}

void RectangleSSR() {
    Rectangle2 *p;

    p = new Rectangle2(10, 10);    //要和该类的构造函数一致

    cout << endl << "初始化好的对象：" << endl;
    p->display();

    cout << endl << "重新设置对象：" << endl;
    p->set();

    cout << endl << "初始化好的对象：" << endl;
    p->display();

    delete p;

}

//!------------------------------------------
class student2 {//学生数据输出与找最大值：
public:
    explicit student2(int = 100, float = 100);

    void output() const;

    int num;
    float score;
};

void student2::output() const {
    cout << num << " " << score << endl;
}

void max(student2 *p) {
    float max = p[0].score;
    int m = 0;

    for (int i = 1; i < 3; i++) {
        if (p[i].score > max) {
            max = p[i].score;
            m = i;
        }
    }

    cout << "\nthe best person:\t" << p[m].score << max << endl;
}

student2::student2(int i, float j) : num(i), score(j) {};

void StuMagic2() {
    student2 stu[3] = {student2(101, 78.5), student2(102, 88), student2(103, 99)};
    student2 *p = stu;

    for (int i = 0; i < 3; p++, i++)
        p->output();

    student2 *arr = stu;
    max(arr);
}


//!------------------------------------------
class Product {//超市零元购！计算折扣和售价
public:
    Product(int j, int k, float l) : num(j), quantity(k), price(l) {};//初始化表

    void total() const;

    static double average();

    static void display();


private:
    int num;
    int quantity;
    double price;
    static double discount;
    static double sum;
    static int n;
};

double Product::discount = 0.05;
double Product::sum = 0;
int Product::n = 0;

void Product::total() const {
    double rate = 1.0;

    if (quantity > 10)
        rate = 0.98 * rate;

    sum += quantity * price * rate * (1 - discount);
    n += quantity;
}

double Product::average() {
    return (sum / n);
}

void Product::display() {
    cout << sum << endl;
    cout << average() << endl;
}


void supermarket() {
    Product PU[3] = {Product(101, 5, 23.5), Product(102, 12, 24.56), Product(103, 100, 21.5)};

    for (auto i: PU)
        i.total();
    Product::display();
}


//!------------------------------------------
//这里需要用到类的前置声明
class Date;

class Time2 {//互相调用举例
public:
    explicit Time2(int = 0, int = 0, int = 0);

    friend void display(const Date &, const Time2 &);

    friend Date;

private:

    int hour;
    int minute;
    int second;
};

Time2::Time2(int h, int m, int s) {
    hour = h;
    minute = m;
    second = s;
}


class Date {
public:
    Date(int, int, int);

    friend void display(const Date &, const Time2 &);

    void output(const Time2 &) const;

private:

    int month;
    int day;
    int year;

};

Date::Date(int m, int d, int y) {
    month = m;
    day = d;
    year = y;
}

void Date::output(const Time2 &a) const {
    cout << "The Time2: \n\n\n\n\t";
    cout << a.second << ":" << a.minute << ":" << a.hour << '\t';
    cout << this->month << "/" << day << "/" << year << "\n\n\n";

}

void display(const Date &d, const Time2 &t) {
    cout << "The Time2: \n\n\n\n\t";
    cout << t.second << ":" << t.minute << ":" << t.hour << '\t';
    cout << d.month << "/" << d.day << "/" << d.year << "\n\n\n";
}


void interaction() {
    Time2 t1(10, 34, 45);
    Date d1(12, 25, 2021);
    d1.output(t1);
    display(d1, t1);
}


//!------------------------------------------
template<class SpadeK>  //类模板尝试
class Co {
public:
    Co(SpadeK a, SpadeK b);

    SpadeK max();

    SpadeK min();

private:
    SpadeK x, y;
};


template<class SpadeK>
Co<SpadeK>::Co(SpadeK a, SpadeK b) {
    x = a;
    y = b;
}


template<class SpadeK>
SpadeK Co<SpadeK>::max() {
    return (x > y) ? x : y;
}


template<class SpadeK>
SpadeK Co<SpadeK>::min() {
    return (x < y) ? x : y;
}


void TemplateMagic() {
    Co<int> cmp1(3, 7);
    cout << cmp1.max() << "   max" << endl;
    cout << cmp1.min() << "   min" << endl;

    Co<float> cmp2(3.7, 8.7);
    cout << cmp2.max() << "   max" << endl;
    cout << cmp2.min() << "   min" << endl;
}
//!------------------------------------------