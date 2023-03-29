//
// Created by AaronLi on 23-3-28.
//

#ifndef CLASSWORK_LIST_HPP
#define CLASSWORK_LIST_HPP

#define OK                 0    /** {@value} 状态值*/
#define ERROR              (-1) /** {@value} 状态值*/
#define SPACE_INITIAL_SIZE 20   /** {@value}存储空间初始化分配大小 */
typedef int ElemType;           /** ElemType的类型，默认为int */
typedef int Status;             /** 顺序表状态，1正确 0错误 */

#include <iostream>
#include <vector>

/**
 * @description
 * <p> 线性表的应用 </P>
 */

typedef struct {
    ElemType *data;   /* 数组存储数据元素 */
    ElemType  length; /*线性表当前长度*/
} SeqList;

class Node_List {
 public:
    ElemType   data;
    Node_List *next;
};

class List {
 private:
    Node_List *head;
    int        length;

 public:
    /**
     * @description
     * <p> 销毁链表 </P>
     */
    ~List();
    /**
     * @description
     * <p> 创建顺序有序表 </P>
     * @param
     *  seqList 顺序表
     */
    static void    CreatSeqList(SeqList &seqList);
    /**
     * @description
     * <p> 降序排序 </P>
     * @param
     *  seqList 顺序表
     */
    static SeqList Sort_Descending(SeqList &seqList);
    /**
     * @description
     * <p> 合并顺序有序表 </P>
     * @param
     *  seqList1 顺序表1
     * @param
     *  seqList2 顺序表2
     * @param
     *  seqList 合并后的顺序表
     */
    static void    MergeList_SeqList(SeqList &seqList1, SeqList &seqList2, SeqList &seqList);
    /**
     * @description
     * <p> 遍历顺序有序表 </P>
     * @param
     *  seqList 顺序表
     */
    static void    Traverse(SeqList &seqList);
    /**
     * @description
     * <p> 初始化链表 </P>
     */
    void           InitiateLinkedList();
    /**
     * @description
     * <p> 创建新节点 </P>
     * @param
     *  node_list 创建链表名
     */
    void           CreateLinked(Node_List &node_list);
    /**
     *
     * @description
     * <p> 遍历链表 </P>
     * @param
     *  node 遍历链表头
     */
    void           Traverse_Node(Node_List *head);
    /**
     * @description
     * <p> 合并链表 </P>
     * @param
     *  node_list1  链表1
     * @param
     *  node_list2  链表2
     */
    void           MergeList_Link(Node_List *node_list1, Node_List *node_list2);
    /**
     * @description
     * <p> 排序链表 </P>
     * @param
     *  head 降序排序链表头
     */
    void           Sort_Link(Node_List *head);
};
#endif  // CLASSWORK_LIST_HPP
