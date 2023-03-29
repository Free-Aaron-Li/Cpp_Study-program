/**
 * @author AaronLi
 * @date 2023-03-28-下午10:13
 * @license GPL-3.0
 */
#include "List.hpp"

void List::CreatSeqList(SeqList &seqList) {
    seqList.data = new ElemType[SPACE_INITIAL_SIZE];
    std::cout << "请输入顺序表的值：（默认大小为20）" << std::endl;
    ElemType value;
    int      i = 0;
    while (std::cin >> value) {
        seqList.data[i++] = value;
        if (std::cin.get() == '\n') break;
    }
    seqList.length = i;
    if (seqList.length > SPACE_INITIAL_SIZE) {
        std::cerr << "顺序表的容量过大，请重新输入！";
        return;
    }

    Traverse(seqList);
}

SeqList List::Sort_Descending(SeqList &seqList) {
    ElemType temporary_value;
    for (int i = 0; i < seqList.length - 1; ++i) {
        for (int j = 0; j < seqList.length - 1; ++j) {
            if (seqList.data[j] < seqList.data[j + 1]) {
                temporary_value     = seqList.data[j + 1];
                seqList.data[j + 1] = seqList.data[j];
                seqList.data[j]     = temporary_value;
            }
        }
    }
    return seqList;
}

void List::MergeList_SeqList(SeqList &seqList1, SeqList &seqList2, SeqList &seqList) {
    seqList.length = seqList1.length + seqList2.length;
    seqList.data   = new ElemType[seqList.length];

    ElemType *first_pointer         = seqList.data;
    ElemType *seqList1_pointer      = seqList1.data;
    ElemType *seqList2_pointer      = seqList2.data;
    ElemType *seqList1_pointer_last = seqList1.data + seqList1.length - 1;
    ElemType *seqList2_pointer_last = seqList2.data + seqList2.length - 1;

    while (seqList1_pointer <= seqList1_pointer_last && seqList2_pointer <= seqList2_pointer_last) {
        if (*seqList1_pointer <= *seqList2_pointer) {
            *first_pointer++ = *seqList1_pointer++;
        } else {
            *first_pointer++ = *seqList2_pointer++;
        }
    }
    while (seqList1_pointer <= seqList1_pointer_last) *first_pointer++ = *seqList1_pointer++;
    while (seqList2_pointer <= seqList2_pointer_last) *first_pointer++ = *seqList2_pointer++;

    Traverse(seqList);
}

void List::Traverse(SeqList &seqList) {
    seqList = Sort_Descending(seqList);
    for (int i = 0; i < seqList.length; i++) { std::cout << seqList.data[i] << " "; }
    std::cout << std::endl;
}