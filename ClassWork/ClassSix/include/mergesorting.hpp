/**
 * @author AaronLi
 * @data 2023-05-22-上午10:48
 * @license GPL-3.0
 */

#ifndef CLASSWORK_MERGESORTING_HPP
#define CLASSWORK_MERGESORTING_HPP

/**
 * @title
 * 归并排序
 * @description
 * 分而治之思想
 */

#include <iostream>
#include <vector>

class MergeSort{
public:
   /**
    * @title
    * 拆分
    * @description
    * 将数组拆分，即分
    */
   void sortArray(int array[],int left, int right);
   
   /**
    * @title
    * 排序
    */
    static void mergeSort(int array[], int left,int middle, int right);
};
#endif //CLASSWORK_MERGESORTING_HPP
