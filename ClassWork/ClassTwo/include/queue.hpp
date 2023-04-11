//
// Created by AaronLi on 23-4-10.
//

#ifndef CLASSWORK_QUEUE_HPP
#define CLASSWORK_QUEUE_HPP

#include <iostream>

typedef int ElemType;   /* 默认内置类型 */
typedef int Status;     /* 状态值 */

#define MAXSIZE 20      /* 定义栈中元素的最大个数 */
#define OK 0            /* 成功状态值 */
#define ERROR (-1)      /* 错误状态值 */

typedef struct {
    ElemType *data;             /* 队列存储空间基地址 */
    ElemType rear;              /* 队列队尾 */
    ElemType front;             /* 队列队首 */
} Queue;

class Exercise_Queue {
public:
    /**
     * @title
     * <p> 初始化 </P>
     * @param
     *  queue 队列对象
     */

    static void InitiateQueue(Queue &queue);

    /**
     * @title
     * <p> 判断队列是否为空 </P>
     * @param
     *  queue 队列对象
     */

    static Status isEmpty(Queue &queue);

    /**
     * @title
     * <p> 判断队列是否已满 </P>
     * @param
     *  queue 队列对象
     */

    static Status isFull(Queue &queue);

    /**
     * @title
     * <p> 入队 </P>
     * @param
     *  queue 队列对象
     * @param
     *  value 入队的值
     */

    static void EnQueue(Queue &queue, ElemType &value);

    /**
     * @title
     * <p> 出队 </P>
     * @param
     *  queue 队列对象
     * @param
     *  value 出队的值
     */

    static ElemType DeQueue(Queue &queue, ElemType &value);

    /**
     * @title
     * <p> 打印队列 </P>
     * @param
     *  queue 队列对象
     */

    static void PrintQueue(Queue &queue);
};
#endif //CLASSWORK_QUEUE_HPP
