/**
 * @author AaronLi
 * @date 2023-03-28-下午7:38
 * @license GPL-3.0
 */
#include "singleLinkedList.hpp"

LinkList::LinkList() {
    head       = new Node();
    head->next = nullptr; /* 头结点无后继节点 */
    length     = 0;
}

LinkList::~LinkList() {
    Node *first_node, *next_node;
    first_node = head;
    next_node  = first_node->next;
    while (next_node != nullptr) {
        delete first_node;
        first_node = next_node;
        next_node  = next_node->next;
    }
    delete first_node;
}

void LinkList::CreateLinkList() {
    Node *node, *right_node;
    right_node = head;
    std::cout << "请输入链表的节点值：";
    ElemType value;
    while (std::cin >> value) {
        node             = new Node();
        node->data       = value;
        right_node->next = node;
        right_node       = node;
        length++;
        if (std::cin.get() == '\n') break;
    }
    right_node->next = nullptr;

    std::cout << "当前链表的数据：" << std::endl;
    TraversalLinkList(head->next);
    std::cout << std::endl;
    ListLength();
}

void LinkList::TraversalLinkList(Node *node) {
    if (node) {
        std::cout << node->data << " ";
        TraversalLinkList(node->next);
    }
}

Status LinkList::DeleteNode_Index(int index) {
    if (index < 0 || index > length) {
        std::cerr << "删除失败，索引越界" << std::endl;
        return ERROR;
    }

    Node *next_node   = head, *temporary_node;
    int   node_number = 0;
    while ((next_node->next) && node_number < index - 1) {
        next_node = next_node->next;
        node_number++;
    }

    std::cout << "成功删除索引为" << index << "的节点元素" << next_node->next->data << std::endl;
    temporary_node  = next_node->next;
    next_node->next = temporary_node->next;
    delete temporary_node;

    std::cout << "当前链表的数据：" << std::endl;
    TraversalLinkList(head->next);
    std::cout << std::endl;
    return OK;
}

Status LinkList::DeleteNode_Value(ElemType value) {
    Node *next_node   = head, *temporary_node;
    int   node_number = 0;
    while (next_node->next->data != value) {
        next_node = next_node->next;
        node_number++;

        if (next_node->next == nullptr) {
            std::cerr << "删除失败，没有找到要删除的节点" << std::endl;
            return ERROR;
        }
    }
    std::cout << "成功删除节点元素为" << value << "的元素，其索引值为" << node_number + 1
              << std::endl;
    temporary_node  = next_node->next;
    next_node->next = temporary_node->next;
    delete temporary_node;

    std::cout << "当前链表的数据：" << std::endl;
    TraversalLinkList(head->next);
    std::cout << std::endl;
    return OK;
}

Status LinkList::InsertNode_Index(int index, ElemType value) {
    if (index < 0 || index > length) {
        std::cerr << "插入失败，索引越界" << std::endl;
        return ERROR;
    }

    Node *next_node   = head, *new_node;
    int   node_number = 0;
    while (next_node->next && node_number < index - 1) {
        next_node = next_node->next;
        node_number++;
    }
    new_node        = new Node;
    new_node->data  = value;
    new_node->next  = next_node->next;
    next_node->next = new_node;

    std::cout << "当前插入节点值为" << value << "，其节点后的数据为：" << std::endl;
    TraversalLinkList(new_node);
    std::cout << std::endl;
    return OK;
}

Status LinkList::ListLength() const {
    std::cout << "链表长度为：" << length << std::endl;
    return OK;
}

Status LinkList::GetElement_Value(ElemType value) {
    Node *node;
    int   node_number = 1;
    node              = head->next;
    while (node) {
        if (node->data == value) {
            std::cout << "成功找到节点值" << value << "，位置为：" << node_number << std::endl;
            return OK;
        }
        node_number++;
        node = node->next;
    }
    std::cout << "没有找到节点值" << value << "的位置！" << std::endl;
    return ERROR;
}