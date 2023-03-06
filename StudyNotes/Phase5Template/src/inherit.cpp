/**
 * @author AaronLi
 * @date 2023-03-01-下午5:52
 * @license GPL-3.0
 */
#include "inherit.hpp"

void InheritTest02() {
    Son2<int> son2;
    std::cout << son2.base_value_;
    std::cout<< typeid(son2).name()<<std::endl;
    son2.showPrint();
}
