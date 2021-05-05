#pragma once

#include "../sequence/sequence.h"
#include "dynamicarray.h"
#include "dynamicarray.cpp"
#include "iostream"

template <typename T>
class ArraySequence: public Sequence<T>
{

private:
    DynamicArray<T> *_array;

public:
    //Constructors
    ArraySequence();
    ArraySequence(T* data, int count);
    ArraySequence(DynamicArray<T>& array);

    //Decomposition
    T& GetFirst();
    T& GetLast();
    T& Get(int index); //an [] operator would be needed here
    Sequence<T>* GetSubSequence(int start_index, int end_index) const;
    int GetLength() const;

    //Operations
    void Append(const T& value);
    void Prepend(const T& value);
    void InsertAt(const T& value, int index);
    Sequence<T>* Concat(Sequence <T> *seq) const;

    //Destructor
    ~ArraySequence();
};
