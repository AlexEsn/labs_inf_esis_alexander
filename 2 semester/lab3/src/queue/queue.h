#pragma once

#include "../list/listsequence.h"
#include "../arr/arraysequence.h"

template<class T>
class queue {

private:
    Sequence<T> *data_;

public:
    queue() : data_(new ListSequence<T>) {};

    void push(const T &value) {
        data_->Append(value);
    }

    T front() {
        return data_->GetFirst();
    }

    bool empty() {
        return (data_->GetLength() == 0);
    }

    T &back() {
        return &data_->GetLast();
    }

    void pop() {
        data_->Remove(0);
    }

    ~queue() {
        delete (ListSequence<T>*) data_;
    };
};