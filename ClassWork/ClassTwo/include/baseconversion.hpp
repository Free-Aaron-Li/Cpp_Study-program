//
// Created by AaronLi on 23-4-16.
//

#ifndef CLASSWORK_BASECONVERSION_HPP
#define CLASSWORK_BASECONVERSION_HPP

/**
 * @title
 * <p> 题一 </P>
 * @description
 *  利用栈的基本操作实现将任意一个十进制整数转化为 R（2-16）进制的整数。
 */

#include "stack.hpp"

/**
 * @title
 * <p> 进制转换 </P>
 * @description
 *  十进制转换为二进制和十六进制
 */

class BaseConversion {
public:

    /**
     * @title
     * <p> 初始化栈 </P>
     * @return
     * Stack {Stack}
     */

    static Stack InitBaseConversion();

/**
 * @title
 * <p> 二进制转换 </P>
 * @param
 *  stack   {Stack} 栈对象
 * @param
 *  value   {ElemType}  待转换值
 * @return
 *  Status  {int}   状态值
 */

    static Status BinaryConversion(Stack &stack, ElemType &value);


/**
 * @title
 * <p> 十六进制转换 </P>
 * @param
 *  stack   {Stack} 栈对象
 * @param
 *  value   {ElemType}  待转换值
 * @return
 *  Status  {int}   状态值
 */

    static Status HexadecimalConversion(Stack &stack, ElemType &value);

    /**
     * @title
     * <p> 打印转换值 </P>
     * @param
     * stack    {Stack} 栈对象
     */

    static void PrintConversionValue(Stack &stack);
};

#endif //CLASSWORK_BASECONVERSION_HPP
