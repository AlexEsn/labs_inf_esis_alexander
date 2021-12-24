#pragma once

#include "../bintree/binTree.h"
#include "../binheap/binheap.h"

template<class T>
class pqueue {

private:
    BinaryArrayHeap<T> *data_;

public:
    pqueue() : data_(new BinaryArrayHeap<T>) {};

    void push(const T &value) {
        data_->Add(value);
    }

    T front() {
        return data_->GetMax();
    }

    bool empty() {
        return (data_->Size() == 0);
    }

    void pop() {
        data_->GetMax();
    }

    ~pqueue() {
        delete data_;
    };
};
