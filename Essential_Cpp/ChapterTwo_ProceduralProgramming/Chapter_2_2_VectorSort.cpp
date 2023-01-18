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

using namespace std;

void display(vector<int> &vec);

void swap(int &val1, int &val2);

void bubble_sort(vector<int> &vec);

/**
 * @date 23-1-18 下午6:37
 * @description
 * 显示vector
 */

void display(vector<int> &vec) {
    for (int i : vec) {
        cout << i << " ";
    }
    cout << endl;
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
 * 冒泡排序
 */

void bubble_sort(vector<int> &vec) {
    for (int i = 0; i < vec.size(); ++i) {
        for (int j = i + 1; j < vec.size(); ++j) {
            if (vec[i] > vec[j]) {
                swap(vec[i], vec[j]);
            }
        }
    }
}

int main() {
    int a[8] = {8, 24, 4, 23, 25, 412, 3, 341};
    /* vector(begin,end):复制[begin,end)区间内另一个数组的元素到vector中 */
    vector<int> vec(a, a + 8);

    display(vec);
    bubble_sort(vec);

    cout << "vector after sort: \n";
    display(vec);
    cout << endl;
}






































