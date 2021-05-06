#include "listsequence.h"

template<typename T>
ListSequence<T>::ListSequence(): _list(new LinkedList <T>()) {}

template<typename T>
ListSequence<T>::ListSequence(T *data, int count)
{
    _list = new LinkedList<T>(data, count);
}

template<typename T>
ListSequence<T>::ListSequence(LinkedList<T> &list)
{
    _list = new LinkedList<T>(list);
}

template<typename T>
T &ListSequence<T>::GetFirst(){
    return _list->front();
}

template<typename T>
T &ListSequence<T>::GetLast(){
    return _list->back();
}

template<typename T>
T &ListSequence<T>::Get(int index)
{

}

template<typename T>
Sequence<T> *ListSequence<T>::GetSubSequence(int start_index, int end_index) const
{

}

template<typename T>
int ListSequence<T>::GetLength() const {
    std::cout << "i am from ListSequence implementation of GetLength() method" << std::endl; //look at custom.h
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
    _list->InsertAt(value, index);
}

template<typename T>
Sequence<T> *ListSequence<T>::Concat(Sequence<T> *seq) const
{

}

template<typename T>
ListSequence<T>::~ListSequence()
{
    delete _list;
}

