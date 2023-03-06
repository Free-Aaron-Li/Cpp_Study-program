//
// Created by AaronLi on 23-3-1.
//

#ifndef PHASE5_INHERIT_HPP
#define PHASE5_INHERIT_HPP

#include <iostream>

template <class T>
class Base {
 public:
    T base_value_ = 12;
};

// 类模板继承类模板 ,可以用T2指定父类中的T类型
template <class T2>
class Son2 : public Base<T2> {
 public:
    void showPrint() {
        std::cout << typeid(T2).name() << std::endl;
    }
};

void InheritTest02();
#endif  // PHASE5_INHERIT_HPP
