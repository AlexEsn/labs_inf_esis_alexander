#include "arraysequence.h"

template<typename T>
ArraySequence<T>::ArraySequence(): _array(new DynamicArray <T>()) {}

template<typename T>
ArraySequence<T>::ArraySequence(T* data, int count)
{
    _array = new DynamicArray<T>(data, count);
}

template<typename T>
ArraySequence<T>::ArraySequence(DynamicArray<T> &array)
{
    _array = new LinkedList<T>(array);
}

template<typename T>
T &ArraySequence<T>::GetFirst() {
    return _array->Get(0);
}

template<typename T>
T &ArraySequence<T>::GetLast() {
    return _array->Get(this->GetLength());
}

template<typename T>
T &ArraySequence<T>::Get(int index)
{
    return _array->Get(index);
}

template<typename T>
Sequence<T> *ArraySequence<T>::GetSubSequence(int start_index, int end_index) const
{

}

template<typename T>
int ArraySequence<T>::GetLength() const {
    std::cout << "i am from ArraySequence implementation of GetLength() method" << std::endl; //look at custom.h
    return _array->GetLength();
}

template<typename T> // dumb implementation from here
void ArraySequence<T>::Append(const T &value){
    _array->Resize(this->GetLength()+1);
    _array->Set(0, value);
}

template<typename T>
void ArraySequence<T>::Prepend(const T &value) {
    _array->Resize(this->GetLength()+1);
    _array->Set(this->GetLength(), value);
}

template<typename T>
void ArraySequence<T>::InsertAt(const T &value, int index) {
    _array->Resize(this->GetLength()+1);
    _array->Set(index, value);
}

template<typename T>
Sequence<T> *ArraySequence<T>::Concat(Sequence<T> *seq) const
{

}

template<typename T>
ArraySequence<T>::~ArraySequence()
{
    delete _array;
}
