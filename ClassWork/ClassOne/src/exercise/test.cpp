/**
 * @author AaronLi
 * @date 2023-04-03-下午8:54
 * @license GPL-3.0
 */
#define OK    0
#define ERROR (-1)
typedef int ElemType; /* ElemType的类型，默认为int */
typedef int Status;   /* 顺序表状态，1正确 0错误 */

#include <iostream>

class Node {
public:
    ElemType data;  // 存放char类型元素
    Node *next;  // 指向下一个结点域
};

class LinkList {
private:
    Node *head;   /* 单链表头结点指针 */
    int length; /* 单链表长度 */

public:
    /**
     * @description
     * <p> 初始化 </P>
     */
    LinkList();

    /**
     * @description
     * <p> 销毁链表 </P>
     */
    ~LinkList();

    /**
     * @description
     * <p> 创建链表 </P>
     * @def
     * 尾插法
     */
    void CreateLinkList();

    /**
     * @description
     * <p> 遍历链表 </P>
     */
    void TraversalLinkList(Node *node);

    /**
     * @description 
     * <p> 删除最小节点值 </P>
     */
    void DeleteMinValue(Node *node);
};

LinkList::LinkList() {
    head = new Node();
    head->next = nullptr; /* 头结点无后继节点 */
    length = 0;
}

LinkList::~LinkList() {
    Node *first_node, *next_node;
    first_node = head;
    next_node = first_node->next;
    while (next_node != nullptr) {
        delete first_node;
        first_node = next_node;
        next_node = next_node->next;
    }
    delete first_node;
}

void LinkList::CreateLinkList() {
    Node *node, *right_node;
    right_node = head;
    std::cout << "请输入链表的节点值：";
    ElemType value;
    while (std::cin >> value) {
        node = new Node();
        node->data = value;
        right_node->next = node;
        right_node = node;
        length++;
        if (std::cin.get() == '\n') break;
    }
    right_node->next = nullptr;

    std::cout << "当前链表的数据：" << std::endl;
    TraversalLinkList(head->next);
    std::cout << std::endl;
}

void LinkList::TraversalLinkList(Node *node) {
    if (node) {
        std::cout << node->data << " ";
        TraversalLinkList(node->next);
    }
}

void LinkList::DeleteMinValue(Node *node) {
    Node *now_node = node, *next_node = now_node->next;
    Node *min_node = now_node, *min_next_node = next_node;
    while (!next_node) {
        if (next_node->data < min_next_node->data) {
            min_next_node = next_node;
            min_node = now_node;
        }
        now_node = next_node;
        next_node = next_node->next;
    }
    min_node->next = min_next_node->next;
}

int main() {
    LinkList linkList;
    Node node{};
    linkList.CreateLinkList();
    linkList.DeleteMinValue(&node);
    linkList.TraversalLinkList(&node);
}
