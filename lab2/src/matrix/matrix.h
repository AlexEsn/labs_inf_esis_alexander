#pragma once

#include <stdexcept>
#include <iostream>
#include <fstream>

#include "../vector/vector.h"

template <class T>
class Matrix{

private:
    int num_rows_;
    int num_columns_;

    vector<vector<T>> elements_;

public:
    Matrix(): num_rows_(0), num_columns_(0), elements_(0){}
    Matrix(int num_rows, int num_columns) {
        Reset(num_rows, num_columns);
    }
    Matrix(const Matrix<T>& matrix){
        this->Reset(matrix.num_rows_, matrix.num_columns_);
        elements_ = matrix.elements_;
    }

    void Reset(int num_rows, int num_columns) {
        if (num_rows < 0) {
            throw std::out_of_range("num_rows must be >= 0");
        }
        if (num_columns < 0) {
            throw std::out_of_range("num_columns must be >= 0");
        }
        if (num_rows == 0 || num_columns == 0) {
            num_rows = num_columns = 0;
        }

        num_rows_ = num_rows;
        num_columns_ = num_columns;

        elements_.resize(num_rows);
        for (int i = 0; i < num_rows_; ++i) {
            elements_[i].resize(num_columns);
        }
    }
    int& At(int row, int column) {
        return elements_.at(row).at(column);
    }
    int At(int row, int column) const {
        return elements_.at(row).at(column);
    }
    int GetNumRows() const {
        return num_rows_;
    }
    int GetNumColumns() const {
        return num_columns_;
    }

    friend bool operator==(const Matrix<T>& one, const Matrix<T>& two);
    friend Matrix<T> operator+(const Matrix<T>& one, const Matrix<T>& two);
    friend std::istream& operator>>(std::istream& in, Matrix<T>& matrix);
    friend std::ostream& operator<<(std::ostream& out, const Matrix<T>& matrix);
};

template <class T>
bool operator==(const Matrix<T>& one, const Matrix<T>& two) {
    if (one.GetNumRows() != two.GetNumRows()) {
        return false;
    }

    if (one.GetNumColumns() != two.GetNumColumns()) {
        return false;
    }

    for (int row = 0; row < one.GetNumRows(); ++row) {
        for (int column = 0; column < one.GetNumColumns(); ++column) {
            if (one.At(row, column) != two.At(row, column)) {
                return false;
            }
        }
    }

    return true;
}

template <class T>
Matrix<T> operator+(const Matrix<T>& one, const Matrix<T>& two) {
    if (one.GetNumRows() != two.GetNumRows()) {
        throw std::invalid_argument("Mismatched number of rows");
    }

    if (one.GetNumColumns() != two.GetNumColumns()) {
        throw std::invalid_argument("Mismatched number of columns");
    }

    Matrix<T> result(one.GetNumRows(), one.GetNumColumns());
    for (int row = 0; row < result.GetNumRows(); ++row) {
        for (int column = 0; column < result.GetNumColumns(); ++column) {
            result.At(row, column) = one.At(row, column) + two.At(row, column);
        }
    }

    return result;
}

template <class T>
std::istream& operator>>(std::istream& in, Matrix<T>& matrix) {
    int num_rows, num_columns;
    in >> num_rows >> num_columns;

    matrix.Reset(num_rows, num_columns);
    for (int row = 0; row < num_rows; ++row) {
        for (int column = 0; column < num_columns; ++column) {
            in >> matrix.At(row, column);
        }
    }

    return in;
}

template <class T>
std::ostream& operator<<(std::ostream& out, const Matrix<T>& matrix) {
    out << matrix.GetNumRows() << " " << matrix.GetNumColumns() << std::endl;
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