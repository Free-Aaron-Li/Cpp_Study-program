/**
 * @author AaronLi
 * @data 2023-06-01-下午1:01
 * @license GPL-3.0
 */
#include <iostream>
#include <vector>

void test_add() {
    std::vector<int> vector_1;
    std::vector<int> vector_2;

    for (int i = 0; i < 10; ++i) {
        vector_1.push_back(i);
        vector_2.push_back(i);
    }

    auto iterator_1 = vector_1.begin();
    std::cout << *(iterator_1) << "\n";
    std::cout << *(iterator_1 += 1) << "\n";
    std::cout << *(iterator_1) << "\n";
    auto iterator_2 = iterator_1;
    std::cout << *(iterator_2++) << *(iterator_1) << "\n";
    std::cout << iterator_2 - iterator_1;

    std::cout << "\n-----------------------\n";
    iterator_2 = vector_1.begin();
    std::cout << *(iterator_1 += 1) << " " << *(iterator_2) << "\n";
    std::cout << (iterator_1 > iterator_2) << "\n";
}


void test_iterator_add() {
    std::vector<int> vector_1{1, 2, 3, 4, 5, 6, 7};
    auto iterator_1 = vector_1.begin();
    auto iterator_2 = vector_1.end();
}

int main() {
    test_add();
    return 0;
}