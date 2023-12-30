// Copyright (c) 2023. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug, please let me know:
// <communicate_aaron@outlook.com>.

// This file is part of 'Cpp_Primer_Studying' project.
// This program is called:'13_2'.
// If there are no special instructions, this file is used as an exercise and test file.
#include "13_2.hpp"

#include <utility>
#include "../../../../PartII_STL/ChapterTwelve_DynamicMemory/include/StrBlob.hpp"

void
Exercise_13_2::meaninglessFunction_1() {}

void
Exercise_13_2::meaninglessFunction_2() {}

void
Exercise_13_2::meaninglessFunction_3() {}

void
Exercise_13_2::meaninglessFunction_4() {}

void
Exercise_13_2::exercise_13_22() {
    Has_Ptr v1;
    Has_Ptr v2("hello");
    std::cout << "v2, str: \"" << v2.get_str() << "\" int: " << v2.get_int() << "\n";
    v1 = v2;
    std::cout << "v1, str: \"" << v1.get_str() << "\" int: " << v1.get_int() << "\n";
    v2.set("hello world", 1);
    std::cout << "v2, str: \"" << v1.get_str() << "\" int: " << v1.get_int() << "\n";  // one value
    std::cout << "v1, str: \"" << v2.get_str() << "\" int: " << v2.get_int() << "\n";  // two value
}

//------------------------------------------------------------------------------------------------

class TreeNode {
 public:
    TreeNode() : _value(), _count(0), _left(nullptr), _right(nullptr) {}

    TreeNode(std::string value, int count) : _value(std::move(value)), _count(count), _left(nullptr), _right(nullptr) {}

    TreeNode(const TreeNode &obj);
    ~TreeNode();

    TreeNode &operator=(const TreeNode &obj);

    /* Test request */
    void print();
    void setValue(const std::string &value);
    void setCount(int count);

 private:
    std::string _value;
    int         _count;
    TreeNode   *_left;
    TreeNode   *_right;
};

TreeNode::TreeNode(const TreeNode &obj) : _value(obj._value), _count(obj._count), _left(nullptr), _right(nullptr) {
    if (obj._left)
        _left = new TreeNode(*obj._left);
    if (obj._right)
        _right = new TreeNode(*obj._right);
}

TreeNode::~TreeNode() {
    delete _left;
    delete _right;
}

TreeNode &
TreeNode::operator=(const TreeNode &obj) {
    _value        = obj._value;
    _count        = obj._count;
    TreeNode *tmp = nullptr;
    if (obj._left)
        tmp = new TreeNode(*obj._left);
    delete _left;
    _left = tmp;

    tmp = nullptr;
    if (obj._right)
        tmp = new TreeNode(*obj._right);
    delete _right;
    _right = tmp;
    return *this;
}

void
TreeNode::print() {
    std::cout << "value is: '" << _value << "', count is: '" << _count << "'.\n";
}

void
TreeNode::setValue(const std::string &value) {
    _value = value;
}

void
TreeNode::setCount(int count) {
    _count = count;
}

class BinStrTree {
 public:
    explicit BinStrTree(const TreeNode &treeNode = TreeNode())
        : _root(new TreeNode(treeNode)), _use(new std::size_t(1)) {}

    BinStrTree(const BinStrTree &obj);
    ~BinStrTree();
    BinStrTree &operator=(const BinStrTree &obj);

 private:
    TreeNode    *_root;
    std::size_t *_use;
};

BinStrTree::BinStrTree(const BinStrTree &obj) : _root(new TreeNode(*obj._root)), _use(obj._use) { ++*_use; }

BinStrTree::~BinStrTree() {
    if (--*_use == 0) {
        delete _root;
        delete _use;
        std::cout << "no members points to this object";
    }
}

BinStrTree &
BinStrTree::operator=(const BinStrTree &obj) {
    ++*obj._use;
    if (--*_use == 0) {
        delete _root;
        delete _use;
    }
    _root = obj._root;
    _use  = obj._use;
    return *this;
}

void
Exercise_13_2::exercise_13_28() {
    TreeNode node("node", 2);
    node.print();
    BinStrTree bin(node);
    TreeNode   node_1(node);
    node_1.setValue("node_1");
    node_1.setCount(3);
    node_1.print();
    TreeNode node_2(node);
    node_2.setValue("node_2");
    node_2.setCount(4);
    node_2.print();
}

//------------------------------------------------------------------------------------------------
