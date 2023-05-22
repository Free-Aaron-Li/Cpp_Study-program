/**
 * @author AaronLi
 * @data 2023-05-22-下午2:52
 * @license GPL-3.0
 */

#include "quicksorting.hpp"

int QuickSort::Random(int first_number, int second_number) {
    time_t seed = time(nullptr);
    /* 创建随机数引擎 */
    std::default_random_engine eng(seed);
    /* 创建一个分布 */
    std::uniform_int_distribution<int> dist(first_number, second_number);
    return dist(eng);
}

int QuickSort::RandomizedPartition(int *a, int first_number, int second_number) {
    /* 从first_number和second_number中随机抽取一个数 */
    int random_number = Random(first_number, second_number);
    Swap(a[first_number], a[random_number]);
    /*  */
    return Partition(a, first_number, second_number);
}

void QuickSort::Swap(int &i, int &j) {
    int temporary_number;
    temporary_number = i;
    i = j;
    j = temporary_number;
}

int QuickSort::Partition(int *a, int first_number, int second_number) {
    int i = first_number, j = second_number + 1;
    int x = a[first_number];
    /* 将小于x的元素交换到左边区域，否则交换到右边区域 */
    while (true) {
        while ((a[++i] < x) && (i < second_number));
        while (a[--j] > x);
        if (i >= j) break;
        Swap(a[i], a[j]);
    }
    a[first_number] = a[j];
    a[j] = x;
    return j;
}

void QuickSort::quickArray(int a[], int first_number, int second_number) {
    if (first_number < second_number) {
        /* 采用随机选择策略划分 */
        int middle = RandomizedPartition(a, first_number, second_number);
        /* 对左序列排序 */
        quickArray(a, first_number, middle - 1);
        /* 对右序列排序 */
        quickArray(a, middle + 1, second_number);
    } else return;
}


