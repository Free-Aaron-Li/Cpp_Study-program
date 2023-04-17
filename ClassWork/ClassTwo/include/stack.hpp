//
// Created by AaronLi on 23-4-16.
//

#ifndef CLASSWORK_STACK_HPP
#define CLASSWORK_STACK_HPP

/**
 * @title
 * <p> 顺序栈 </P>
 */

#include "iostream"

typedef int ElemType;

/** 默认内置类型 */
typedef int ElemType;
/** 状态值 */
typedef int Status;

/** 定义栈中元素的最大个数 */
#define MAXSIZE 20      
/** 成功状态值 */
#define OK (1)           
/** 错误状态值 */
#define ERROR 0      

/**
 * @title
 * <p> 栈 </P>
 * @param
 *  data    {ElemType[]}    栈空间
 * @param
 *  top     {int}   栈顶
 */
 
struct Stack {
    /** 存放栈中元素 */
    ElemType data[MAXSIZE];
    /** 栈顶 */
    int top;                     
};

/**
 * @title
 * <p> 顺序栈 </P>
 * @param
 *  ElemType 
 */

class SequentialStack {
public:

    /**
     * @title
     * <p> 初始化栈 </P>
     * @param
     *  stack   {Stack}    栈名 
     */

    static void InitStack(Stack *stack) {
        stack->top = -1;
    };

    /**
     * @title
     * <p> 判断栈空 </P>
     * @param
     *  stack   {Stack}    栈名
     * @return
     *  Status  {int}   状态值
     */

    static Status StackIsEmpty(Stack *stack);
    
    /**
     * @title
     * <p> 判断栈满 </P>
     * @param
     *  stack  {Stack}    栈名
     * @return
     *  Status  {int}   状态值
     */
     
    static Status  StackIsFull(Stack *stack);
    
    /**
     * @title
     * <p> 入栈 </P>
     * @param
     *  stack   {Stack}    栈名
     * @param
     *  value   {ElemType}  元素值
     * @return
     *  Status  {int}   状态值
     */
     
    static Status Push(Stack *stack, ElemType &value);
    
    /**
     * @title
     * <p> 出栈 </P>
     * @param
     *  stack   {Stack}    栈名
     * @param
     *  value   {ElemType}  元素值
     * @return
     *  Status  {int}   状态值
     */
     
     static Status  Pop(Stack *stack, ElemType &value);
    
     /**
      * @title
      * <p> 读取栈顶元素 </P>
      * @param
      *  stack   {Stack}    栈名
      * @param
      *  value   {ElemType}  元素值
      * @return
      *  Status  {int}   状态值
      */
      
     static Status GetTop(Stack *stack, ElemType &value);
     
     /**
      * @title
      * <p> 打印栈元素 </P>
      * @param
      *  stack   {Stack}    栈名
      * @return
      *  void 
      */
      
     static void PrintStack(Stack *stack);
};

#endif //CLASSWORK_STACK_HPP
