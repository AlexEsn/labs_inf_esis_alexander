#include <iostream>
#pragma once

template<typename T>
class Sequence {

public:
    //Decomposition
    virtual T& GetFirst() = 0;
    virtual T& GetLast() = 0;
    virtual T& Get(int index) = 0;
    virtual T& operator[](int index) = 0;
    [[nodiscard]] virtual size_t GetLength() const = 0;

    //Operations
    virtual void Append(const T& item) = 0;
    virtual void Prepend(const T& item) = 0;
    virtual void InsertAt(const T& item, int index) = 0;
    virtual void Resize(int length) = 0;
    virtual void Remove(int index) = 0;
    virtual Sequence<T> *Concat(Sequence<T> *Sequence) const = 0;
    virtual Sequence<T> *GetSubSequence(int start_index, int end_index) const = 0;
};
