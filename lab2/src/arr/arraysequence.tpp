
#include "arraysequence.h"

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

template<class T>
void ArraySequence<T>::Resize(int length) {
    array_->Resize(length);
}

template<class T>
Sequence<T> *ArraySequence<T>::GetSubSequence(int start_index, int end_index) const {
    if (start_index < 0) throw std::out_of_range("negative start index");
    if (start_index >= array_->GetLength()) throw std::out_of_range("start index is more then length");
    if (end_index >= array_->GetLength()) throw std::out_of_range("end index is more then length");
    T *new_arr = new T[end_index - start_index + 1];
    for (int i = start_index; i <= end_index; ++i) {
        new_arr[i - start_index] = array_->Get(i);
    }
    return new ArraySequence<T>(new_arr, end_index - start_index + 1);
}

template<class T>
Sequence<T> *ArraySequence<T>::Concat(Sequence<T> *seq) const {
    if (seq->GetLength() == 0 && this->array_ == nullptr) throw std::logic_error("both containers are empty");
    T *new_arr = new T[seq->GetLength() + this->GetLength()];
    for (int i = 0; i < array_->GetLength(); ++i) {
        new_arr[i] = array_->Get(i);
    }
    for (int i = 0; i < seq->GetLength(); ++i) {
        new_arr[i + array_->GetLength()] = seq->Get(i);
    }
    return new ArraySequence<T>(new_arr, seq->GetLength() + this->GetLength());
}

