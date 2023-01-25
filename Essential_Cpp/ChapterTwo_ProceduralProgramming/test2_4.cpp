/**
 * @file test2_4.cpp
 * @author AaronLi
 * @date 2023-01-23-下午11:19
 * @description
 * <p> 练习2.4 </p>
 * <p></p>
 * 写一个函数，以局部静态（local static）的vector存储Pentagonal数列元素。此函数返回一个const指针，指向该vector。如果vector的大小小于指定的元素个数，
 * 就扩充vector的大小。接下来再实现第二个函数，接受一个位置值，返回该位置上的元素。最后，编写main()测试这些函数
 * @link 
 */

#include <iostream>
#include <vector>
using namespace std;

const vector<int>* pentagonal_sequence(int num);
bool calculation_is_ok(int num);
bool pentagonal_element(int num,int &elem);

bool calculation_is_ok(int num) {
    const int max_num=100;
    if (num <= 0 || num > max_num) {
        cerr << "penta_seq(): oops: invalid size: "
             << num << " --cannot fulfill request. "
             << endl;
        return false;
    }
    return true;
}

const vector<int>* pentagonal_sequence(int num){
    if(!calculation_is_ok(num)){
        return nullptr;
    }

    static vector<int> elems;
    for (int i = int(elems.size()); i < num; ++i) {
        elems.push_back((i*(3*i-1))/2);
    }

    return &elems;
}

bool pentagonal_element(int num,int &elem){
    const vector<int>* pseq= pentagonal_sequence(num);

    if(!pseq){
        elem=0;
        return false;
    }
    elem=(*pseq)[num-1];
    return true;
}

int main(){
    int elem=0;
    if ( pentagonal_element( 2, elem ))
        cout << "element 4 is " << elem << '\n';
}
