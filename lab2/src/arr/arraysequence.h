#pragma once

#include "../seq/sequence.h"
#include "dynamicarray.h"

template<class T>
class ArraySequence : public Sequence<T> {

private:
    DynamicArray<T> *array_;

public:
    //Constructors
    ArraySequence();

    explicit ArraySequence(int length);

    ArraySequence(const T *data, int length);

    //Copy constructor
    ArraySequence(const ArraySequence<T> &array);

    //Decomposition
    T &GetFirst() override;

    T &GetLast() override;

    T &Get(int index) override;

    T &operator[](int index) override;

//    Sequence<T>* GetSubSequence(int start_index, int end_index) const override;     //TODO
    [[nodiscard]] size_t GetLength() const override;

    //Operations
    void Append(const T &value) override;

    void Prepend(const T &value) override;

    void InsertAt(const T &value, int index) override;
//    Sequence<T>* Concat(Sequence <T> *seq) const override;          //TODO

    //Destructor
    ~ArraySequence();
};

template<typename T>
ArraySequence<T>::ArraySequence():
        array_(new DynamicArray<T>()) {}

template<typename T>
ArraySequence<T>::ArraySequence(int length):
        array_(new DynamicArray<T>(length)) {}

template<typename T>
ArraySequence<T>::ArraySequence(const T *data, int length):
        array_(new DynamicArray<T>(data, length)) {}

template<typename T>
ArraySequence<T>::ArraySequence(const ArraySequence<T> &array):
        array_(new DynamicArray<T>(*array.array_)) {}

template<typename T>
T &ArraySequence<T>::GetFirst() {
    return array_->Get(0);
}

template<typename T>
T &ArraySequence<T>::GetLast() {
    return array_->Get(this->GetLength() - 1);
}

template<typename T>
T &ArraySequence<T>::Get(int index) {
    return array_->Get(index);
}

template<class T>
T &ArraySequence<T>::operator[](int index) {
    return array_->Get(index);
}

template<typename T>
size_t ArraySequence<T>::GetLength() const {
    return array_->GetLength();
}

template<typename T>
void ArraySequence<T>::Append(const T &value) {
    array_->Insert(0, value);
}

template<typename T>
void ArraySequence<T>::Prepend(const T &value) {
    array_->Insert(array_->GetLength(), value);
}

template<typename T>
void ArraySequence<T>::InsertAt(const T &value, int index) {
    array_->Insert(index, value);
}

template<typename T>
ArraySequence<T>::~ArraySequence() {
    delete array_;
}