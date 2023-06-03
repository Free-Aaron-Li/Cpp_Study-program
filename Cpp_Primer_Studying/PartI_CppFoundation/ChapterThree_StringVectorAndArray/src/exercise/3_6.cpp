/**
 * @author AaronLi
 * @data 2023-06-03-下午6:44
 * @license GPL-3.0
 */
#include "3_6.hpp"

void Exercise_3_6::exercise_3_43() {
    int array[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};

    std::cout << "版本1：\n";
    for (const int(&row)[4] : array) {
        for (int column : row) { std::cout << column << "\t"; }
        std::cout << "\n";
    }

    std::cout << "版本2：\n";
    for (int i = 0; i < sizeof(array) / sizeof(array[0]); ++i) {
        for (int j = 0; j < sizeof(array[0]) / sizeof(array[0][0]); ++j) { std::cout << array[i][j] << "\t"; }
        std::cout << "\n";
    }

    std::cout << "版本3：\n";
    for (int(*i)[4] = array; i != array + 3; ++i) {
        for (int *j = *i; j != *i + 4; ++j) { std::cout << *j << "\t"; }
        std::cout << "\n";
    }
}

void Exercise_3_6::exercise_3_44() {
    int array[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    using int_array = int[4];

    std::cout << "版本1：\n";
    for (const int_array &row : array) {
        for (int column : row) { std::cout << column << "\t"; }
        std::cout << "\n";
    }

    std::cout << "版本2：\n";
    for (int i = 0; i < sizeof(array) / sizeof(array[0]); ++i) {
        for (int j = 0; j < sizeof(array[0]) / sizeof(array[0][0]); ++j) { std::cout << array[i][j] << "\t"; }
        std::cout << "\n";
    }

    std::cout << "版本3：\n";
    for (int_array *i = array; i != array + 3; ++i) {
        for (int *j = *i; j != *i + 4; ++j) { std::cout << *j << "\t"; }
        std::cout << "\n";
    }
}

void Exercise_3_6::exercise_3_45() {
    int array[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    using int_array = int[4];

    std::cout << "版本1：\n";
    for (auto &row : array) {
        for (auto column : row) { std::cout << column << "\t"; }
        std::cout << "\n";
    }

    std::cout << "版本2：\n";
    for (auto i = 0; i < sizeof(array) / sizeof(array[0]); ++i) {
        for (auto j = 0; j < sizeof(array[0]) / sizeof(array[0][0]); ++j) { std::cout << array[i][j] << "\t"; }
        std::cout << "\n";
    }

    std::cout << "版本3：\n";
    for (auto i = array; i != array + 3; ++i) {
        for (auto j = *i; j != *i + 4; ++j) { std::cout << *j << "\t"; }
        std::cout << "\n";
    }
}
