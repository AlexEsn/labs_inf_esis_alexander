#pragma once

#include <utility>                                          //pair
#include "AVL.h"
#include "../vector/vector.h"
#include "../queue/queue.h"

template<class T>
class compressed_matrix {

private:
    BTree<std::pair<std::pair<int, int>, T>> *data_;
    int column_;
    int row_;
    size_t size_;

    //Constructors
    compressed_matrix(int num_row, int num_colum, BTree<std::pair<std::pair<int, int>, T>> *node);

public:
    compressed_matrix();
    compressed_matrix(int num_colum, int num_row);

    //Decomposition
    void resize(int num_colum, int num_row, bool flag);
    int nnz();
    void push_back(int index_column, int index_row, T element);
    int size1();
    int size2();

    //Overloaded operators
    T &operator()(int index_column, int index_row);

    template<typename U>
    friend compressed_matrix<U> &operator+(compressed_matrix<U> matrix1, compressed_matrix<U> matrix2);

};

#include "sparse_matrix_BTree.tpp"