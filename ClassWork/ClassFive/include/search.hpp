/**
 * @author AaronLi
 * @data 2023-05-14-下午6:32
 * @license GPL-3.0
 */

#ifndef CLASSWORK_SEARCH_HPP
#define CLASSWORK_SEARCH_HPP

#include <iostream>
#include <vector>

/**
 * 顺序查找
 * */
template<typename T>
int sequentialSearch(T &array, int target) {
    int length = sizeof(array) / sizeof(array[0]);
    for (int i = 0; i < length; ++i) {
        if (target == array[i]) return i;
    }
    return 0;
}

template<typename T>
int Increasing(T &array) {
    int length = sizeof(array) / sizeof(array[0]) - 1;
    int temporary;

    for (int i = 0; i < length; ++i) {
        int min_index = i;
        for (int j = min_index + 1; j < length; ++j) {
            if (array[j] < array[min_index]) min_index = j;
        }
        temporary = array[i];
        array[i] = array[min_index];
        array[min_index] = temporary;
    }
}

/**
 * 二分查找，递增数组
 */
template<typename T>
int binarySearch(T &array, int target) {
    int length = sizeof(array) / sizeof(array[0]) - 1;

    int label = 0;
    for (int i = 1; i < length; i++) {
        if (array[i] < array[i - 1]) label = 1;
    }
    if (label != 0) {
        Increasing(array);
    }
    int left = 0;
    int right = length - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (target == array[mid]) return mid;
        else if (target < array[mid]) right = mid - 1;
        else left = mid + 1;
    }
    return 0;
}


#endif //CLASSWORK_SEARCH_HPP
