//
// Created by AaronLi on 23-3-1.
//

#ifndef PHASE5_COMPARE_HPP
#define PHASE5_COMPARE_HPP

#include <iostream>
#include <utility>

template <class PersonName = std::string, class PersonAge = int>
class Person {
 public:
    PersonName person_name_;
    PersonAge  person_age_;

 public:
    Person(PersonName name, PersonAge age) {
        this->person_name_ = std::move(name);
        this->person_age_  = age;
    }
    void showPerson() {
        std::cout << "Person Name: " << this->person_name_ << "\tPerson Age: " << this->person_age_
                  << std::endl;
    }
};

template <typename T>
bool Compare(T &a, T &b);

bool CompareOne(Person<std::string, int> &a, Person<std::string, int> &b);

template <class T>
void printPerson(T &a, T &b);

template <class T1, class T2>
void printPerson2(Person<T1, T2> &person);
void Test01();
void Test02();
void CompareTest();

#endif  // PHASE5_COMPARE_HPP
