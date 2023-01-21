/**
 * @file Chapter_2_1_Test.cpp
 * @author AaronLi
 * @date 2023-01-17-下午3:24
 * @description
 * <p> 多次执行 </p>
 * <p></p>
 * <p>
 * 依照Chapter_2_1_Function所提供的函数，修改main()，实现允许用户不断输入位置值，直到用户希望停止。
 * </p>
 * @link 
 */

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

/**
 * @date 23-1-16 下午10:25
 * @description
 * <p> 函数声明 </p>
 * <p></p>
 * <p>
 * 函数必须先被声明，才能被调用。函数声明使得编译器得以检查后续出现的使用方法是否正确。
 * </p>
 */

bool fibon_elem(int pos, int &elem);

bool print_sequence(int pos);

bool is_size_ok(int size);

void display_message(char);

void display_message(const string &);

void display_message(const string &, int);

/**
 * @date 23-1-19 下午7:17
 * @description
 * <p> 重载display_message() </P>
 */

void display_message(char ch) {
    cout << ch << endl;
}

void display_message(const string &str) {
    cout << str << endl;
}

void display_message(const string &str, int number) {
    cout << "The message is: " << str
         << " " << number
         << endl;
}

/**
 * @date 23-1-19 下午6:00
 * @description
 * <p> 判断用户输入的Fibonacci数列位置是否可计算 </P>
 */

bool is_size_ok(int size) {
    const int max_size = 46;
    const string msg("Requested size is not supported");
    /* 检查位置值是否合理 */

    if (size <= 0 || size > max_size) {
        /* 通过使用通用的display_message函数，取代原先让每个函数自行产生调试信息的方式 */

        /* cerr << "Invalid position: " << size
              << " -- cannot handle request!\n\t";*/
        display_message(msg, size);
        return false;
    }

    /* 更为激进一些，直接终止该程序并输出pos值。当然在这里使用返回boolean值方式。除此之外，还可以使用抛出异常方法 */
    /* if (pos <= 0 || pos>1024){
         exit(-1);
     }*/

    return true;
}

/**
 * @date 23-1-19 下午6:03
 * @description
 * <p> 计算数列 </P>
 * <p></p>
 * <p>
 *  计算Fibonacci数列中的size个元素，并返回持有这些元素的静态容器的地址
 * </p>
 */

const vector<int> *
fibon_seq(int size) {
    static vector<int> elems;

    if (!is_size_ok(size)) {
        return nullptr;
    }
    for (int i = int(elems.size()); i < size; ++i) {
        if (i == 0 || i == 1) {
            elems.push_back(1);
        } else {
            elems.push_back(elems[i - 1] + elems[i - 2]);
        }
    }

    return &elems;
}

/**
 * @date 23-1-17 下午3:28
 * @description
 * 打印用户提供位置值对应Fibonacci数列
 */

bool print_sequence(int pos) {
    if (pos <= 0 || pos > 1024) {
        cerr << "invalid position: " << pos
             << "-- cannot handle request!\n" << endl;
        return false;
    }
    string str="The Fibonacci Sequence for";
    display_message(str,pos);

    /* 无论调用者指定那个元素位置，都会输出1 1 。除非指定位置值为1 */
    switch (pos) {
        default:
        case 2:
            cout << "1 ";
            /* 注意这里没有break */
        case 1:
            cout << "1 ";
            break;
    }

    int elem;
    int n_2 = 1, n_1 = 1;
    for (int i = 3; i <= pos; ++i) {
        elem = n_2 + n_1;
        n_1 = n_2;
        n_2 = elem;

        /* 一行打印十个元素 */
        cout << elem << (!(i % 10) ? "\n" : " ");
    }
    cout << endl;
    return true;
}

/**
 * @date 23-1-16 下午11:32
 * @description
 * 返回Fibonacci数列指定元素<br/>
 * pos：数列中的元素位置（由调用者指定）<br/>
 * n_2,n_1：持有前两个元素的值 <br/>
 * elem：持有即将返回的值 <br/>
 * 通过使用inline关键字的方式使fibon_elem成为内联函数，将fibon_elem()调用的三个函数写入fibon_elem()内，但依然维持三个独立的运算单元。<br/>
 * 以此保证在执行性能不够理想的情况下，依旧保证良好的编程规范。<br/>
 */

inline bool fibon_elem(int pos, int &elem) {

    const vector<int> *pseq = fibon_seq(pos);

    if (!pseq) {
        elem = 0;
        return false;
    }

    print_sequence(pos);

    elem = (*pseq)[pos - 1];
    return true;
}


int main() {
    int pos, elem;
    char sign = 'y';
    bool flag = true;
    while (flag) {
        cout << "Please enter the position value you want: ";
        cin >> pos;
        if (fibon_elem(pos, elem)) {
            cout << "The position value: " << pos
                 << " The element is: " << elem << "\n"
                 << endl;
        } else {
            cout << "Sorry,cannot calculate element: " << pos
                 << endl;
        }

        display_message("would you like to try again? (y/n) ");
        cin >> sign;
        if (sign != 'y' && sign != 'Y') {
            flag = false;
        }
    }
}