/**
 * @author AaronLi
 * @data 2023-05-14-下午11:00
 * @license GPL-3.0
 */

#ifndef CLASSWORK_HASHTABLE_HPP
#define CLASSWORK_HASHTABLE_HPP

#include <iostream>
#include <vector>

/* p */
#define P 13;
/* 不存在值 */
#define NULL_NUMBER (-2147)
/* 状态值 */
#define ERROR 0
/* 状态值 */
#define OK 1

/* 散列表 */
class HashTable {
public:
    /* 散列表 */
    std::vector<int> _hash_table;
    /* 散列表空间大小 */
    int _hash_table_size{};
public:
    static int hash(int key);

    void initHashTable(int size);

    int insert(int key);

    int linear_probe(int key);
    int printHashTable();
};


#endif //CLASSWORK_HASHTABLE_HPP
