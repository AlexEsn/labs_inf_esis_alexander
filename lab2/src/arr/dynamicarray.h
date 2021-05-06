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
    DynamicArray(T *data, int index);
    DynamicArray(int length);
    DynamicArray(const DynamicArray<T>& array);

    //Decomposition, an [] operator may be very useful here
    T& Get(int index);
    int GetLength() const;

    //Operations
    void Set(int index, T value);
    void Resize(int length);

    //Destructor
    ~DynamicArray();
};