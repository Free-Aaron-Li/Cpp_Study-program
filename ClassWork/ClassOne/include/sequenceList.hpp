//
// Created by AaronLi on 23-3-27.
//

#ifndef CLASSWORK_SEQUENCELIST_HPP
#define CLASSWORK_SEQUENCELIST_HPP

/**
 * @description
 * <p> 顺序表操作 </P>
 */

#define OK                 0
#define ERROR              (-1)
#define SPACE_INITIAL_SIZE 20 /* 存储空间初始化分配大小 */
typedef int ElemType;         /* ElemType的类型，默认为int */
typedef int Status;           /* 顺序表状态，1正确 0错误 */

#include <iostream>
#include <vector>

typedef struct {
    ElemType data[SPACE_INITIAL_SIZE]; /* 数组存储数据元素 */
    ElemType length;                   /*线性表当前长度*/
} SqList;

class SequenceList{
 public:    
/**
 * @description
 * <p> 初始化 </P>
 * @param
 *  sqList 顺序表
 */

static void InitList(SqList* sqList);

/**
 * @description
 * <p> 插入 </P>
 * @param
 *  sqList 顺序表
 * @param
 *  subscript 插入数组位置下标
 * @param
 *  element 插入元素
 */

static Status ListInsert(SqList* sqList, int subscript, ElemType element);

/**
 * @description 
 * <p> 降序 </P>
 * @param
 *  sqList 顺序表
 */

static void SortDescending(SqList* sqList);

/**
 * @description
 * <p> 查找 </P>
 * @param
 *  sqList 顺序表
 * @param
 *  element 查找元素
 */

static Status SearchIndex(SqList* sqList, ElemType element);

/**
 * @description
 * <p> 删除 </P>
 * @param
 *  sqList 顺序表
 * @param
 *  subscript 删除位置下标
 */

static Status ListDelete(SqList* sqList, int subscript);

/**
 * @description
 * <p> 遍历输出 </P>
 * @param
 *  sqList 顺序表
 */

static void Output(SqList* sqList);

};
#endif  // CLASSWORK_SEQUENCELIST_HPP
