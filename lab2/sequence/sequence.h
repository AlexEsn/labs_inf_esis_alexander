#ifndef SEQUENCE_H
#define SEQUENCE_H

#include "list/linkedlist.h"
#include "arr/dynamicarray.h"

template<typename T>
class Sequence {

public:
    //Decomposition
    virtual T& GetFirst() = 0;
    virtual T& GetLast() = 0;
    virtual T& Get(int index) = 0;
    virtual Sequence<T> *GetSubSequence(int start_index, int end_index) const = 0;
    virtual int GetLength() const = 0;

    //Operations
    virtual void Append(const T& item) = 0;
    virtual void Prepend(const T& item) = 0;
    virtual void InsertAt(const T& item, int index) = 0;
    virtual Sequence<T> *Concat(Sequence<T> *Sequence) const = 0;

    //Map, reduce, zip, unzip, where, etc.

};

#endif // SEQUENCE_H
