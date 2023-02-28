//
// Created by AaronLi on 23-2-27.
//

#ifndef PHASE5_SWAP_HPP
#define PHASE5_SWAP_HPP

#include <iostream>

void SwapInt(int &a,int &b);
void SwapDouble(double &a,double &b);

template<typename T>
void Swap(T &a,T &b);

int Test();

#endif  // PHASE5_SWAP_HPP
