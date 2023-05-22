/**
 * @author AaronLi
 * @data 2023-05-22-下午2:51
 * @license GPL-3.0
 */


#ifndef CLASSWORK_QUICKSORT_HPP
#define CLASSWORK_QUICKSORT_HPP

/**
 * @title
 * 随机选择策略的快速排序
 */


#include <ctime>
#include <iostream>
#include <random>

class QuickSort {
public:
    /**
     * @title
     * 随机功能
     */
    static int Random(int first_number, int second_number);

    /**
     * @title
     * 随机划分
     */
    static int RandomizedPartition(int a[], int first_number, int second_number);

    /**
     * @title
     * 交换
     */
    static void Swap(int &i, int &j);

    /**
     * @title
     * 划分左右数组
     * @description
     * 将first_number设为数组下界，second_number设为数组上界
     */
    static int Partition(int a[], int first_number, int second_number);

    /**
     * @title
     * 快速排序
     */
    void quickArray(int a[], int first_number, int second_number);
};

#endif //CLASSWORK_QUICKSORT_HPP
