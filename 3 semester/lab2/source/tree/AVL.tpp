
#include "AVL.h"

template<class T>
BTreeNode<T>::BTreeNode(T k) : element_(k), left_(nullptr), right_(nullptr), height_(1){};

template<class T>
BTree<T>::BTree() : root_(nullptr) {}

template<class T>
BTree<T>::BTree(T element) : root_(new BTreeNode<T>(element)) {}

template<class T>
size_t BTree<T>::Size() {
        if (!root_) return 0;
        return Height(root_);
    }

template<class T>
void BTree<T>::Insert(T element) {
    root_ = insert(root_, element);
}

template<class T>
void BTree<T>::Remove(T element) {
    root_ = remove(root_, element);
}

template<class T>
size_t BTree<T>::Height(BTreeNode<T> *node) {
    return node ? node->height_ : 0;
}

template<class T>
int BTree<T>::BalanceCoefficient(BTreeNode<T> *node) {
    return Height(node->right_) - Height(node->left_);
}

template<class T>
void BTree<T>::FixHeight(BTreeNode<T> *node) {
    size_t hl = Height(node->left_);
    size_t hr = Height(node->right_);
    node->height_ = (hl > hr ? hl : hr) + 1;
}

template<class T>
BTreeNode<T> *BTree<T>::RotateRight(BTreeNode<T> *node) {
    BTreeNode<T> *q = node->left_;
    node->left_ = q->right_;
    q->right_ = node;
    FixHeight(node);
    FixHeight(q);
    return q;
}

template<class T>
BTreeNode<T> *BTree<T>::RotateLeft(BTreeNode<T> *q) {
    BTreeNode<T> *node = q->right_;
    q->right_ = node->left_;
    node->left_ = q;
    FixHeight(q);
    FixHeight(node);
    return node;
}

template<class T>
BTreeNode<T> *BTree<T>::Balance(BTreeNode<T> *node) {
    FixHeight(node);
    if (BalanceCoefficient(node) == 2) {
        if (BalanceCoefficient(node->right_) < 0)
            node->right_ = RotateRight(node->right_);
        return RotateLeft(node);
    }
    if (BalanceCoefficient(node) == -2) {
        if (BalanceCoefficient(node->left_) > 0)
            node->left_ = RotateLeft(node->left_);
        return RotateRight(node);
    }
    return node;
}

template<class T>
BTreeNode<T> *BTree<T>::FindMin(BTreeNode<T> *node) {
    return node->left_ ? FindMin(node->left_) : node;
}

template<class T>
BTreeNode<T> *BTree<T>::RemoveMin(BTreeNode<T> *node) {
    if (node->left_ == 0)
        return node->right_;
    node->left_ = RemoveMin(node->left_);
    return Balance(node);
}

template<class T>
BTreeNode<T> *BTree<T>::insert(BTreeNode<T> *node, T element) {
    if (!node) return new BTreeNode<T>(element);
    if (element < node->element_)
        node->left_ = insert(node->left_, element);
    else if (element > node->element_)
        node->right_ = insert(node->right_, element);
    return Balance(node);
}

template<class T>
BTreeNode<T> *BTree<T>::remove(BTreeNode<T> *node, T element) {
    if (!node) return nullptr;
    if (element < node->element_)
        node->left_ = remove(node->left_, element);
    else if (element > node->element_)
        node->right_ = remove(node->right_, element);
    else {
        BTreeNode<T> *q = node->left_;
        BTreeNode<T> *r = node->right_;
        delete node;
        if (!r) return q;
        BTreeNode<T> *min = FindMin(r);
        min->right_ = RemoveMin(r);
        min->left_ = q;
        return Balance(min);
    }
    return Balance(node);
}