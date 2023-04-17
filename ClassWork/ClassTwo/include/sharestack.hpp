//
// Created by AaronLi on 23-4-16.
//

#ifndef CLASSWORK_SHARESTACK_HPP
#define CLASSWORK_SHARESTACK_HPP

/**
 * @title
 * <p> 题二 </P>
 * @description
 *  设有两个栈 s1,s2 都采用顺序栈方式，并共享一个存储区[0,..,maxsize-1]，为了尽量
利用空间，减少溢出的可能，可采用栈顶相向，迎面增长的存储方式。试设计 s1,s2 有关入栈和
出栈的操作算法。
 */

#include "stack.hpp"

/**
 * @title
 * <p> 共享栈 </P>
 */

class ShareStack {
public:
    /** 栈1顶部 */
    int top_1 = -1;
    /** 栈2顶部 */
    int top_2 = MAXSIZE;
public:

    /**
     * @title
     * <p> 初始化 </P>
     * @param
     *  stack   {Stack} 栈对象
     * @return
     *  void 
     */

    static void InitShareStack(Stack &stack);

    /**
     * @title
     * <p> 栈满 </P>
     * @param
     *  stack   {Stack} 栈对象
     * @return
     *  Status  {int}   状态值
     */

    Status ShareStackIsFull(Stack &stack) const;

    /**
     * @title
     * <p> 入栈1 </P>
     * @param
     *  stack   {Stack} 栈对象
     * @param
     *  value   {ElemType}  入栈元素
     * @return
     *  Status  {int}   状态值
     */

    Status PushOneStack(Stack &stack, ElemType &value);

    /**
     * @title
     * <p> 入栈2 </P>
     * @param
     *  stack   {Stack} 栈对象
     * @param
     *  value   {ElemType}  入栈元素
     * @return
     *  Status  {int}   状态值
     */

    Status PushTwoStack(Stack &stack, ElemType &value);

    /**
     * @title
     *  <p> 出栈1 </p>
     * @param
     *  stack   {Stack} 栈对象
     * @param
     *  value   {ElemType}  入栈元素
     * @return
     *  Status  {int}   状态值
     */

    Status PopOneStack(Stack &stack, ElemType &value);

    /**
     * @title
     *  <p> 出栈1 </p>
     * @param
     *  stack   {Stack} 栈对象
     * @param
     *  value   {ElemType}  入栈元素
     * @return
     *  Status  {int}   状态值
     */

    Status PopTwoStack(Stack &stack, ElemType &value);
    
    /**
     * @title
     * <p> 打印栈 </P>
     * @param
     *  stack   {Stack} 栈对象
     * @return
     *  void 
     */
     
    static void PrintShareStack(Stack &stack);
    
};

#endif //CLASSWORK_SHARESTACK_HPP
