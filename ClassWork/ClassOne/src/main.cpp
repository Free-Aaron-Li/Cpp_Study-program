/**
 * @author AaronLi
 * @date 2023-03-27-下午7:42
 * @license GPL-3.0
 */
#include "List.hpp"
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

void test_SeqList() {
    SeqList seqList_a, seqList_b, seqList;
    std::cout << "seqList_a: " << std::endl;
    List::CreatSeqList(seqList_a);
    std::cout << "seqList_b: " << std::endl;
    List::CreatSeqList(seqList_b);
    List::MergeList_SeqList(seqList_a, seqList_b, seqList);
    std::cout << "***************************" << std::endl;
}

void test_LinkedList() {
    Node_List node_list1{}, node_list2{};
    List      list{};
    list.InitiateLinkedList();
    list.CreateLinked(node_list1);
    list.CreateLinked(node_list2);
    list.MergeList_Link(&node_list1, &node_list2);
}

int main() {
    // test_sequenceList();
    // test_singleLinkedList();
    // test_SeqList();
    test_LinkedList();
    return 0;
}
