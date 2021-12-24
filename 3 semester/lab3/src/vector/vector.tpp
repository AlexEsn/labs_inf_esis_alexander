
#include "vector.h"

template<class T>
vector<T>::vector() :
        array_(new ArraySequence<T>) {}

template<typename T>
vector<T>::vector(int length):
        array_(new ArraySequence<T>(length)) {}

template<class T>
vector<T>::vector(const T *data, int length):
        array_(new ArraySequence<T>(data, length)) {}

template<class T>
T &vector<T>::operator[](int index) {
    if (index >= this->size())
        throw std::out_of_range("out of range");
    return array_->Get(index);
}

template<class T>
T &vector<T>::at(int index) {
    if (index >= this->size())
        throw std::out_of_range("out of range");
    return array_->Get(index);
}

template<class T>
T &vector<T>::at(int index) const {
    if (index >= this->size())
        throw std::out_of_range("out of range");
    return array_->Get(index);
}

template<class T>
void vector<T>::push_back(const T &value) {
    array_->Append(value);
}

template<class T>
vector<T>::vector(const vector<T> &vector):
        array_(new ArraySequence<T>(*((ArraySequence<T> *) vector.array_))) {}

template<class T>
vector<T>::~vector() {
    delete (ArraySequence<T> *) array_;
}

template<typename T>
size_t vector<T>::size() const {
    return array_->GetLength();
}

template<class T>
bool vector<T>::empty() const {
    return (array_->GetLength() == 0);
}

template<class T>
void vector<T>::resize(int length) {
    array_->Resize(length);
}

template<class T>
vector<T> &operator+(const vector<T> &v1, const vector<T> &v2) {
    int size_max = std::max(v1.size(), v2.size());
    int size_min = std::min(v1.size(), v2.size());
    T *v3_data = new T[size_max];
    for (int i = 0; i < size_max; ++i) {
        if (i < size_min) v3_data[i] = v1.array_->Get(i) + v2.array_->Get(i);
        else if (v1.size() > v2.size()) v3_data[i] = v1.array_->Get(i);
        else v3_data[i] = v2.array_->Get(i);
    }
    return *(new vector<T>(v3_data, size_max));
}

template<class T>
vector<T> &operator*(T lambda, const vector<T> &v) {
    T *new_data = new T[v.size()];
    for (int i = 0; i < v.size(); ++i) {
        new_data[i] = lambda * v.at(i);
    }
    return *(new vector<T>(new_data, v.size()));
}

template<class T>
T operator*(const vector<T> &v1, const vector<T> &v2) {
    int size_min = std::min(v1.size(), v2.size());
    T answer = 0;
    for (int i = 0; i < size_min; ++i) {
        answer += v1.at(i) * v2.at(i);
    }
    return answer;
}

template<class T>
T vector<T>::CalculatingTheNormOfVector() {
    T norma = 0;
    for (int i = 0; i < this->size(); ++i) {
        norma += this->at(i) * this->at(i);
    }
    return sqrt(norma);
}