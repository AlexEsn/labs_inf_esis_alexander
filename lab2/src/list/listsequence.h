#pragma once

#include "../sequence/sequence.h"
#include "linkedlist.h"
#include "linkedlist.cpp"
#include "iostream"

template <typename T>
class ListSequence: public Sequence<T>
{

private:
    LinkedList<T> *_list;

public:
    //Constructors
    ListSequence();
    ListSequence(T* data, int count);
    ListSequence(LinkedList<T>& list);

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
    ~ListSequence();
};