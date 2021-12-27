#pragma once
#include "../vector/vector.h"

template<typename T>
struct TreeNodeVector {
    T data_;
    vector<TreeNodeVector<T> *> child_;
};

template<typename T>
TreeNodeVector<T> *newNode(T data) {
    TreeNodeVector<T> *temp = new TreeNodeVector<T>;
    temp->data_ = data;
    return temp;
}