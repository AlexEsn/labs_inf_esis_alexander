#pragma once

#include "../seq/sequence.h"
#include "linkedlist.h"

template <class T>
class ListSequence: public Sequence<T>
{

private:
    LinkedList<T> *_list;

public:
    //Constructors
    ListSequence();
    ListSequence(T* data, int length);
    explicit ListSequence(LinkedList<T>& list);

    //Decomposition
    T& GetFirst() override;
    T& GetLast() override;
    T& Get(int index) override;
    T& operator[](int index) override;
//    Sequence<T>* GetSubSequence(int start_index, int end_index) const override;           //TODO
    [[nodiscard]] size_t GetLength() const override;

    //Operations
    void Append(const T& value) override;
    void Prepend(const T& value) override;
    void InsertAt(const T& value, int index) override;
    void Resize(int length) override;
//    Sequence<T>* Concat(Sequence <T> *seq) const override ;                               //TODO

    //Destructor
    ~ListSequence();
};

template<typename T>
ListSequence<T>::ListSequence(): _list(new LinkedList <T>()) {}

template<typename T>
ListSequence<T>::ListSequence(T *data, int length)
{
    _list = new LinkedList<T>(data, length);
}

template<typename T>
ListSequence<T>::ListSequence(LinkedList<T> &list)
{
    _list = new LinkedList<T>(list);
}

template<typename T>
T &ListSequence<T>::GetFirst(){
    auto it = _list->begin();
    return *it;
}

template<typename T>
T &ListSequence<T>::GetLast(){
    auto it = _list->end();
    return *(--it);
}

template<typename T>
T &ListSequence<T>::Get(int index)
{
    auto it = _list->get_nth(index);
    return *it;
}

template<typename T>
size_t ListSequence<T>::GetLength() const {
    return _list->GetLength();
}

template<typename T>
void ListSequence<T>::Append(const T &value){
    _list->push_back(value);
}

template<typename T>
void ListSequence<T>::Prepend(const T &value) {
    _list->push_front(value);
}

template<typename T>
void ListSequence<T>::InsertAt(const T &value, int index) {
    auto it = _list->get_nth(index - 1);
    _list->insert_after(value, it);
}

template<typename T>
ListSequence<T>::~ListSequence()
{
    delete _list;
}

template<class T>
T &ListSequence<T>::operator[](int index){
    return Get(index);
}

template<class T>
void ListSequence<T>::Resize(int length) {

}
