/**
 * @author AaronLi
 * @date 2023-03-06-下午8:56
 * @license GPL-3.0
 */
#include "test.hpp"
#include <stdio.h>

void test(){
    char a[3][3]={1,2,3,4,5,6,7,8,9};
    char b[3][3]={7,8,9,1,1,2,3,4,5};
    char c[3][3];
    for (int i = 0; i <=2; ++i) {
        for (int j = 0; j <= 2; ++j) {
            c[i][j]=0;
            for (int k = 0; k <= 2; ++k) {
                c[i][j]+=a[i][k]*b[k][j];
            }
        }
    }

    for (int i = 0; i <= 2; ++i) {
        for (int j = 0; j <= 3; ++j) {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
}