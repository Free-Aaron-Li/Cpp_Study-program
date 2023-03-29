/**
 * @author AaronLi
 * @date 2023-03-28-下午11:37
 * @license GPL-3.0
 */
#include "List.hpp"

List::~List() {
    Node_List *first_node, *next_node;
    first_node = head;
    next_node  = first_node->next;
    while (next_node != nullptr) {
        delete first_node;
        first_node = next_node;
        next_node  = next_node->next;
    }
    delete first_node;
}

void List::InitiateLinkedList() {
    head       = new Node_List();
    head->next = nullptr; /* 头结点无后继节点 */
    length     = 0;
}

void List::CreateLinked(Node_List &node_list) {
    Node_List *node, *right_node;
    right_node = head;
    std::cout << "请输入链表的节点值：";
    ElemType value;
    while (std::cin >> value) {
        node             = new Node_List();
        node->data       = value;
        right_node->next = node;
        right_node       = node;
        length++;
        if (std::cin.get() == '\n') break;
    }
    right_node->next = nullptr;

    Sort_Link(head->next);
    std::cout << "链表值为：" << std::endl;
    Traverse_Node(head->next);
    std::cout << std::endl;
    node_list = *head;
}

void List::Traverse_Node(Node_List *node) {
    if (node) {
        std::cout << node->data << " ";
        Traverse_Node(node->next);
    }
}

void List::MergeList_Link(Node_List *node_list1, Node_List *node_list2) {
    Node_List *node1, *node2, *node3;
    node1 = node_list1->next;
    node2 = node_list2->next;
    node3 = node_list1;

    while (node1 && node2) {
        if (node2->data <= node1->data) {
            node3->next = node1;
            node3       = node3->next;
            node2       = node2->next;
        } else {
            node3->next = node1;
            node3       = node3->next;
            node1       = node1->next;
        }
    }
    if (node1) node3->next = node1;
    if (node2) node3->next = node2;

    Sort_Link(node_list1->next);
    std::cout << "合并后的链表值为：" << std::endl;
    Traverse_Node(node_list1->next);
    std::cout << std::endl;
}

void List::Sort_Link(Node_List *node_head) {
    if (node_head == nullptr || head->next == nullptr) {
        std::cerr << "链表为空！" << std::endl;
        return;
    }

    Node_List *node1, *node2;
    for (node1 = node_head; node1->next != nullptr; node1 = node1->next) {
        Node_List *node_max = node1;
        for (node2 = node1; node2 != nullptr; node2 = node2->next) {
            if (node_max->data < node2->data) {
                ElemType temporary = node_max->data;
                node_max->data     = node2->data;
                node2->data        = temporary;
            }
        }
        node1->data = node_max->data;
    }
}
