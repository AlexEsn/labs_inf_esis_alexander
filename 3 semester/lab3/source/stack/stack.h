#pragma once

#include "../list/listsequence.h"
#include "../arr/arraysequence.h"

template<class T>
class stack {

private:
    Sequence<T> *data_;

public:
    stack() : data_(new ListSequence<T>) {};

    void push(const T &value) {
        data_->Append(value);
    }

    T top() {
        return data_->GetFirst();
    }

    bool empty() {
        return (data_->GetLength() == 0);
    }

    void pop() {
        data_->Remove(0);
    }

    size_t size() {
        data_->GetLength();
    }

    ~stack() {
        delete (ListSequence<T>*) data_;
    };
};