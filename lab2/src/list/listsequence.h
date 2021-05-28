#pragma once

#include "../seq/sequence.h"
#include "linkedlist.h"

template <class T>
class ListSequence: public Sequence<T>
{

private:
    LinkedList<T> *list_;

public:
    //Constructors
    ListSequence();
    ListSequence(T* data, int length);
    ListSequence(LinkedList<T>& list);

    //Decomposition
    T& GetFirst() override;
    T& GetLast() override;
    T& Get(int index) override;
    T& Get(int index) const;
    T& operator[](int index) override;
    [[nodiscard]] size_t GetLength() const override;

    //Operations
    void Append(const T& value) override;
    void Prepend(const T& value) override;
    void InsertAt(const T& value, int index) override;
    void Resize(int length) override;
    void Remove(int index) override;
    Sequence<T>* GetSubSequence(int start_index, int end_index) const override;
    Sequence<T>* Concat(Sequence <T> *seq) const override;

    //Destructor
    ~ListSequence();
};

#include "listsequence.tpp"