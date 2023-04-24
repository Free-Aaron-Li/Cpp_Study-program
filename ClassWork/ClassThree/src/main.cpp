/**
 * @author AaronLi
 * @date 2023-04-17-下午8:26
 * @license GPL-3.0
 */
#include "main.hpp"

int main() {
    Tree tree;
    BinaryTree binaryTree;
    std::cout<<"请使用先序遍历的方式输入树节点\n";
    tree.CreateTree(binaryTree);

    std::cout<<"递归方式：\n";
    std::cout<<"先序遍历输出树的节点：\n";    
    tree.PreOrderTraverse_Recursion(binaryTree);
    std::cout<<"\n";
    std::cout<<"中序遍历输出树的节点：\n";
    tree.InOrderTraverse_Recursion(binaryTree);
    std::cout<<"\n";
    std::cout<<"后序遍历输出树的节点：\n";
    tree.PostOrderTraverse_Recursion(binaryTree);
    std::cout<<"\n";
    std::cout<<"非递归方式：\n";
    std::cout<<"先序遍历输出树的节点：\n";
    tree.PreOrderTraverse_NonRecursion(binaryTree);
    std::cout<<"\n";
    std::cout<<"中序遍历输出树的节点：\n";
    tree.InOrderTraverse_NonRecursion(binaryTree);
    std::cout<<"\n";
    std::cout<<"后序遍历输出树的节点：\n";
    tree.PostOrderTraverse_NonRecursion(binaryTree);
    std::cout<<"\n";
    std::cout<<"层次遍历输出树的节点：\n";
    tree.LevelOrderTraverse(binaryTree);
}