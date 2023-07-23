#include<iostream>

using namespace std;


//! --------------------------------------------------------
//Shape 派生三个派生，用一个输出函数来输出他们的周长
class Shape {
public:
    virtual double ci() = 0;

private:
    //虚基类，，
};


class Circle : public Shape {
public:
    virtual double ci() {
        return 2 * 3.1415926 * r;
    }

    explicit Circle(double ra) {
        r = ra;
    }


private:
    double r;

};

class Triangle : public Shape {
public:
    virtual double ci() {
        return a + b + c;
    }

    Triangle(double ai, double bi, double ci) {
        a = ai;
        b = bi;
        c = ci;
    }

private:

    double a;
    double b;
    double c;
};

class Rectangle : public Shape {
public:
    virtual double ci() {
        return 2 * (a + b);
    }

    Rectangle(double ai, double bi) {
        a = ai;
        b = bi;
    }

private:
    double a;
    double b;
};

//output function
void printci(Shape *s) {
    cout << s->ci() << endl;
}

// Test
//int main() {
//    Circle c(3);
//    Triangle t(3, 4, 5);
//    Rectangle r(3, 5);
//    Shape *p[3] = {&c, &t, &r};
//    int i;
//    for (i = 0; i < 3; i++) 
//        printci(p[i]);
//    return 0;
//}

//! --------------------------------------------------------