/**
 * @author AaronLi
 * @date 2023-04-24-上午10:45
 * @license GPL-3.0
 */
#include "binarytree.hpp"

void Tree::CreateTree(BinaryTree &tree) {
    TreeElemType value;
    std::cin >> value;
    if (value == '#') { tree = nullptr; }
    else {
        tree = new BinaryTreeNode;
        tree->data = value;
        CreateTree(tree->lchild);
        CreateTree(tree->rchild);
    }

}

void Tree::PreOrderTraverse_Recursion(BinaryTree &tree) {
    if (tree) {
        std::cout << tree->data;
        PreOrderTraverse_Recursion(tree->lchild);
        PreOrderTraverse_Recursion(tree->rchild);
    }
}

void Tree::InOrderTraverse_Recursion(BinaryTree &tree) {
    if (tree) {
        InOrderTraverse_Recursion(tree->lchild);
        std::cout << tree->data;
        InOrderTraverse_Recursion(tree->rchild);
    }
}

void Tree::PostOrderTraverse_Recursion(BinaryTree &tree) {
    if (tree) {
        PostOrderTraverse_Recursion(tree->lchild);
        PostOrderTraverse_Recursion(tree->rchild);
        std::cout << tree->data;
    }
}

void Tree::PreOrderTraverse_NonRecursion(BinaryTree &tree) {
    std::stack<BinaryTree> stack;
    BinaryTree root_tree = tree;

    while (root_tree || !stack.empty()) {
        if (root_tree) {
            stack.push(root_tree);
            std::cout << root_tree->data;
            root_tree = root_tree->lchild;
        } else {
            root_tree = stack.top();
            stack.pop();
            root_tree = root_tree->rchild;
        }
    }
}

void Tree::InOrderTraverse_NonRecursion(BinaryTree &tree) {
    std::stack<BinaryTree> stack;
    BinaryTree root_tree = tree;

    while (root_tree || !stack.empty()) {
        if (root_tree) {
            stack.push(root_tree);
            root_tree = root_tree->lchild;
        } else {
            root_tree = stack.top();
            stack.pop();
            std::cout << root_tree->data;
            root_tree = root_tree->rchild;
        }
    }
}

void Tree::PostOrderTraverse_NonRecursion(BinaryTree &tree) {
    std::stack<BinaryTree> stack;
    BinaryTree root_tree = tree;
    BinaryTree pre_tree = nullptr;

    stack.push(root_tree);
    while (!stack.empty()) {
        root_tree = stack.top();
        if ((root_tree->lchild == nullptr && root_tree->rchild == nullptr) ||
            ((pre_tree == root_tree->lchild || pre_tree == root_tree->rchild) && pre_tree != nullptr)) {
            std::cout << root_tree->data;
            stack.pop();
            pre_tree = root_tree;
        } else {
            if (root_tree->rchild != nullptr)
                stack.push(root_tree->rchild);
            if (root_tree->lchild != nullptr)
                stack.push(root_tree->lchild);
        }
    }

}

void Tree::LevelOrderTraverse(BinaryTree &tree) {
    std::queue<BinaryTree> queue;
    BinaryTree root_tree = tree;
    queue.push(root_tree);

    while (!queue.empty()) {
        root_tree = queue.front();
        queue.pop();
        std::cout << root_tree->data;
        if (root_tree->lchild != nullptr)
            queue.push(root_tree->lchild);
        if (root_tree->rchild != nullptr)
            queue.push(root_tree->rchild);
    }
}
