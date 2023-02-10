/**
 * @file main.cpp
 * @author AaronLi
 * @date 2023-02-03-下午12:22
 * @description
 */

#include<graphics.h>
#include<conio.h>

int main()
{

    initgraph(666, 666);		//初始化为666*666的画布
    /*				circle				*/
    setcolor(YELLOW);			//circle的线条为黄色
    setfillcolor(RED);			//circle内红色填充
    setbkcolor(GREEN);
    fillcircle(300, 300, 60);	//circle center为（100，100）半径20


    getch();					//按任意键继续
    closegraph();				//关闭图形界面
    return 0;
}

