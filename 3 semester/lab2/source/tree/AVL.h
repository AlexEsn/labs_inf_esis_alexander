#pragma once

#include <stdexcept>        //for exeption

template <class T>
struct BTreeNode
{
    T element_;
    BTreeNode *left_;
    BTreeNode *right_;
    size_t height_;

    explicit BTreeNode(T k);
};

template<class T>
struct BTree {

    BTreeNode<T> *root_;

    //Constructors
    BTree();
    explicit BTree(T element);

    //Operations
    size_t Size();
    void Insert(T element);
    void Remove(T element);

private:
    //Decomposition
    size_t Height(BTreeNode<T> *node);
    int BalanceCoefficient(BTreeNode<T> *node);
    void FixHeight(BTreeNode<T> *node);
    BTreeNode<T> *RotateRight(BTreeNode<T> *node);
    BTreeNode<T> *RotateLeft(BTreeNode<T> *node);
    BTreeNode<T> *Balance(BTreeNode<T> *node);
    BTreeNode<T> *FindMin(BTreeNode<T> *node);
    BTreeNode<T> *RemoveMin(BTreeNode<T> *node);
    BTreeNode<T> *insert(BTreeNode<T> *node, T element);
    BTreeNode<T> *remove(BTreeNode<T> *node, T element);
};

#include "AVL.tpp"