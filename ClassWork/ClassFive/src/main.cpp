/**
 * @author AaronLi
 * @data 2023-05-14-下午6:26
 * @license GPL-3.0
 */
#include "search.hpp"
#include "hashtable.hpp"

int search_for_function() {
    std::cout << "-----------------------------\n"
                 "请输入您想要查找的字符串：\n";
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
    std::cout << "-----------------------------\n"
                 "请输入您想要关键词组（例如：38 17）：\n";
    std::vector<int> array;
    int number;
    while (std::cin >> number) {
        array.push_back(number);
        if (std::cin.get() == '\n')break;
    }
    HashTable hashTable;
    hashTable.initHashTable((int) array.size() + 2);
    for (int i: array) {
        hashTable.insert(i);
    }
    hashTable.printHashTable();
    return 0;
}

int main() {
    std::cout << "-----------------------------\n"
                 "1.查找操作\n"
                 "2.构建哈希表操作\n"
                 "请选择您的操作：";
    int option;
    std::cin >> option;
    switch (option) {
        case 1:
            search_for_function();
            break;
        case 2:
            hash_table_for_function();
            break;
        default:
            std::cout << "结束\n";
    }
    return 0;
}