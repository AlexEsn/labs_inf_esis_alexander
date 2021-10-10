#pragma once

#include <fstream>

#include "../vector/vector.h"

template <class T>
class Matrix{

protected:
    int num_rows_;
    int num_columns_;
    vector<vector<T>> elements_;

public:
    Matrix();
    Matrix(int num_rows, int num_columns);

    void Reset(int num_rows, int num_columns);
    int& At(int row, int column);
    [[nodiscard]] int At(int row, int column) const;
    [[nodiscard]] int GetNumRows() const;
    [[nodiscard]] int GetNumColumns() const;
    vector<T>& operator[] (int i);
    vector<T>& operator[] (int i) const;

    Matrix<T>& operator=(const Matrix<T>& matrix);

    template <typename U>
    friend Matrix<U> operator+(const Matrix<U>& one, const Matrix<U>& two);
    template <typename U>
    friend bool operator==(const Matrix<U>& one, const Matrix<U>& two);
    template <typename U>
    friend std::istream& operator>>(std::istream& in, Matrix<U>& matrix);
    template <typename U>
    friend std::ostream& operator<<(std::ostream& out, const Matrix<U>& matrix);
    template <class U>
    friend Matrix<U> operator*(U lambda, const Matrix<U>& matrix);
};

#include "matrix.tpp"