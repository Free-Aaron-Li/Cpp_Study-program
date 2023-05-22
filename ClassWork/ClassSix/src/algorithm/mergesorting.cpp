/**
 * @author AaronLi
 * @data 2023-05-22-上午10:48
 * @license GPL-3.0
 */
#include "mergesorting.hpp"

void MergeSort::sortArray(int array[], int left, int right) {
    if (left < right) {
        int middle = (left + right) / 2;
        sortArray(array, left, middle);         /* 拆解左序列 */
        sortArray(array, middle + 1, right);     /* 拆解右序列 */
        mergeSort(array, left, middle, right);       /* 排序 */
    }
}

void MergeSort::mergeSort(int array[], int left, int middle, int right) {
    int *temp_array = new int[right - left + 1];
    int i = left, j = middle + 1, k = 0;
    while (i <= middle && j <= right) {
        if (array[i] < array[j]) {
            temp_array[k] = array[i];
            i++;
        } else {
            temp_array[k] = array[j];
            j++;
        }
        k++;
    }

    /* 未比较数全部添加至临时vector中 */
    while (i <= middle) {
        temp_array[k] = array[i];
        i++;
        k++;
    }

    while (j <= right) {
        temp_array[k] = array[j];
        j++;
        k++;
    }

    i = left;
    for (int temp_k = 0; temp_k < k && i <= right; ++temp_k) {
        array[i] = temp_array[temp_k];
        ++i;
    }
}

