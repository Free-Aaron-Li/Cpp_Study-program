/**
 * @file Print.cpp
 * @author AaronLi
 * @date 2023-02-03-下午4:53
 * @description
 */

#include "sort.hpp"

void Print(int arr[3][3],int lengh){
    for(int i=0;i<lengh;i++){
        for(int j=0;j<3;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}