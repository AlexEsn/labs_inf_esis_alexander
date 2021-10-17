#pragma once

#include "../seq/sequence.h"
#include "dynamicarray.h"
#include <iostream>
#include <ostream>

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
    [[nodiscard]] size_t GetLength() const override;

    //Operations
    void Append(const T &value) override;
    void Prepend(const T &value) override;
    void InsertAt(const T &value, int index) override;
    void Resize(int length) override;
    void Remove(int index) override;
    Sequence<T>* GetSubSequence(int start_index, int end_index) const override;
    Sequence<T>* Concat(Sequence <T> *seq) const override;

    //Overloaded operators
    template<typename U>
    friend std::ostream& operator<<(std::ostream& out, const ArraySequence<U>& seq);

    //Destructor
    ~ArraySequence();
};


#include "arraysequence.tpp"