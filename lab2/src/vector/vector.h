#pragma once

#include "list/listsequence.h"
#include "arr/arraysequence.h"

template<class T>
class vector {

private:
    Sequence<T> *array_;

public:
    vector();
    explicit vector(int length);
    vector(const T *data, int length);
    vector(const vector<T> &vector);

    [[nodiscard]] size_t size() const;
    [[nodiscard]] bool empty() const;
    T &operator[](int index);
    T &at(int index);
    T &at(int index) const;
    void resize(int length);
    void push_back(const T &value);

    ~vector();
};

template<class T>
vector<T>::vector() :
        array_(new ArraySequence<T>) {}

template<typename T>
vector<T>::vector(int length):
        array_(new ArraySequence<T>(length)) {}

template<class T>
vector<T>::vector(const T *data, int length):
        array_(new ArraySequence<T>(data, length)) {}

template<class T>
T &vector<T>::operator[](int index) {
    if (index >= this->size())
        throw std::out_of_range("out of range");
    return array_->Get(index);
}

template<class T>
T &vector<T>::at(int index) {
    if (index >= this->size())
        throw std::out_of_range("out of range");
    return array_->Get(index);
}

template<class T>
T &vector<T>::at(int index) const {
    if (index >= this->size())
        throw std::out_of_range("out of range");
    return array_->Get(index);
}

template<class T>
void vector<T>::push_back(const T &value) {
    array_->Append(value);
}

template<class T>
vector<T>::vector(const vector <T> &vector):
        array_(new ArraySequence<T>(*((ArraySequence<T> *) vector.array_))) {}

template<class T>
vector<T>::~vector() {
    delete (ArraySequence<T> *) array_;
}

template<typename T>
size_t vector<T>::size() const {
    return array_->GetLength();
}

template<class T>
bool vector<T>::empty() const {
    return (array_->GetLength() == 0);
}

template<class T>
void vector<T>::resize(int length) {
    array_->Resize(length);
}
