/**
 * @author AaronLi
 * @date 2023-03-27-下午7:42
 * @license GPL-3.0
 */
#include "sequenceList.hpp"
#include "singleLinkedList.hpp"

void test_sequenceList() {
    SqList sqList;
    SequenceList::InitList(&sqList);
    SequenceList::ListInsert(&sqList, 7, 23);
    SequenceList::SearchIndex(&sqList, 23);
    SequenceList::ListDelete(&sqList, 7);
}

void test_singleLinkedList() {
    LinkList linkList;
    linkList.CreateLinkList();
    linkList.DeleteNode_Index(3);
    linkList.DeleteNode_Value(11);
    linkList.InsertNode_Index(3, 22);
    linkList.GetElement_Value(13);
}
int main() {
    // test_sequenceList();
    test_singleLinkedList();
    return 0;
}
