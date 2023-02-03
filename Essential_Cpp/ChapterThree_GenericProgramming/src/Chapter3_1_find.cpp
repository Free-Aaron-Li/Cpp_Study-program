/**
 * @file Chapter1_1_find.cpp
 * @author AaronLi
 * @date
 * 2023-01-25-下午4:44
 * @description
 * <p> test <p>
 * @link
 */
#include <iostream>
using namespace std;

void swap(int a,int b);

int main() {
  int a=10;
  int b=20;
  swap(a,b);
  return 0;
}

void swap(int a,int b) {
  int temp = a;
  a = b;
  b = temp;
  cout<<"a: "<<a<<endl;
  cout<<"b: "<<b<<endl;
}





