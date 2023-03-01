/**
 * @author AaronLi
 * @date 2023-02-27-上午11:40
 * @license GPL-3.0
 */
#include "swap.hpp"

template <typename T>
void Swap(T &a, T &b) {
    T temporary = a;
    a           = b;
    b           = temporary;
}

template <typename T>
void Print(T &array, int length) {
    std::cout << "Original Array: " << std::endl;
    for (int i = 0; i < length; ++i) { std::cout << " " << array[i] << " "; }
}

template <class T>
void SelectionSort(T &array, int length) {
    for (int i = 0; i < length-1; ++i) {
        int maximum_subscript = i;
        for (int j = i + 1; j < length; ++j) {
            if (array[maximum_subscript] < array[j]) { maximum_subscript = j; }
        }
        if (maximum_subscript != i) { Swap(array[i], array[maximum_subscript]); }
    }

    Print(array, length);
}

int Test() {
    int array[] = {32,5234,2432,6784,97849,79056,25,142,54,6,3};
    SelectionSort(array,sizeof(array)/sizeof(int));

    std::cout<<std::endl;
    char char_array[]="baourlafmasg";
    SelectionSort(char_array,sizeof(char_array)/sizeof(char));
    return 0;
}