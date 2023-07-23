#include<iostream>
#include<string>
#include <utility>

using namespace std;

// 由于之前一直搞重复命名的问题, 这里为了保证唯一性搞的类名可能比较奇怪

//!------------------------------------------
class RectangleX {
public:
    explicit RectangleX(int l = 10, int w = 10);

    [[nodiscard]] int area() const;

    friend ostream &operator<<(ostream &output, RectangleX &c);

    friend istream &operator>>(istream &input, RectangleX &c);

private:
    int length;
    int width;
};


RectangleX::RectangleX(int l, int w) : length(l), width(w) {

}

int RectangleX::area() const {
    return length * width;
}

istream &operator>>(istream &input, RectangleX &c) {
    cout << endl << "length=";
    input >> c.length;
    cout << endl << "width=";
    input >> c.width;
    return input;
}

ostream &operator<<(ostream &output, RectangleX &c) {
    output << endl << "长度：" << c.length << endl;
    output << endl << "宽度：" << c.width << endl;
    output << endl << "面积：" << c.area() << endl;
    return output;
}


void op1() { // 重载运算符1
    RectangleX a, b(20, 30), c(15, 10);
    cout << endl << "输出a,b,c的初始状态:" << endl << endl;

    cout << a << endl << b << endl << c << endl;       //operator<<(cout,a) //operator<<(cout,b)、operator<<(cout,c)

    cout << endl << "输入a,b:" << endl << endl;
    cin >> a >> b;     //operator>>(cin,a)、operator>>(cin,b)

    cout << endl << "输出a,b的最新状态:" << endl << endl;
    cout << a << endl << b << endl;   //operator<<(cout,a)、operator<<(cout,b)
}


//!------------------------------------------
class RectangleY {
public:
    RectangleY(int l, int w);

    operator int() const;

    [[maybe_unused]] void set();

    [[nodiscard]] int area() const;

    [[maybe_unused]] void display() const;

    friend int operator+(RectangleY m, RectangleY n);

private:
    int length;
    int width;
};

RectangleY::RectangleY(int l, int w) : length(l), width(w) {//构造函数
}


RectangleY::operator int() const {//类型转换函数
    return length * width;
}


[[maybe_unused]] void RectangleY::set() {
    cout << endl << "length=";
    cin >> length;
    cout << endl << "width=";
    cin >> width;
}


int RectangleY::area() const {
    return length * width;
}

[[maybe_unused]] void RectangleY::display() const {
    cout << endl << "长度：" << length << endl;
    cout << endl << "宽度：" << width << endl;
    cout << endl << "面积：" << area() << endl;
}


int operator+(RectangleY m, RectangleY n) {
    int sum;
    sum = m.area() + n.area();
    return sum;
}


void op2() { // 重载运算符2
    RectangleY a(10, 10), b(20, 30);
    int temp;
    int result;

    temp = b;   //对象赋值给int变量，自动调用类型转换函数→ b转成int变量
    cout << endl << "temp=" << temp << endl;

    cout << endl << "******** a+b **********" << endl;
    result = a + b;       // int operator + (RectangleY m,RectangleY n)
    cout << endl << "a和b的面积和为" << result << endl;


    cout << endl << "******** a+100 **********" << endl;
    result = a + 100;     //对+的重载没有匹配的→是否有类型转换函数？是！→ a转成int变量
    cout << endl << "a的面积加100为" << result << endl;


    cout << endl << "******** 100+a **********" << endl;
    result = 100 + a;   //对+的重载没有匹配的→是否有类型转换函数？是！→ a转成int变量  
    cout << endl << "100加a的面积为" << result << endl;
}


//!------------------------------------------
class Complex {//复数加法计算，重载; 要求：非成员非友元
public:
    Complex() {
        real = 0;
        imag = 0;
    }

    Complex(double r, double i) {
        real = r;
        imag = i;
    }

    [[nodiscard]] double get_real() const;

    [[nodiscard]] double get_imag() const;

    void display() const;


private:
    double real;
    double imag;

};

double Complex::get_real() const {
    return real;
}

double Complex::get_imag() const {
    return imag;
}

void Complex::display() const {
    cout << "(" << real << "," << imag << ")" << endl;
}

Complex operator+(Complex &a, Complex &b) {
    return {a.get_real() + b.get_real(), a.get_imag() + b.get_imag()}; //使用了{}要求c++11, 也可以用Complex(...)
}

void Co_add() {
    Complex c1(3, 4), c2(5, -10), c3;
    c3 = c1 + c2;
    cout << "c3=" << endl;
    c3.display();
}

//!------------------------------------------
class co { //复数的所有计算和输出集合：类型转换运算符：整数也合法：
public:
    co() {
        real = 0;
        imag = 0;
    };

    co(double r) {
        real = r;
        imag = 0;
    };

    co(double r, double i) {
        real = r;
        imag = i;
    };
    //重载构造函数：

    //重载类型转换运算符
    operator double() const {
        return real;
    }

    co operator+(co &b) const;

    co operator+(int &i) const;

    co operator-(co &b) const;

    co operator*(co &b) const;

    co operator/(co &b) const;

    friend co operator+(int &, co &);

    friend istream &operator>>(istream &, co &);

    friend ostream &operator<<(ostream &, co &);

    //void display();

private:
    double real;
    double imag;
};


co co::operator+(co &b) const {
    co c;
    c.real = this->real + b.real;
    c.imag = this->imag + b.imag;
    return c;
}

co co::operator+(int &i) const {//临时对象
    return {this->real + i, this->imag};
}


co operator+(int &i, co &c) {
    return {i + c.real, c.imag};
}


co co::operator-(co &b) const {
    co c;
    c.real = this->real - b.real;
    c.imag = this->imag - b.imag;
    return c;
}

co co::operator*(co &b) const {
    co c;
    c.real = this->real * b.real - this->imag * b.imag;
    c.imag = imag * b.real + real * b.imag;
    return c;
}

co co::operator/(co &b) const {
    co c;
    c.real = (real * b.real + imag * b.imag) / (b.real * b.real + b.imag * b.imag);
    c.imag = (imag * b.real - real * b.imag) / (b.real * b.real + b.imag * b.imag);
    return c;
}


istream &operator>>(istream &inp, co &a) {
    inp >> a.real >> a.imag;
    return inp;
}


ostream &operator<<(ostream &outp, co &a) {
    outp << a.real << "+" << a.imag << "i\n";
    return outp;
}


//测试：int main()
//int main() {
//    co a, b, c, d, e, f;
//    double y;
//    cin >> a >> b;
//    cout << a << b;
//    cout << (c = a + b);
//    cout << (d = a * b);
//    d = 2.5 + a;
//    cout << d;
//    e = co(d);
//    cout << e;
//    return 0;
//}

//!------------------------------------------
//矩阵有关输入输出和相加N行N列；
const int N = 4;  //改变长度
class box {
public:
    box() {
        for (auto &i: num)
            for (int &j: i)
                j = 0;
    }

    friend box operator+(box &, box &);

    friend ostream &operator<<(ostream &, box &);

    friend istream &operator>>(istream &, box &);


    void input() {
        cout << "put in the numbers\n";
        for (auto &i: num)
            for (int &j: i)
                cin >> j;
    }

    void display() {
        int y = 0;
        for (auto &i: num) {
            for (int j: i) {
                cout << j << "  ";
                y++;
                if (y % N == 0)
                    cout << endl;
            }
        }
    }

private:
    int num[N][N]{};
};

box operator+(box &a, box &b) {
    box c;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            c.num[i][j] = a.num[i][j] + b.num[i][j];
    }
    return c;
}


istream &operator>>(istream &inp, box &a) {
    cout << "put in the numbers\n";
    for (auto &i: a.num)
        for (int &j: i)
            inp >> j;
    return inp;
}


ostream &operator<<(ostream &outp, box &a) {
    int y = 0;
    for (auto &i: a.num) {
        for (int j: i) {
            outp << j << "  ";
            y++;
            if (y % N == 0)
                outp << endl;
        }
    }
    return outp;
}

//Test
//int main() {
//    cout << "This is a program for test!!! ";
//    box a, b, c, d;
//    b.display();
//    cin >> a;
//    //a.input();
//    b = a;
//    //a.display();
//    //b.display();
//    cout << b;
//    c = a + b;
//    c.display();
//    system("pause");
//    return 0;
//}



//大学生毕业当老师的数据继承问题：-----转换构造函数的使用问题;这题给我整啥了，直接暴力破解

class student {
public:
    student(int, string, string, float);

    friend class teacher;

    //以下用于访问student时候使用
    [[nodiscard]] int number() const {
        return num;
    }

    string getname() {//返回一个首地址char型指针
        return name;
    }

    string getsex() {//当老师不需要考虑成绩（确信）
        return sex;
    }

    void display() {
        cout << "num:" << num << "\nname:" << name << "\nsex" << sex << "\nscore:" << score << "\n\n";
    }

private:
    int num;
    string name;
    string sex;
    float score;

};

student::student(int n, string nam, string se, float sc) {
    num = n;
    name = std::move(nam); //std::move()函数用于将对象的状态或者所有权从一个对象转移到另一个对象，但是不留任何副本。在某些情况下，移动对象比复制对象更高效。
    sex = std::move(se);
    score = sc;

}


class teacher {
public:
    teacher() = default;

    teacher(int, string, string, float);

    friend class student;

    explicit teacher(student &);  //转换构造函数


    void display() {
        cout << "num:" << num << "\nname:" << name << "\nsex:" << sex << "\npay:" << pay << "\n\n";
    };

private:
    int num{};
    string name;
    string sex;
    float pay{};

};

teacher::teacher(int n, string nam, string se, float p) {
    num = n;
    name = std::move(nam);
    sex = std::move(se);
    pay = p;
}

// Change how to change???

//函数访问方法：
teacher::teacher(student &stu) {
    this->num = stu.number();
    this->pay = 1500;
    this->name = stu.getname();
    this->sex = stu.getsex();
    cout << endl << "转换完毕，长官！" << endl;
}

//teacher::teacher(student &stu) {
//    this->num = stu.num;
//    sex = stu.sex;
//    name = stu.name;
//    this->pay = 1500;
//
//    cout << endl << "转换完毕！" << endl;
//}

//Test
//int main() {
//    teacher t1(14444, "Li", "man", 133.4), t2;
//    student s1(20066, "Wang", "wom", 144.4);
//
//    cout << "stu 1:\n\n";
//    s1.display();
//    t2 = teacher(s1);
//    cout << "teac 2:\n\n";
//    t2.display();
//    return 0;
//
//}


//!------------------------------------------
class A {//继承！构造函数的练习举例
public:
    A() {
        a = 0;
        b = 0;
    }

    A(int i) {
        a = i;
        b = 0;
    }

    A(int i, int j) {
        a = i;
        b = j;
    }
    //三个构造函数

    void display() const {
        cout << a << "\t" << b << "\t";
    }


private:
    int a;
    int b;
};

class B : public A {
public:
    B() {
        c = 0;
    }

    B(int i) : A(i) {
        c = 0;
    }

    B(int i, int j) : A(i, j) {
        c = 0;
    }

    B(int i, int j, int k) : A(i, j) {
        c = k;
    }

    void display1() {
        display();
        cout << c << "\n";
    }

private:
    int c;
};


//test
//int main() {
//    B b1, b2(1), b3(1, 2), b4(1, 2, 3);
//    b1.display1();
//    b2.display1();
//    b3.display1();
//    b4.display1();
//    return 0;
//}


//!------------------------------------------
//教师和干部的多重继承派生教师兼干部, 记得从爸爸那里传参数过来！

class TeaChair { //茶几?这很合理
public:
    TeaChair(int a, string t) : age(a), title(std::move(t)) {}

    TeaChair() = default;

    void display() { cout << "age: " << age << "\tttitle: " << title << endl; }

protected:
    int age{};
    string title;
};


class ganbu {
public:
    ganbu(int a1, string t1) : age2(a1), post(std::move(t1)) {}

    ganbu() = default;

    void display() {
        cout << "age: " << age2 << "\tpost: " << post << endl;
    }

protected:
    int age2{};
    string post;
};


class pop : public TeaChair, public ganbu {
public:
    pop(int a1, string t1, int a, string t, float u) : ganbu(a1, std::move(t1)), TeaChair(a, std::move(t)), wage(u) {}

    void show() {
        TeaChair::display();

        cout << "wages: " << wage << endl;
    }

protected:
    float wage;
};

//Test
//int main() {
//    pop p1(22, "tt", 13, "ii", 43.44);
//    p1.show();
//}

//!------------------------------------------