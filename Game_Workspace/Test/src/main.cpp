/**
 * @author AaronLi
 * @date 2023-02-19-下午11:16
 * @license GPL-3.0
 */

#include <conio.h>
#include "graphics.h"

int main(){
    initgraph(600,600);
    fillcircle(300,300,100);
    _getch();
    closegraph();
    return 0;
}
