/**
 * @file main.cpp
 * @author AaronLi
 * @date 2023-02-03-下午12:22
 * @description
 */
#include "sort.hpp"

int main() {
  int arr[3][3]={{10,4,3},{14,7,6},{17,21,32}};
  BubbleSort(arr,3);
  Print(arr,3);
}
