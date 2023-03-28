/**
 * @author AaronLi
 * @date 2023-03-27-下午7:59
 * @license GPL-3.0
 */
#include "sequenceList.hpp"

void InitList(SqList* sqList) {
    char choose = ' ';
    std::cout << "是否自定义数组？(y/n) ";
    std::cin >> choose;
    if (choose == 'y' || choose == 'Y') {
        std::cout << "输入递减数组：" << std::endl;
        int i      = 0;
        int number = 0;
        while (std::cin >> number) {
            sqList->data[i++] = number;
            if (std::cin.get() == '\n') break;
        }
        sqList->length = i;
    } else {
        std::cout << "创建递减数组（10~0）：" << std::endl;
        for (int i = 0; i <= 10; ++i) { sqList->data[i] = 10 - i; }
        sqList->length = 11;
        for (int i = 0; i < sqList->length; i++) { std::cout << sqList->data[i] << " "; }
        std::cout << std::endl;
    }
}

Status ListInsert(SqList* sqList, int subscript, ElemType element) {
    if (sqList->length == SPACE_INITIAL_SIZE) { /* 顺序表已满 */
        std::cerr << "顺序表已满！" << std::endl;
        return ERROR;
    }
    if (subscript < 1 || subscript > sqList->length + 1) { /* 查找数据未在表内 */
        std::cerr << "插入数据地址过大或过小" << std::endl;
        return ERROR;
    }

    int index;
    if (subscript <= sqList->length) {
        for (index = sqList->length - 1; index >= subscript - 1; index--) {
            sqList->data[index + 1] = sqList->data[index]; /*将插入位置及之后的元素后移一位*/
        }
    }
    sqList->data[subscript - 1] = element; /*将新元素插入*/
    sqList->length++;                      /*表长加1*/

    SortDescending(sqList);
    Output(sqList);
    return OK;
}

void SortDescending(SqList* sqList){
    int temporary;
    for (int i = 0; i < sqList->length-1; ++i) {
        for (int j = 0; j < sqList->length-1; ++j) {
            if (sqList->data[j+1]>sqList->data[j]){
                temporary= sqList->data[j+1];
                sqList->data[j+1]= sqList->data[j];
                sqList->data[j]=temporary;                
            }
        }
    }
}

Status SearchIndex(SqList* sqList, ElemType element) {
    for (int i = 0; i < sqList->length; ++i) {
        if (element == sqList->data[i]) {
            std::cout << "成功找到元素" << element << "所处位置：" << i + 1 << std::endl;
            return OK;
        }
    }
    std::cerr << "查找元素" << element << "不存在！" << std::endl;
    return ERROR;
}

Status ListDelete(SqList* sqList, int subscript) {
    if (subscript - 1 < 0 || subscript > sqList->length) {
        std::cerr << "删除元素地址过大或过小" << std::endl;
        return ERROR;
    }

    for (int j = subscript - 1; j < sqList->length; j++) { sqList->data[j] = sqList->data[j+1]; }
    sqList->length--;

    Output(sqList);
    return OK;
}

void Output(SqList* sqList) {
    std::cout << "当前顺序表的长度为：" << sqList->length << " 数组为：" << std::endl;
    for (int i = 0; i < sqList->length; ++i) { std::cout << sqList->data[i] << " "; }
    std::cout << std::endl;
}