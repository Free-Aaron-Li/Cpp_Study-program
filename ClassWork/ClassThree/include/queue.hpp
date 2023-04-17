//
// Created by AaronLi on 23-4-16.
//

#ifndef CLASSWORK_QUEUE_HPP
#define CLASSWORK_QUEUE_HPP

/**
 * @title
 * <p> 顺序队列 </P>
 */
#include <iostream>

typedef int ElemType;

/** 默认内置类型 */
typedef int ElemType;
/** 状态值 */
typedef int Status;

/** 定义队列中元素的最大个数 */
#define MAXSIZE 20
/** 成功状态值 */
#define OK (1)
/** 错误状态值 */
#define ERROR 0


/**
 * @title
 * <p> 队列 </P>
 * @param
 *  data    {ElemType*}  队列空间
 * @param
 *  rear    {ElemType}  队尾
 * @param
 *  front   {ElemType}  队首
 */
 
struct Queue{
    /** 队列存储空间基地址 */
    ElemType *data;             
    /** 队列队尾 */
    ElemType rear;             
    /** 队列队首 */
    ElemType front;             
};


/**
 * @title
 * <p> 顺序队列 </P>
 */
 
class SequentialQueue{
public:
    
    /**
     * @title
     * <p> 初始化 </P>
     * @param
     *  queue   {Queue}   队列对象
     * @return
     *  void 
     */
     
    static void InitQueue(Queue *queue);
    
    /**
     * @title
     * <p> 判断队空 </P>
     * @param
     *  queue   {Queue}   队列对象
     * @return
     *  Status  {int}   状态值 
     */
     
    static Status QueueIsEmpty(Queue *queue);
    
    /**
     * @title
     * <p> 判断队满 </P>
     * @param
     *  queue   {Queue}     队列对象
     * @return
     *  Status  {int}   状态值
     */
     
    static Status QueueIsFull(Queue *queue);
    
    /**
     * @title
     * <p> 入队 </P>
     * @param
     *  queue   {Queue} 队列对象
     * @param
     *  value   {ElemType}  入队元素
     * @return
     *  value   {int}   状态值
     */
     
    static Status EnQueue(Queue &queue,ElemType &value);
    
    /**
     * @title
     * <p> 出队 </P>
     * @param
     *  queue   {Queue} 队列对象
     * @param
     *  value   {ElemType}  出队元素
     * @return
     *  Status  {int}   状态值
     */
     
    static Status DeQueue(Queue &queue,ElemType &value);
    
    /**
     * @title
     * <p> 打印队列元素 </P>
     * @param
     *  queue   {Queue} 队列对象
     * @return
     *  void 
     */
     
    static void PrintQueue(Queue &queue);
    
    /**
     * @title
     * <p> 获取队头元素 </P>
     * @param
     * queue    {Queue} 队列对象
     */
     
    static ElemType GetQueueHeader(Queue &queue);
};
#endif //CLASSWORK_QUEUE_HPP
