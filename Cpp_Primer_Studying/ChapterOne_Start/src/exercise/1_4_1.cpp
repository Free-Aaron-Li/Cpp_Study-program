/**
 * @author AaronLi
 * @date 2023-04-01-下午10:57
 * @license GPL-3.0
 */
#include "1_4.hpp"

void Exercise_1_4::SumFiftyToHundred() {
    ElemType value_1 = 50;
    ElemType result = 0;

    while (value_1 <= 100) {
        result += value_1;
        value_1++;
    }
    std::cout << "Sum 50 to 100 is: " << result << std::endl;
}

void Exercise_1_4::Decline() {
    ElemType value = 10;

    std::cout << "递减序列为：" << std::endl;
    while (value >= 0) {
        std::cout << value << std::endl;
        value--;
    }
}

void Exercise_1_4::Integer() {
    ElemType value_1=0;
    ElemType value_2=0;
    
    std::cout<<"请输入两个整数：";
    std::cin>>value_1;
    std::cin>>value_2;
    
    std::cout<<"两个整数之间的值为："<<std::endl;
    if (value_1<=value_2){
        while (value_1<=value_2){
            std::cout<<value_1<<" ";
            value_1++;
        }
    } else{
        while (value_2<=value_1){
            std::cout<<value_2<<" ";
            value_2++;
        }
    }
}
