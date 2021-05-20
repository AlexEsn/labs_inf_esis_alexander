
#include "listsequence.h"

template<typename T>
ListSequence<T>::ListSequence(): list_(new LinkedList<T>()) {}

template<typename T>
ListSequence<T>::ListSequence(T *data, int length) {
    list_ = new LinkedList<T>(data, length);
}

template<typename T>
ListSequence<T>::ListSequence(LinkedList <T> &list) {
    list_ = new LinkedList<T>(list);
}

template<typename T>
T &ListSequence<T>::GetFirst() {
    auto it = list_->begin();
    return *it;
}

template<typename T>
T &ListSequence<T>::GetLast() {
    auto it = list_->end();
    return *(--it);
}

template<typename T>
T &ListSequence<T>::Get(int index) {
    auto it = list_->get_nth(index);
    return *it;
}

template<typename T>
T &ListSequence<T>::Get(int index) const{
    auto it = list_->get_nth(index);
    return *it;
}

template<typename T>
size_t ListSequence<T>::GetLength() const {
    return list_->GetLength();
}

template<typename T>
void ListSequence<T>::Append(const T &value) {
    list_->push_back(value);
}

template<typename T>
void ListSequence<T>::Prepend(const T &value) {
    list_->push_front(value);
}

template<typename T>
void ListSequence<T>::InsertAt(const T &value, int index) {
    auto it = list_->get_nth(index - 1);
    list_->insert_after(value, it);
}

template<typename T>
ListSequence<T>::~ListSequence() {
    delete list_;
}

template<class T>
T &ListSequence<T>::operator[](int index) {
    return Get(index);
}

template<class T>
void ListSequence<T>::Resize(int length) {

}

template<class T>
Sequence<T> *ListSequence<T>::GetSubSequence(int start_index, int end_index) const {
    if (start_index < 0) throw std::out_of_range("negative start index");
    if (start_index >= list_->GetLength()) throw std::out_of_range("start index is more then length");
    if (end_index >= list_->GetLength()) throw std::out_of_range("end index is more then length");
    T *new_arr = new T[end_index - start_index + 1];
    for (int i = start_index; i <= end_index; ++i) {
        new_arr[i - start_index] = this->Get(i);
    }
    return new ListSequence<T>(new_arr, end_index - start_index + 1);
}

template<class T>
Sequence<T> *ListSequence<T>::Concat(Sequence<T> *seq) const {
    if (seq->GetLength() == 0 && this->list_ == nullptr) throw std::logic_error("both containers are empty");
    T *new_arr = new T[seq->GetLength() + this->GetLength()];
    for (int i = 0; i < list_->GetLength(); ++i) {
        new_arr[i] = this->Get(i);
    }
    for (int i = 0; i < seq->GetLength(); ++i) {
        new_arr[i + list_->GetLength()] = seq->Get(i);
    }
    return new ListSequence<T>(new_arr, seq->GetLength() + this->GetLength());
}
