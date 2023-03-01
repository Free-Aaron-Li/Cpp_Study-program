/**
 * @author AaronLi
 * @date 2023-03-01-下午12:29
 * @license GPL-3.0
 */
#include "compare.hpp"

template <typename T>
bool Compare(T &a, T &b) {
    if (a == b) { return true; }
    else { return false; }
}

bool CompareOne(Person<std::string, int> &person_one, Person<std::string, int> &person_two) {
    if (
      person_one.person_name_ == person_two.person_name_
      && person_one.person_age_ == person_two.person_age_) {
        return true;
    }
    else { return false; }
}

void CompareTest() {
    Person<std::string, int> person_one("张三", 12);
    Person                   person_two("李四", 13);
    person_two.Print();
    Person<std::string, int> person_tree("张三", 15);
    int                      a = 13;
    int                      b = 13;

    std::cout << Compare(a, b) << std::endl;
    std::cout << CompareOne(person_one, person_tree) << std::endl;
}