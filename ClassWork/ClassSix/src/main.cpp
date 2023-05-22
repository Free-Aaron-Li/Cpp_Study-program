/**
 * @author AaronLi
 * @data 2023-05-22-上午10:24
 * @license GPL-3.0
 */
#include "mergesorting.hpp"
#include "quicksorting.hpp"

void test_merge_sort() {
    int array[] = {4, 6, 3, 74, 2, 1, 9, 234};
    std::cout << "before sort: ";
    for (auto e: array)
        std::cout << e << " ";
    MergeSort mergeSort;
    mergeSort.sortArray(array, 0, 7);
    std::cout << "\nafter sort: ";
    for (auto e: array)
        std::cout << e << " ";
}

void test_quick_sort() {
    int array[] = {4, 6, 3, 74, 2, 1, 9, 234};
    std::cout << "before sort: ";
    for (auto e: array)
        std::cout << e << " ";
    QuickSort quickSort;
    quickSort.quickArray(array, 0, 7);
    std::cout << "\nafter sort: ";
    for (auto e: array)
        std::cout << e << " ";
}

int main() {
    test_merge_sort();
    test_quick_sort();
    return 0;
}
