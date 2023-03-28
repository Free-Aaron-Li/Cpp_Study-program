/**
 * @author AaronLi
 * @date 2023-03-27-下午7:42
 * @license GPL-3.0
 */
#include "sequenceList.hpp"

void test_sequenceList() {
    SqList sqList;
    InitList(&sqList);
    ListInsert(&sqList, 7, 23);
    SearchIndex(&sqList, 23);
    ListDelete(&sqList, 7);
}

int main() {
    test_sequenceList();
    return 0;
}
