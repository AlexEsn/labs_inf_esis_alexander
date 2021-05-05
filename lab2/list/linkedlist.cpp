#include "linkedlist.h"

template<typename T>
LinkedList<T>::LinkedList()
{
    _length = 0;
    _head = nullptr;
}

template<typename T>
LinkedList<T>::LinkedList(T *data, int count) : LinkedList()
{
    for (int i = 0; i < count; i++)
        push_back(data[i]);
}

template<typename T>
LinkedList<T>::LinkedList(const LinkedList<T> &list)
{
    Node *node = list._head->pNext;
    for (int i = 0; i < list._length; i++)
        InsertAt(node->data, i);
}

template<typename T>
T &LinkedList<T>::front() const
{

}

template<typename T>
T &LinkedList<T>::back() const
{

}

template<typename T>
void LinkedList<T>::pop_front()
{

}

template<typename T>
void LinkedList<T>::pop_back()
{

}

template<typename T>
void LinkedList<T>::clear()
{
    while (_length)
        pop_front();
}

template<typename T>
LinkedList<T> *LinkedList<T>::GetSubList(int start_index, int end_index) const
{

}

template<typename T>
int LinkedList<T>::GetLength() const {
    return _length;
}

template<typename T>
void LinkedList<T>::push_front(const T &data)
{

}

template<typename T>
void LinkedList<T>::push_back(const T &data)
{

}

template<typename T>
void LinkedList<T>::InsertAt(const T &data, int index)
{

}

template<typename T>
LinkedList<T> *LinkedList<T>::Concat(LinkedList<T> *list) const
{

}

template<typename T>
LinkedList<T>::~LinkedList()
{
    clear();
}


