/**
 * @file Test1_6.cpp
 * @author AaronLi
 * @date 2022-12-28-下午3:27
 * @description
 * <p> 练习1.6 </p>
 * <p></p>
 * <p>
 * 编写一个程序，从标准输入设备读取一串整数，并将读入的整数依次放到array及vector，然后遍历这两种容器，
 * 求取数值总和。将总和及平均值输入至标准输入设备。
 * </p>
 * @link 
 */
#include <iostream>
#include <vector>

using namespace std;

/**
 * @date 22-12-28 下午4:00
 * @description 使用vector实现
 */

int main() {
    vector<int> num_vector;
    int num_value;
    while (cin >> num_value) {
        /*   将新输入的内容添加到num_string中 push_back 在数组的最后添加一个数据 */
        num_vector.push_back(num_value);
    }

    int sum = 0;
    for (int i: num_vector) {
        sum += i;
    }
    int average = (int) (sum / num_vector.size());

    cout << "Sum of " << num_vector.size()
         << ",elements:" << sum
         << ",average:" << average << endl;
    return 0;
}

/**
 * @date 22-12-28 下午4:05
 * @description 使用array实现
 */
/*

int main() {
    const int array_size = 128;
    int num_array[array_size];
    int num_value, num_input = 0;

    while (cin >> num_value && num_input < array_size) {
        num_array[num_input++] = num_value;
    }

    int sum = 0;
    for (int j = 0; j < num_input; ++j) {
        sum += num_array[j];
    }
    int average = sum / num_input;

    cout << "Sum of " << num_input
         << ",elements:" << sum
         << ",average:" << average << endl;
    return 0;
}
*/
