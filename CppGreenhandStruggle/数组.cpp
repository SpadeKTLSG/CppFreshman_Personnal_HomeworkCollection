#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

//!------------------------------------------
void swap(int *a, int *b) { //交换两个数
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;

}


void io_interact() {  //交互输入输出

    int a[5], i;

    for (i = 0; i < 5; i++) {
        cout << endl << "请输入第" << i + 1 << "个数   ";
        cin >> a[i];
    }

    cout << endl << "刚输入的5个数是: ";

    for (i = 0; i < 5; i++) {
        cout << setw(4) << a[i];
        if (i % 5 == 0)
            cout << endl;
    }
}


void reverse_arr(int arr[], int n) { //数组倒序

    for (int i = 0; i < n / 2; i++)
        swap(&arr[i], &arr[n - i - 1]);
}


void search(int arr[], int n, int x) { //简单查找,附带可能的计数功能

    int i, count = 0;

    for (i = 0; i < n; i++)
        if (arr[i] == x) {
            cout << endl << "找到该元素，其下标为：" << setw(3) << i;
            count++;
        }
    if (count == 0)
        cout << endl << "未找到该元素！" << endl;
}


void search_half(int arr[], int n, int x) { //初级二分查找

    int i = 0, j = n - 1, mid;

    while (i <= j) {
        mid = (i + j) / 2;
        if (arr[mid] == x) {
            cout << endl << "找到该元素，其下标为：" << mid;
            return;
        } else if (arr[mid] > x)
            j = mid - 1;
        else
            i = mid + 1;
    }
    cout << endl << "未找到该元素！" << endl;
}


void bubbling(int a[], int n) {  //冒泡排序
    int k;
    for (int j = 1; j <= n - 1; j++) {
        for (int i = 1; i <= n - j; i++) {
            if (a[i] > a[i + 1]) {
                swap(&a[i], &a[i + 1]);
            }
        }
    }
}


void select(int a[], int n) { //选择排序
    int k;
    for (int i = 0; i < n - 1; i++) {
        k = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[k])
                k = j;
            swap(&a[i], &a[k]);
        }
    }
}


int find_prime(int N) { //素数,返回结果
    int a[N + 1];
    for (int i = 2; i <= N; i++)
        a[i] = i;

    for (int i = 2; i <= sqrt(N); i++) {
        for (int j = i * i; j <= N; j += i) {
            if (a[i] != 0 && a[j] != 0)
                if (a[j] % a[i] == 0)
                    a[j] = 0;
        }
    }

    for (int i = 2, count = 0; i <= N; i++) {
        if (a[i] != 0) {
            cout << setw(5) << a[i] << " ";
            count++;
        }
        if (count == 10) {
            cout << endl;
            count = 0; //每10个换行
        }
    }
    return 0;
}


void binary_search(int N) { //交互式二分查找
    int a[N];
    cout << "put in the data:  " << endl;
    cin >> a[0];

    for (int i = 1; i < N; i++) {
        cin >> a[i];
        if (a[i] < a[i - 1]) {
            cout << "enter the data again!" << endl;
            i--;
        }
    }

    cout << endl;
    for (int i = 0; i < N; i++)
        cout << a[i] << endl;
    cout << endl;

    int num, start, end, middle;
    char c = 'Y';

    while (c == 'Y') { //第一次尝试这种循环阻塞的糖
        cout << "input number to look for:  ";
        cin >> num;
        start = 0;
        end = N - 1;

        while (start <= end) {
            middle = (start + end) / 2;
            if (num == a[middle]) {
                cout << "Find " << num << ",It's position is  " << middle + 1 << endl;
                break;
            } else {
                if (num < a[middle])
                    end = middle - 1;
                else
                    start = middle + 1;
            }
        }

        if (start > end)
            cout << "No, she answer." << endl;

        cout << "continue or not??? N" << endl;
        cin >> c;
    }
}


//!----------------------------------------------------------------------------------------------------------------------
//综合问题: 日期判断是第几天（考虑闰年的问题，同时输出是否闰年run=1） 我写的思路：主函数输入日期，然后建立每个月的日期总数数组，然后加上前面，和本月日期数相加求和。如果是闰年再在二月后的每个月加上一天作为补充。
int runnian(int n) {
    return (n % 4 == 0 && n % 100 != 0 || n % 400 == 0) ? 1 : 0;
}

void Sum_day(int m, int d, int run) {
    int i;
    int Sn = 0;

    int a[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for (i = 1; i < m; i++) {
        Sn = Sn + a[i];
        if (i == m)
            Sn = Sn + d;
    }
    if (run == 1 && m > 2)
        Sn++;

    cout << Sn;
}

void whichday1() {
    int year, month, day, run;
    cout << "put in the year ,month , day,plz " << endl;
    cin >> year >> month >> day;
    run = runnian(year);
    Sum_day(month, day, run);
}

//2用结构体的做法：

struct Date {
    int year;
    int month;
    int day;
};

void whichday2() {
    Date date{};
    int days;
    cout << "input year,month,day:";
    cin >> date.year >> date.month >> date.day;
    switch (date.month) {
        case 1:
            days = date.day;
            break;
        case 2:
            days = date.day + 31;
            break;
        case 3:
            days = date.day + 59;
            break;
        case 4:
            days = date.day + 90;
            break;
        case 5:
            days = date.day + 120;
            break;
        case 6:
            days = date.day + 151;
            break;
        case 7:
            days = date.day + 181;
            break;
        case 8:
            days = date.day + 212;
            break;
        case 9:
            days = date.day + 243;
            break;
        case 10:
            days = date.day + 273;
            break;
        case 11:
            days = date.day + 304;
            break;
        case 12:
            days = date.day + 334;
            break;
    }
    if ((date.year % 4 == 0 && date.year % 100 != 0 || date.year % 400 == 0) && date.month >= 3)
        days = days + 1;
    cout << date.month << "/" << date.day << " is the " << days << "th day in " << date.year << "." << endl;
}


//3结构体数组指针的做法:

int days(Date *p);

void whichday3() {
    Date date{};
    int day_sum;
    cout << "input year,month,day:";
    cin >> date.year >> date.month >> date.day;
    day_sum = days(&date);
    cout << date.month << "/" << date.day << " is the " << day_sum << "th day in " << date.year << "." << endl;
}

int days(Date *p) {
    int sum, i;
    int day_tab[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    sum = 0;
    for (i = 0; i < p->month - 1; i++)
        sum += day_tab[i];
    sum += p->day;
    if ((p->year % 4 == 0 && p->year % 100 != 0 || p->year % 4 == 0) && p->month >= 3)
        sum += 1;
    return sum;
}

//!----------------------------------------------------------------------------------------------------------------------

//密码翻译: 第一个字母变成最后一个
const int N = 6;

void pin_reader1() {
    char ch[N], tran[N];

    cout << "\ninput your code here.";
    for (char &i: ch)
        cin >> i;

    for (int j = 0; j < N; j++) {
        if ((ch[j] >= 'A') && (ch[j] <= 'Z'))
            tran[j] = 155 - ch[j];
        else if ((ch[j] >= 'a') && (ch[j] <= 'z')) {
            tran[j] = 219 - ch[j];
        } else
            tran[j] = ch[j];
    }

    cout << "\n the result is that :";
    for (char j: tran)
        cout << j;
}


void pin_reader() {
    string ch = "  ";
    char *p = &ch[0];

    cout << "input the code plz ; \n";
    gets_s(p, 100);
    cout << "your code is that : " << ch << endl;
    for (int j = 0; j <= ch.size(); j++) {
        if (ch[j] >= 'A' && ch[j] <= 'Z')
            ch[j] = 155 - ch[j];
        else if (ch[j] >= 'a' && ch[j] <= 'z')
            ch[j] = 219 - ch[j];
        else
            ch[j] = ch[j];
    }
}

//!----------------------------------------------------------------------------------------------------------------------