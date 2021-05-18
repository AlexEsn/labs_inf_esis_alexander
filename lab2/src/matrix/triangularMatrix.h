#pragma once

#include "matrix.h"

template<typename T>
class TriangularMatrix : Matrix<T>{

public:
    TriangularMatrix()= default;
    explicit TriangularMatrix(int length): TriangularMatrix(new Matrix<T>(length, length)){}

    template<typename U>
    friend std::istream& operator>>(std::istream& in, TriangularMatrix<U>& matrix);
    template<typename U>
    friend std::ostream& operator<<(std::ostream& out, const TriangularMatrix<U>& matrix);
};

template <class T>
std::istream& operator>>(std::istream& in, TriangularMatrix<T>& matrix) {
    int size;
    in >> size;

    matrix.Reset(size, size);
    for (int row = 0; row < size; ++row) {
        for (int column = 0; column < size; ++column) {
            in >> matrix.At(row, column);
        }
    }

    return in;
}

template <class T>
std::ostream& operator<<(std::ostream& out, const TriangularMatrix<T>& matrix) {
    out << matrix.GetNumColumns() << std::endl;
    for (int row = 0; row < matrix.GetNumRows(); ++row) {
        for (int column = 0; column < matrix.GetNumColumns(); ++column) {
            if (column > 0) {
                out << " ";
            }
            out << matrix.At(row, column);
        }
        out << std::endl;
    }

    return out;
}