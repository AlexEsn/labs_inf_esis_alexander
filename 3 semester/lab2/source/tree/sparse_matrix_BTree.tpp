
#include "sparse_matrix_BTree.h"

template<class T>
compressed_matrix<T>::compressed_matrix(int num_row, int num_colum, BTree<std::pair<std::pair<int, int>, T>> *node) :
        data_(node), size_(0) {
    if (num_row < 0) throw std::out_of_range("invalid num row");
    if (num_colum < 0) throw std::out_of_range("invalid num column");
    row_ = num_row;
    column_ = num_colum;
}

template<class T>
compressed_matrix<T>::compressed_matrix() :
        column_(0), row_(0), data_(new BTree<std::pair<std::pair<int, int>, T>>), size_(0) {}


template<class T>
compressed_matrix<T>::compressed_matrix(int num_colum, int num_row) :
        data_(new BTree<std::pair<std::pair<int, int>, T>>), size_(0) {
    if (num_row < 0) throw std::out_of_range("invalid num row");
    if (num_colum < 0) throw std::out_of_range("invalid num column");
    row_ = num_row;
    column_ = num_colum;
}

template<class T>
void compressed_matrix<T>::resize(int num_colum, int num_row, bool flag) {
    if (num_row < 0) throw std::out_of_range("invalid num row");
    if (num_colum < 0) throw std::out_of_range("invalid num column");
    column_ = num_colum;
    row_ = num_row;
}

template<class T>
int compressed_matrix<T>::nnz() {
    return size_;
}

template<class T>
void compressed_matrix<T>::push_back(int index_column, int index_row, T element) {
    if (index_row >= row_ || index_row < 0) throw std::out_of_range("invalid index");
    if (index_column >= column_ || index_column < 0) throw std::out_of_range("invalid index");
    size_++;
    data_->Insert(std::make_pair(std::make_pair(index_column, index_row), element));
}

template<class T>
int compressed_matrix<T>::size1() {
    return column_;
}

template<class T>
int compressed_matrix<T>::size2() {
    return row_;
}

template<class T>
T &compressed_matrix<T>::operator()(int index_column, int index_row) {
    queue<BTreeNode<std::pair<std::pair<int, int>, T>> *> queue_node;
    auto index = std::make_pair(index_column, index_row);
    queue_node.push(data_->root_);
    while (!queue_node.empty()) {
        auto p = queue_node.front();
        queue_node.pop();
        if (p == nullptr) {
            T *emptiness = new T;
            *emptiness = 0;
            return *emptiness;
        }
        if (index < p->element_.first) {
            queue_node.push(p->left_);
        } else if (index > p->element_.first)
            queue_node.push(p->right_);
        else {
            return p->element_.second;
        }

    }
}


template<typename T>
compressed_matrix<T> &operator+(compressed_matrix<T> matrix1, compressed_matrix<T> matrix2) {
    std::vector<std::vector<T>> v(matrix1.size1());
    for (int i = 0; i < matrix2.size1(); ++i) {
        v[i].resize(matrix2.size1());
        for (int j = 0; j < matrix2.size2(); ++j) {
            v[i][j] = 0;
        }
    }
    queue<BTreeNode<std::pair<std::pair<int, int>, T>> *> queue_node;
    queue_node.push(matrix1.data_->root_);
    while (!queue_node.empty()) {
        auto p = queue_node.front();
        queue_node.pop();
        if (p) {
            v[p->element_.first.first][p->element_.first.second] += p->element_.second;
            queue_node.push(p->right_);
            queue_node.push(p->left_);
        }

    }
    queue_node.push(matrix2.data_->root_);
    while (!queue_node.empty()) {
        auto p = queue_node.front();
        queue_node.pop();
        if (p) {
            v[p->element_.first.first][p->element_.first.second] += p->element_.second;
            queue_node.push(p->right_);
            queue_node.push(p->left_);
        }

    }
    auto *result_matrix = new compressed_matrix<T>(matrix2.size1(), matrix2.size2());
    for (int i = 0; i < matrix1.size1(); ++i) {
        for (int j = 0; j < matrix1.size2(); ++j) {
            if (v[i][j] != 0) (*result_matrix).push_back(i, j, v[i][j]);
        }
    }
    return *result_matrix;
}
