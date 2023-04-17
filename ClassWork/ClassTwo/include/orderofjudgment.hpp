//
// Created by AaronLi on 23-4-16.
//

#ifndef CLASSWORK_ORDEROFJUDGMENT_HPP
#define CLASSWORK_ORDEROFJUDGMENT_HPP

/**
 * @title
 * <p> 题目三 </P>
 * @description
 *  使用栈和队列模拟如下操作：1-n 之间的 n 个整数按照由小到大的某种顺序入栈，现给出某种出栈顺序，判断其是否正确，如果正确则输出 YES,否则输出 NO。
 */

#include "stack.hpp"
#include "queue.hpp"

class Judgment {
public:

    /**
     * @title
     * <p> 初始化 </P>
     * @param
     *  queue   {Queue} 队列对象
     * @return
     *  void 
     */

    static void InitJudgment(Queue &queue);

    /**
     * @title
     * <p> 猜测顺序链入队 </P>
     * @param
     *  queue   {Queue} 队列对象
     * @return
     *  Status  {int}   状态值
     */

    int PushQueue(Queue &queue);

    /**
     * @title
     * <p> 判断出栈顺序 </P>
     * @param
     *  queue   {Queue} 队列对象
     * @return
     *  void
     */

    void JudgmentStack(Queue &queue);
};

#endif //CLASSWORK_ORDEROFJUDGMENT_HPP
