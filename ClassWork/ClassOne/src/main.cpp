/**
 * @author AaronLi
 * @date 2023-03-27-下午7:42
 * @license GPL-3.0
 */
#include "List.hpp"
#include "sequenceList.hpp"
#include "singleLinkedList.hpp"

void test_sequenceList() {
    std::cout << "***************************" << std::endl;
    std::cout << "测试顺序表：" << std::endl;
    std::cout << "***************************" << std::endl;
    SqList sqList;
    /* 初始化顺序表 */
    SequenceList::InitList(&sqList);
    /* 插入元素 */
    SequenceList::ListInsert(&sqList, 7, 23);
    /* 查找元素 */
    SequenceList::SearchIndex(&sqList, 23);
    /* 删除元素 */
    SequenceList::ListDelete(&sqList, 7);
    std::cout << "****************************" << std::endl;
}

void test_singleLinkedList() {
    std::cout << "***************************" << std::endl;
    std::cout << "测试单链表：" << std::endl;
    std::cout << "***************************" << std::endl;
    LinkList linkList;
    linkList.CreateLinkList();
    linkList.DeleteNode_Index(3);
    linkList.DeleteNode_Value(11);
    linkList.InsertNode_Index(3, 22);
    linkList.GetElement_Value(13);
    std::cout << "***************************" << std::endl;
}

void test_SeqList() {
    std::cout << "***************************" << std::endl;
    std::cout << "测试线性表之顺序表：" << std::endl;
    std::cout << "***************************" << std::endl;
    SeqList seqList_a, seqList_b, seqList;
    std::cout << "seqList_a: " << std::endl;
    List::CreatSeqList(seqList_a);
    std::cout << "seqList_b: " << std::endl;
    List::CreatSeqList(seqList_b);
    List::MergeList_SeqList(seqList_a, seqList_b, seqList);
    std::cout << "***************************" << std::endl;
}

void test_LinkedList() {
    std::cout << "***************************" << std::endl;
    std::cout << "测试线性表之单链表：" << std::endl;
    std::cout << "***************************" << std::endl;
    Node_List node_list1{}, node_list2{};
    List      list{};
    list.InitiateLinkedList();
    std::cout << "List_a: " << std::endl;
    list.CreateLinked(node_list1);
    std::cout << "List_b: " << std::endl;
    list.CreateLinked(node_list2);
    list.MergeList_Link(&node_list1, &node_list2);
    std::cout << "***************************" << std::endl;
}

int main() {
    // test_sequenceList();
    // test_singleLinkedList();
    // test_SeqList();
    test_LinkedList();
    return 0;
}
