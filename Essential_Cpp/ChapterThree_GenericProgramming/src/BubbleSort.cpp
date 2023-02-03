/**
 * @file BubbleSort.cpp
 * @author AaronLi
 * @date 2023-02-03-下午4:19
 * @description
 */

#include "sort.hpp"

void BubbleSort(int arr[3][3],int length){
  int num=3;
  int arr_copy[3*length];
  int subscript =0;
  for (int i = 0; i < length; ++i) {
    for (int j = 0; j < num; ++j) {
      arr_copy[subscript++]=arr[i][j];
    }
  }

  for (int i = 0; i < subscript; ++i) {
    for (int j = 0; j < subscript - 1; ++j) {
      if(arr_copy[j]>arr_copy[j+1]) {
        int temporary = arr_copy[j];
        arr_copy[j] = arr_copy[j+1];
        arr_copy[j+1] = temporary;
      }
    }
  }

  subscript=0;
  for (int i = 0; i < length; ++i) {
    for (int j = 0; j < num; ++j) {
      arr[i][j] = arr_copy[subscript+j];
    }
    subscript+=3;
  }

}




