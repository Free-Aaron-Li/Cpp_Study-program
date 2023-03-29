//
// Created by AaronLi on 23-3-28.
//

#ifndef CLASSWORK_SINGLELINKEDLIST_HPP
#define CLASSWORK_SINGLELINKEDLIST_HPP

/**
 * @description
 * <p> 单链表操作 </P>
 */

#define OK    0
#define ERROR (-1)
typedef int ElemType; /* ElemType的类型，默认为int */
typedef int Status;   /* 顺序表状态，1正确 0错误 */

#include <iostream>

class Node {
 public:
    ElemType data;  // 存放char类型元素
    Node*    next;  // 指向下一个结点域
};

class LinkList {
 private:
    Node* head;   /* 单链表头结点指针 */
    int   length; /* 单链表长度 */

 public:
    /**
     * @description
     * <p> 初始化 </P>
     */
    LinkList();
    /**
     * @description
     * <p> 销毁链表 </P>
     */
    ~LinkList();
    /**
     * @description
     * <p> 创建链表 </P>
     * @def
     * 尾插法
     */
    void   CreateLinkList();
    /**
     * @description
     * <p> 遍历链表 </P>
     */
    void   TraversalLinkList(Node* node);
    /**
     * @description
     * <p> 删除节点——按照节点索引 </P>
     * @param
     *  index 删除的位置
     */
    Status DeleteNode_Index(int index);
    /**
     * @description
     * <p> 删除节点——按照节点值 </P>
     * @param
     *  value 节点值
     */
    Status DeleteNode_Value(ElemType value);
    /**
     * @description
     * <p> 插入节点 </P>
     * @param
     *  index 插入位置
     * @param
     *  value 插入值
     */
    Status InsertNode_Index(int index, ElemType value);
    /**
     * @description
     * <p> 链表长度 </P>
     */
    Status ListLength() const;
    /**
     * @description
     * <p> 查找节点值 </P>
     * @param
     *  value 查找值
     */
    Status GetElement_Value(ElemType value);
};

#endif  // CLASSWORK_SINGLELINKEDLIST_HPP
