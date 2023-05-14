/**
 * @author AaronLi
 * @data 2023-05-14-下午11:16
 * @license GPL-3.0
 */

#include "hashtable.hpp"

int HashTable::hash(int key) {
    return key % P
}

void HashTable::initHashTable(int size) {
    _hash_table_size = size;
    _hash_table.reserve(size);
    for (int i = 0; i < size; ++i) {
        _hash_table.push_back(NULL_NUMBER);
    }
}

int HashTable::insert(int key) {
    /* 若对应盒子为空 */
    if (_hash_table[hash(key)] == NULL_NUMBER) {
        _hash_table[hash(key)] = key;
        return OK;
    } else {
        if (!linear_probe(key)) {
            std::cout << "散列表已满！";
        }
    }

    return ERROR;
}

int HashTable::linear_probe(int key) {
    int next_index, count = 0;
    /** H<sub>i</sub>=(H(key)+d<sub>i</sub>%m i=1,2,...,k(k\<=m-1) */
    for (int i = 1; i < _hash_table_size; ++i) {
        next_index = ((key % count) + i) % _hash_table_size;
        if (_hash_table[next_index] == NULL_NUMBER) {
            _hash_table[next_index] = key;
            return OK;
        }
        count++;
        /* 散列表已满 */
        if (count == _hash_table.size())return ERROR;
    }
    return OK;
}

int HashTable::printHashTable() {
    if (_hash_table.empty()) {
        std::cout << "散列表为空！";
        return ERROR;
    }
    for (int i = 0; i < _hash_table_size; ++i) {
        std::cout << _hash_table[i] << " ";
    }
    return OK;
}
