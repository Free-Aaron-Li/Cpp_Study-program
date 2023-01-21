/**
 * @file Chapter_2_2_VectorSort.cpp
 * @author AaronLi
 * @date 2023-01-18-下午5:16
 * @description
 * <p> 整数排序 </p>
 * <p></p>
 * <p>
 * 实现一个可对vector内的整数值加以排序的函数。
 * </p>
 * @link 
 */

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void display(vector<int> &vec, ostream &os);

void swap(int &val1, int &val2);

void bubble_sort(vector<int> &vec, ofstream *ofil);

/**
 * @date 23-1-18 下午6:37
 * @description
 * <p>显示vector</p>
 * <p></p>
 * <p>
 *  有时候用户希望提供一个不同的目的地，例如文件。<br/>
 *  通过让cout成为ostream参数，用户可以即选择输出在显示器上，也可以选择输入到自定义的文件夹中。
 * </p>
 */

void display(vector<int> &vec, ostream &os = cout) {
    for (int i: vec) {
        os << i << " ";
    }
    os << endl;
}

/**
 * @date 23-1-18 下午6:39
 * @description
 * 元素位置交换
 */

void swap(int &val1, int &val2) {
    int temp = val1;
    val1 = val2;
    val2 = temp;
}

/**
 * @date 23-1-18 下午6:41
 * @description
 * <p>冒泡排序</p>
 * <p></p>
 * <p>
 *  有时候我们需要对了解某个函数的调试信息，但是用户并不需要。<br/>
 *  这个时候，我们可以通过**设置默认值**方式，将bubble_sort()第二参数声明为ofstream对象的一个pointer，<br/>
 *  将默认值设置为nullptr（即0）表示并未指向任何ofstream对象。这样如果用户仅使用第一个参数，那么便不会输出调试信息，<br/>
 *  若需要调试信息，则可以调用第二个参数，指向某个ofstream对象，那么这个函数便会产生调试信息。<br/>
 * </p>
 */

void bubble_sort(vector<int> &vec, ofstream *ofil = nullptr) {
    for (int i = 0; i < vec.size(); ++i) {
        for (int j = i + 1; j < vec.size(); ++j) {
            if (vec[i] > vec[j]) {
                if (ofil != nullptr) {
                    /* 调试信息 */
                    (*ofil) << "about to call swap! i: " << i
                            << " j: " << j << "\tswapping: " << vec[i]
                            << " with " << vec[j] << endl;
                }
                swap(vec[i], vec[j]);
            }
        }
    }
}

/**
 * @date 23-1-19 下午2:41
 * @description
 * <p>以vector方式返回Fibonacci数列（元素个数由用户指定）</p>
 * <p></p>
 * <p>
 *  由于Fibonacci数列是固定的，所以为了节省开支。可以通过将Fibonacci数列设置为static vector静态局部对象。
 * </p>
 */

/* const vector是整个向量不能改动，包括不能修改元素，添加、删除元素；而vector是向量已有的元素不能改动，但是仍有向向量中添加元素等操作 */
const vector<int> *
fibon_seq(int size) {
    const int max_size = 46;
    static vector<int> elems;
    if (size <= 0 || size > max_size) {
        cerr << "fibon_seq(): oops: invalid size: "
             << size << " --cannot fulfill request. "
             << endl;
        return nullptr;
    }

    /* 如果size等于或小elems.size()，那就不必计算 */
    for (int i = int(elems.size()); i < size; ++i) {
        if (i == 0 || i == 1) {
            elems.push_back(1);
        } else {
            elems.push_back(elems[i - 1] + elems[i - 1]);
        }
    }
    return &elems;
}

int main() {

    /* 调试信息log */
    ofstream ofil("../data.txt");

    int a[8] = {8, 24, 4, 23, 25, 412, 3, 341};
    /* vector(begin,end):复制[begin,end)区间内另一个数组的元素到vector中 */
    vector<int> vec(a, a + 8);
    int fibon_size = 0, fibon_length = 0;

    /* 并不产生调试信息 */
    display(vec);
    bubble_sort(vec);
    cout << "vector after sort: \n";
    display(vec);

    /* 产生调试信息 */
    bubble_sort(vec, &ofil);
    cout << "vector after sort: \n";
    display(vec, ofil);
    cout << endl;

    cout << "Please enter Fibonacci max length you want: ";
    cin >> fibon_size;
    cout << endl;
    /* 调用fibon_seq()，打印Fibonacci数列 */
    for (auto fibon: *fibon_seq(fibon_size)) {
        cout << fibon << " ";
    }
    cout << endl;

    for (auto fibon: *fibon_seq(3)) {
        cout << fibon << " ";
    }
    cout << endl;

    cout << "Please enter Fibonacci length you want: ";
    cin >> fibon_length;
    const vector<int> *fibonacci = fibon_seq(fibon_length);
    if(!fibonacci){
        return 0;
    }

    for (int i = 0; i < fibon_length; ++i) {
        cout << (*fibonacci)[i] << " ";
    }
    cout << endl;
}
