#pragma once

#include "squareMatrix.h"

template<typename T>
class DiagonalMatrix : public SquareMatrix<T>{

public:
    DiagonalMatrix()= default;
    explicit DiagonalMatrix(int length): DiagonalMatrix(new SquareMatrix<T>(length)){}

    template <typename U>
    friend std::istream& operator>>(std::istream& in, DiagonalMatrix<U>& matrix);
};

template <class T>
std::istream& operator>>(std::istream& in, DiagonalMatrix<T>& matrix) {
    int size;
    in >> size;

    matrix.Reset(size, size);
    for (int row = 0; row < size; ++row) {
        for (int column = 0; column < size; ++column) {
            if(row == column) in >> matrix[row][column];
            else matrix[row][column] = 0;
        }
    }

    return in;
}