/**
 * @author AaronLi
 * @data 2023-05-14-下午6:26
 * @license GPL-3.0
 */
#include "search.hpp"
#include "hashtable.hpp"

int search_for_function() {
    std::cout << "请输入您想要查找的字符串：\n";
    int number;
    std::vector<int> array;
    while (std::cin >> number) {
        array.push_back(number);
        if (std::cin.get() == '\n') break;
    }
    std::cout << "-----------------------------\n"
                 "1.顺序查找\n"
                 "2.二分查找\n"
                 "请选择您想要进行的排序和想要查找的数（例如：1 3）：";

    int option, target, result;
    std::cin >> option >> target;
    switch (option) {
        case 1:
            result = sequentialSearch(array, target);
            if (result) {
                std::cout << "目标下标值：" << result << "\n";
            } else {
                std::cout << "找不到目标值！\n";
            }
            break;
        case 2:
            result = binarySearch(array, target);
            if (result) {
                std::cout << "目标下标值：" << result << "\n";
            } else {
                std::cout << "找不到目标值！\n";
            }
            break;
        default:
            std::cout << "结束\n";
            return 0;
    }
    return 1;
}

int hash_table_for_function() {
    HashTable hashTable;
    hashTable.initHashTable(13);
    int array[] = {19, 8};
    for (int i : array) {
        hashTable.insert(i);
    }
    hashTable.printHashTable();
    return 0;
}

int main() {
    hash_table_for_function();
    return 0;
}