//
// Created by AaronLi on 23-4-10.
//

#ifndef CLASSWORK_STACK_AND_QUEUE_HPP
#define CLASSWORK_STACK_AND_QUEUE_HPP

#include <iostream>

typedef int ElemType;   /* 默认内置类型 */
typedef int Status;     /* 状态值 */

#define MAXSIZE 20      /* 定义栈中元素的最大个数 */
#define OK 0            /* 成功状态值 */
#define ERROR (-1)      /* 错误状态值 */

/* 栈的结构类型 */
typedef struct {
    ElemType data[MAXSIZE];      /* 存放栈中元素 */
    int top;                     /* 栈顶指针 */
} SqStack;

class Exercise_SqStack {
public:
    /**
     * @title
     * <p> 初始化栈 </P>
     * @param 
     *  sqStack 栈名
     */

    static void InitStack(SqStack &sqStack);

    /**
     * @title
     * <p> 判断栈空 </P>
     * @param
     *   sqStack 栈名
     */

    static bool IsEmpty(SqStack sqStack);

    /**
     * @title
     * <p> 进栈 </P>
     * @param
     *  sqStack 栈名
     * @param
     *  elemType 进栈元素值
     */

    static bool Push(SqStack &sqStack, ElemType &elemType);

    /**
     * @title
     * <p> 出栈 </P>
     * @param
     *  sqStack 栈名
     * @param
     *  elemType 出栈元素值
     */

    static ElemType Pop(SqStack &sqStack, ElemType &elemType);

    /**
     * @title
     * <p> 读取栈顶元素 </P>
     * @param
     *  sqStack 栈名
     * @param
     *  elemType 栈顶元素值
     */

    static bool GetTop(SqStack sqStack, ElemType &elemType);

    /**
     * @title
     * <p> 打印栈元素 </P>
     * @param
     *  sqStack 栈名
     */

    static void PrintStack(SqStack sqStack);
};
#endif //CLASSWORK_STACK_AND_QUEUE_HPP
