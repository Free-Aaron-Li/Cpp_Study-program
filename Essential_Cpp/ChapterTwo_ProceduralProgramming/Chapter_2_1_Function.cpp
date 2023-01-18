/**
 * @file Chapter_2_1_Function.cpp
 * @author AaronLi
 * @date 2023-01-16-下午10:21
 * @description
 * <p> 2.1节 编写函数 </p>
 * <p></p>
 * <p>
 * 作为一个示例函数，用于返回Fibonacci数列中由用户指定的某个位置的元素
 * </p>
 * @link 
 */

#include <iostream>
#include <cstdlib>

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

/**
 * @date 23-1-16 下午11:32
 * @description
 * 返回Fibonacci数列指定元素<br/>
 * pos：数列中的元素位置（由调用者指定）<br/>
 * n_2,n_1：持有前两个元素的值 <br/>
 * elem：持有即将返回的值 <br/>
 */

bool fibon_elem(int pos, int &elem) {
    /* 检查位置值是否合理 */

    if (pos <= 0 || pos > 46) {
        cerr << "Invalid position: " << pos
             << " -- cannot handle request!\n\t";
        elem = -1;
        return false;
    }

    /* 更为激进一些，直接终止该程序并输出pos值。当然在这里使用返回boolean值方式。除此之外，还可以使用抛出异常方法 */
    /* if (pos <= 0 || pos>1024){
         exit(-1);
     }*/

    elem = 1;
    int n_2 = 1, n_1 = 1;
    for (int i = 3; i <= pos; ++i) {
        elem = n_1 + n_2;
        n_2 = n_1;
        n_1 = elem;
    }

    print_sequence(pos);

    return true;
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
    cout << "The Fibonacci Sequence for "
         << pos << " position:\n\t" << endl;

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

int main() {
    int pos;
    cout << "Please enter a position: ";
    cin >> pos;
    int elem;
    if (fibon_elem(pos, elem)) {
        cout << "element #" << pos
             << " is " << elem << endl;
    } else {
        cout << "Sorry, Could not calculate element #" << pos
             << endl;
    }
}




