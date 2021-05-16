#pragma once

#include <iostream>
#include <stdexcept>
#include <cstring>

template<class T>
class DynamicArray {

private:
    T *data_;
    size_t length_;

public:
    //Constructors
    DynamicArray();
    DynamicArray(const T *data, int length);
    explicit DynamicArray(int length);

    //Copy constructor
    DynamicArray(const DynamicArray<T> &array);

    //Decomposition
    T &Get(int index);
    T &operator[](int index);
    [[nodiscard]] size_t GetLength() const;

    //Operations
    void Set(int index, T value);
    void Resize(int length);
    void Insert(int insert_index, T value);

    //Destructor
    ~DynamicArray();
};

template<typename T>
DynamicArray<T>::DynamicArray(): data_(nullptr), length_(0){}

template<typename T>
DynamicArray<T>::DynamicArray(const T *data, int length) {
    if (length < 0)
        throw std::out_of_range("negative size");
    else if (length > 0)
        data_ = new T[length];
    else
        data_ = nullptr;
    length_ = length;
    for (int i = 0; i < length_; i++)
        data_[i] = data[i];
}

template<typename T>
DynamicArray<T>::DynamicArray(int length) {
    if (length < 0) throw std::length_error("negative size");
    length_ = length;
    if (length != 0)
        data_ = new T[length];
    else
        data_ = nullptr;
}

template<typename T>
DynamicArray<T>::DynamicArray(const DynamicArray<T> &array) {
    data_ = nullptr;
    length_ = array.length_;
    if (length_ != 0)
        data_ = new T[length_];
    else
        data_ = nullptr;
    for (int i = 0; i < length_; i++)
        data_[i] = array.data_[i];
}

template<typename T>
T &DynamicArray<T>::Get(int index) {
    if (index < 0) throw std::out_of_range("negative index");
    if (index >= length_) Resize(index + 1);
    return data_[index];
}

template<typename T>
size_t DynamicArray<T>::GetLength() const {
    return length_;
}

template<typename T>
T &DynamicArray<T>::operator[](int index) {
    return this->Get(index);
}

template<typename T>
void DynamicArray<T>::Set(int index, T value) {
    Get(index) = value;
}

template<typename T>
void DynamicArray<T>::Insert(int insert_index, T value) {

    length_++;

    if (insert_index < 0)
        throw std::out_of_range("negative index");
    if (insert_index >= length_)
        throw std::out_of_range("index more of length");

    T *new_data = new T[length_];

    for (size_t i = 0; i < insert_index; i++)
        new_data[i] = data_[i];

    for (size_t i = insert_index + 1; i < length_; i++)
        new_data[i] = data_[i - 1];

    new_data[insert_index] = value;

    delete[] data_;
    data_ = new_data;
}

template<typename T>
void DynamicArray<T>::Resize(int length) {

    if (length < 0) throw std::length_error("negative size");
    T *new_data = new T[length];

    if (length > length_)
        memcpy(new_data, data_, length_ * sizeof(T));
    else
        memcpy(new_data, data_, length * sizeof(T));

    length_ = length;
    delete[] data_;
    data_ = new_data;
}

template<typename T>
DynamicArray<T>::~DynamicArray() {
    length_ = 0;
    if(data_ != nullptr) delete[] data_;
}

//#include "dynamicarray.ini"