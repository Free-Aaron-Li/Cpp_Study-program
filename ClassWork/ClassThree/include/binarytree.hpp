//
// Created by AaronLi on 23-4-24.
//

#ifndef CLASSTHREE_BINARYTREE_HPP
#define CLASSTHREE_BINARYTREE_HPP

/**
 * @title
 * <p> 二叉树 </P>
 */

#include <iostream>
#include <stack>
#include <queue>

/**
 * @title
 * <p> 二叉树元素类型 </P>
 * @description
 *  默认为char
 */

typedef char TreeElemType;

/**
 * @title
 * <p> 二叉树存储结构 </P>
 * @param
 *  data    TreeElemType    存储元素
 * @param
 *  lchild  BinaryTreeNode      左子节点
 * @param
 *  rchild  BinaryTreeNode      右子节点
 */

typedef struct BinaryTreeNode {
    TreeElemType data;
    struct BinaryTreeNode *lchild;
    struct BinaryTreeNode *rchild;
} BinaryTreeNode, *BinaryTree;

class Tree {
public:
    /**
     * @title
     * <p> 创建二叉树 </P>
     * @param
     *  tree    BinaryTree  树对象
     * @description
     *  简化创建，设二叉树每个节点的元素仅包含单字符，且按照先序遍历建立二叉树
     */

    void CreateTree(BinaryTree &tree);

    /* 递归遍历*/

    /**
     * @title
     * <p> 先序遍历 </P>
     * @param
     *  tree    BinaryTree    树对象
     */

    void PreOrderTraverse_Recursion(BinaryTree &tree);

    /**
    * @title
    * <p> 中序遍历 </P>
    * @param
    *  tree    BinaryTree    树对象
    */

    void InOrderTraverse_Recursion(BinaryTree &tree);

    /**
    * @title
    * <p> 后序遍历 </P>
    * @param
    *  tree    BinaryTree    树对象
    */

    void PostOrderTraverse_Recursion(BinaryTree &tree);

    /* 非递归遍历 */

    /**
    * @title
    * <p> 先序遍历 </P>
    * @param
    *  tree     BinaryTree   树对象
    */

    void PreOrderTraverse_NonRecursion(BinaryTree &tree);

    /**
    * @title
    * <p> 中序遍历 </P>
    * @param
    *  tree     BinaryTree   树对象
    */

    void InOrderTraverse_NonRecursion(BinaryTree &tree);

    /**
    * @title
    * <p> 后序遍历 </P>
    * @param
    *  tree     BinaryTree   树对象
    */

    void PostOrderTraverse_NonRecursion(BinaryTree &tree);

    /**
     * @title
     * <p> 层次遍历 </P>
     * @param
     *  tree    BinaryTree   树对象
     */

    void LevelOrderTraverse(BinaryTree &tree);
};

#endif //CLASSTHREE_BINARYTREE_HPP
