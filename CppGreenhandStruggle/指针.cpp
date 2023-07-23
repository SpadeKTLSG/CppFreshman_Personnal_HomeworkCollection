#include<iostream>
#include <cstdio>
#include <tchar.h>
using namespace std;

//!------------------------------------------
int swap(int *k1, int *k2) { //int类型的交换
    int t;
    t = *k2;
    *k2 = *k1;
    *k1 = t;
    return 0;
}


void change(char *p1, char *p2) { //string类型的交换
    char p[20];
    strcpy(p, p1);
    strcpy(p1, p2);
    strcpy(p2, p);
}


//!------------------------------------------
void basic_compare() {//输入三个字符串，从小到大输出
    void swap(char *, char *);
    char a[20], b[20], c[20];
    cout << "put in three words" << endl;
    gets_s(a, 20);
    gets_s(b, 20);
    gets_s(c, 20);
    if (strcmp(a, b) > 0) change(a, b);
    if (strcmp(b, c) > 0) change(b, c);
    if (strcmp(b, c) > 0) change(b, c);
    cout << "the result are that: " << endl << a << endl << b << endl << c;
}


void exchange(int *number) {
    int *max, *min, *p, t;
    max = min = number;//初始化max，min的指向，让p去遍历整个结构

    for (p = number + 1; p < number + 10; p++) {
        if (*p > *max) max = p;
        if (*p < *min) min = p;
    }

    swap(number, min);
    if (*max == number[0]) //如果最大的数在第一个那么需要特殊处理
        max = min;
    swap(number + 9, max);
}


void funnychange() { //输入整数调整最小的和第一个兑换，最大的和最后一个对换
    int number[10];
    for (int &i: number)
        cin >> i;
    exchange(number);
    for (int i: number)
        cout << i;
}


void fun(int *a, int n, int m) { //前面各数向后面移动m个位置，最后m数变成最前面m个数
    int *p, end;
    end = *(a + n - 1);// == end = a[n-1];
    for (p = a + n - 1; p > a; p--)
        *p = *(p - 1); //从后往前挨个把数字往后板

    a[0] = end;
    m--;
    if (m > 0)
        fun(a, n, m);
}


void situp_kill() {//n人站一圈，第一个人开始报数1，2，3，报道3的人死去。问最后的那个人是第几号
    //my思路：建立从1-50（取n=50），然后按照标记变量y的1-3，if为3，令其为0；然后遍历数组，如果发现零有49个，就停止，并输出那个数; 死人不会报数

    int k = 0, i = 0, m = 0, n = 0, a[50], *p = a;
    cout << "input number of the mass: n =(n<50) ";
    cin >> n;
    for (i = 0; i < n; i++)
        *(p + i) = i + 1;     //number everyone from 1-n;


    while (m < n - 1) {
        if (*(p + i) != 0)
            k++;
        if (k == 3) {
            *(p + i) = 0;
            k = 0;
            m++;
        }
        i++;
        if (i == n)
            i = 0;
    }

    while (*p == 0)
        p++;
    cout << "result:   No.  " << *p << endl;
}


//!------------------------------------------
void funnnycopy() { //n个字符的字符串，将它从第m个字符开始的全部字符复制到另一个新的字符串；我用string法，书本的指针法：
    void copystr(char *, char *, int); //声明函数
    int m;
    char str1[20], str2[20];
    cout << "input" << endl;
    gets_s(str1, 20);
    cout << "put in the m   ";
    cin >> m;
    if (strlen(str1) < m)
        cout << "error" << endl;
    else {
        copystr(str1, str2, m);
        cout << "result    " << str2 << endl;
    }
}


void copystr(char *p1, char *p2, int m) {
    int n = 0;

    while (n < m - 1) {
        n++;
        p1++;
    }

    while (*p1 != '\0') {//对齐第一个与第二个，
        *p2 = *p1;
        p1++;
        p2++;
    }
    *p2 = '\0'; //手动加上结束符
}


//!------------------------------------------
void input(int f[3][3]) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cin >> f[i][j];
}

void output(int f[3][3]) {
    int w = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << f[i][j] << "  ";
            w++;
            if (w % 3 == 0)
                cout << endl;
        }
    }
}

void reverse(int a[3][3], int b[3][3]) {
    int y = 0, u = 0;
    for (int i = 0; i < 3; i++) {
        u = 0;
        for (int j = 2; j >= 0; j--) {
            b[y][u] = a[j][i];
            u++;
        }
        y++;
    }
}

void matrixMagic() {//90°转置3×3矩阵   头猪：改变阅读方向，把书横过来阅读就是转置的了，就搞一个新数组，把原来的按照新的顺序进行输入，最后输出两个数组：使用函数。進め！

    int a[3][3], b[3][3];
    cout << "put in your numbers in array 3*3;  " << endl;
    input(a);
    cout << endl;

    output(a);
    reverse(a, b);

    cout << endl << "  the results are thats : " << endl;
    output(b);
}


//!------------------------------------------
//我是废物。。。以下是没做出来的题目，我是废物。。。呜呜呜
//! 下面内容一笔未改, 要的就是原汁原味 : )
const int N = 3;

void newoutput(int f[N][N]);

void newinput(int f[N][N]);

void max(int *);

void CHange(int *, int *);

void min(int *p1, int *p2, int c);

void copy(int *p1, int *p2);

void change(int *p1, int *p2);

void makemaxest(int *p);

void fun_min(int *p1, int *p2);


//这里N为奇数，所以下面对于中心的定义会有变化，有数学原理得到是：N/2（中心）；
int main() {
    int a[N][N], b[N][N];
    int *p1, *p2;
    p1 = &a[0][0];
    p2 = &b[0][0];
    //definition...


    cout << "put in your numbers in array 3*3; (the number < 114514)  " << endl;
    newinput(a);
    cout << "That is your array" << endl;
    newoutput(a);


    copy(p1, p2);
    //b is now the copy of a,and now you can delete items in b random to easily find the minus num.
    //尽情搞b！
    cout << endl;
    CHange(p1, p2);

    //the end...
    cout << endl << "  the results is  : " << endl;
    newoutput(a);
    cout << endl << "the mirror:  ";
    newoutput(b);
    cout << endl << endl;
}

//  Core of the funtion 
void CHange(int *p1, int *p2) {
    max(p1);
    copy(p1, p2);
    fun_min(p1, p2);
}

// Second Core of the funtion.
void fun_min(int *p1, int *p2) {
    int i = 1;
    for (i = 1; i < 5; i++) {
        min(p1, p2, i);
    }

}

void newinput(int f[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> f[i][j];
        }
    }
}

void newoutput(int f[N][N]) {
    int w = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << f[i][j] << "  ";
            w++;
            if (w % N == 0) {
                cout << endl;
            }
        }
    }

}

void max(int *p) {
    int *pm, i, j;
    pm = p;
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++) {
            if (*(p + i * N + j) > *pm) {
                pm = p + i * N + j;
            }
        }

    change(pm, p + N * N / 2 + N / 2);  //p+N*N/2+N/2 is the center of the array;

}


void min(int *p1, int *p2, int c) {
    int *pm, i, j;
    int u = 0;   //follow the map! man.
    pm = p1;
    int *pm2;
    pm2 = p2;
    // the b is the const;
    int k1, k2, k3;
    k3 = k2 = k1 = 114514;

    switch (c) {
        case 1:
            u = 0;
        case 2:
            u = N - 1, k1 = N - 1;
        case 3:
            u = N * (N - 1), k2 = N * (N - 1), k1 = N - 1;
        case 4:
            u = N * N - 1, k3 = N * N - 1, k2 = N * (N - 1), k1 = N - 1;
    }

    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++) {

            if ((*(p2 + i * N + j) < *pm)) {
                if ((pm != p1 + k1) && (pm != p1 + k2) && (pm != p1 + k3)) {
                    pm = p1 + i * N + j;
                    pm2 = p2 + i * N + j;
                }
            }
        }

    change(pm, p1 + u);
    change(pm2, p2 + u);

    makemaxest(pm2);
}


void change(int *p1, int *p2) {
    int t;
    t = *p1;
    *p1 = *p2;
    *p2 = t;

}

void copy(int *p1, int *p2) {//  copy:   a->b 
    int i = 0, j = 0;
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++) {
            *(p2 + i * N + j) = *(p1 + i * N + j);
        }

}

void makemaxest(int *p) {
    *p = 114514;

}

//1.02版本更新：发现结果除了最后一次的右下角没事之外，其他的位置会因为转换而变化，后面的变换把之前的给覆盖掉了。失败。
//可能：建立最大，次小的分别的变量。）没意思确信。
//意思到了，镜面还有一个覆盖的问题等待修复。
//我又明白了！使用镜像数组不如使用覆盖的精准定位法。。。

//! 两年后的锐评: 这写的什么东西?!可以看出来已经写疯了
//! ----------------------------------------------