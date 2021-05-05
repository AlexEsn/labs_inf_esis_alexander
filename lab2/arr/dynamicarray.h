#pragma once

#include <iostream>

template <typename T>
class DynamicArray
{
private:
    T *_data;
    size_t _length;

public:
    //Constructors
    DynamicArray();
    DynamicArray(T *data, size_t index);
    DynamicArray(size_t length);
    DynamicArray(const DynamicArray<T>& array);

    //Decomposition, an [] operator may be very useful here
    T& Get(size_t index);
    int GetLength() const;

    //Operations
    void Set(size_t index, T value);
    void Resize(size_t length);

    //Destructor
    ~DynamicArray();
};