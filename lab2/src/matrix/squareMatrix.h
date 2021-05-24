#pragma once

#include "matrix.h"

template <class T>
class SquareMatrix : public Matrix<T>{

public:

    SquareMatrix()= default;
    explicit SquareMatrix(int length): SquareMatrix(new Matrix<T>(length, length)){};

    [[nodiscard]] int GetSize() const;
    T CalculatingTheNormOfMatrix();
    SquareMatrix<T>& operator=(const SquareMatrix<T>& matrix) {
        this->Reset(matrix.num_rows_, matrix.num_columns_);
        for (int i = 0; i < matrix.GetSize(); ++i) {
            for (int j = 0; j < matrix.GetSize(); ++j) {
                this->elements_[i][j] = matrix.elements_.at(i).at(j);
            }
        }
        return *this;
    }

    template <typename U>
    friend std::istream& operator>>(std::istream& in, SquareMatrix<U>& matrix);
    template <typename U>
    friend std::ostream& operator<<(std::ostream& out, const SquareMatrix<U>& matrix);
};

template<class T>
int SquareMatrix<T>::GetSize() const {
    return this->GetNumColumns();
}

template<class T>
T SquareMatrix<T>::CalculatingTheNormOfMatrix() {
    if (this->GetSize() != 0) {
        T result = this[0][0];
        for (int i = 0; i < this->GetSize(); ++i) {
            T tmp = 0;
            for (int j = 0; j < i + 1; ++j) {
                tmp += this[i][j];
            }
            if (tmp >= result)
                result = tmp;
        }
        return result;
    } else {
        throw std::logic_error("Error of calculations");
        return -1;
    }
}

template <class T>
std::istream& operator>>(std::istream& in, SquareMatrix<T>& matrix) {
    int size;
    in >> size;

    matrix.Reset(size, size);
    for (int row = 0; row < size; ++row) {
        for (int column = 0; column < size; ++column) {
            in >> matrix[row][column];
        }
    }

    return in;
}

template <class T>
std::ostream& operator<<(std::ostream& out, const SquareMatrix<T>& matrix) {
    out << matrix.GetSize() << std::endl;
    for (int row = 0; row < matrix.GetSize(); ++row) {
        for (int column = 0; column < matrix.GetSize(); ++column) {
            if (column > 0) {
                out << " ";
            }
            out << matrix.At(row, column);
        }
        out << std::endl;
    }

    return out;
}