#include "dynamicarray.h"

template<typename T>
DynamicArray<T>::DynamicArray() {
    _data = nullptr;
    _length = 0;
}

template<typename T>
DynamicArray<T>::DynamicArray(T *data, int index)
{
    if(index)
        _data = new T[index];
    else _data = nullptr;
    _length = index;
    for (int i = 0; i < _length; i++)
        _data[i] = data[i];
}

template<typename T>
DynamicArray<T>::DynamicArray (const DynamicArray<T> &array)
{
    _data = nullptr;
    _length = array._length;
    if (_length != 0)
        _data = new T[_length];
    else
        _data = nullptr;
    for (int i = 0; i < _length; i++)
        _data[i] = array._data[i];
}

template<typename T>
T &DynamicArray<T>::Get(int index)
{
    return _data[index];
}

template<typename T>
DynamicArray<T>::DynamicArray (int length)
{
    _length = length;
    if (length != 0)
        _data = new T[length];
    else
        _data = nullptr;
}

template<typename T>
int DynamicArray<T>::GetLength() const {
    return _length;
}

template<typename T>
void DynamicArray<T>::Set(int index, T value)
{

}

template<typename T>
void DynamicArray<T>::Resize(int length)
{

}

template<typename T>
DynamicArray<T>::~DynamicArray()
{
    _length = 0;
    delete[] _data;
}
