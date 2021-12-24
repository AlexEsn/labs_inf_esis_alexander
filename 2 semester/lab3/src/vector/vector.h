#pragma once

#include "../list/listsequence.h"
#include "../arr/arraysequence.h"
#include <cmath>

template<class T>
class vector {

private:
    Sequence<T> *array_;

public:
    //Constrictor
    vector();
    explicit vector(int length);
    vector(const T *data, int length);
    vector(const vector<T> &vector);

    //Operation
    [[nodiscard]] size_t size() const;
    [[nodiscard]] bool empty() const;
    T &operator[](int index);
    T &at(int index);
    T &at(int index) const;
    void resize(int length);
    void push_back(const T &value);

    //Task operations
    template<class U>
    friend vector<U>& operator+(const vector<U>& v1, const vector<U>& v2);
    template<class U>
    friend vector<U>& operator*(U lambda, const vector<U>& v);
    template<class U>
    friend U operator*(const vector<U>& v1, const vector<U>& v2);
    T CalculatingTheNormOfVector();

    //Destructor
    ~vector();
};

#include "vector.tpp"