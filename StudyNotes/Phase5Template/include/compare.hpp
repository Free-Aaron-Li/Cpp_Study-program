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
    void Print() {
        std::cout << "Person Name: " << this->person_name_ << "\tPerson Age: " << this->person_age_
                  << std::endl;
    }
};

template <typename T>
bool Compare(T &a, T &b);

bool CompareOne(Person<std::string, int> &a, Person<std::string, int> &b);

void CompareTest();

#endif  // PHASE5_COMPARE_HPP
