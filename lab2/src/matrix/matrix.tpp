
#include "matrix.h"

template<class T>
Matrix<T>::Matrix(): num_rows_(0), num_columns_(0), elements_(0) {}

template<class T>
Matrix<T>::Matrix(int num_rows, int num_columns) {
    Reset(num_rows, num_columns);
}

template<class T>
void Matrix<T>::Reset(int num_rows, int num_columns) {
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

    elements_.resize(num_rows_);
    for (int i = 0; i < num_rows_; ++i) {
        elements_[i].resize(num_columns_);
    }
}

template<class T>
int &Matrix<T>::At(int row, int column) {
    return elements_.at(row).at(column);
}

template<class T>
int Matrix<T>::At(int row, int column) const {
    return elements_.at(row).at(column);
}

template<class T>
int Matrix<T>::GetNumRows() const {
    return num_rows_;
}

template<class T>
int Matrix<T>::GetNumColumns() const {
    return num_columns_;
}

template<class T>
int Matrix<T>::GetSize() const {
    return num_rows_;
}

template<class T>
vector<T> &Matrix<T>::operator[](int i) {
    return elements_[i];
}

template<class T>
vector<T> &Matrix<T>::operator[](int i) const {
    return elements_.at(i);
}

template<class T>
Matrix<T> &Matrix<T>::operator=(const Matrix<T> &matrix) {
    this->num_rows_ = matrix.num_rows_;
    this->num_columns_ = matrix.num_columns_;
    for (int i = 0; i < matrix.num_rows_; ++i) {
        for (int j = 0; j < matrix.num_columns_; ++j) {
            this->elements_[i][j] = matrix.elements_.at(i).at(j);
        }
    }
    return *this;
}

template<class T>
T Matrix<T>::CalculatingTheNormOfMatrix() {
    if (this != nullptr && this->GetSize() != 0) {
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

template<class T>
Matrix<T> operator*(T lambda, const Matrix<T> &matrix) {
    Matrix<T> answer(matrix.num_rows_, matrix.num_columns_);
    for (int i = 0; i < matrix.GetNumRows(); ++i) {
        for (int j = 0; j < matrix.GetNumColumns(); ++j) {
            answer.elements_[i][j] = lambda * matrix.elements_.at(i).at(j);
        }
    }
    return answer;
}

template<class T>
bool operator==(const Matrix<T> &one, const Matrix<T> &two) {
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

template<class T>
Matrix<T> operator+(const Matrix<T> &one, const Matrix<T> &two) {
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

template<class T>
std::istream &operator>>(std::istream &in, Matrix<T> &matrix) {
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

template<class T>
std::ostream &operator<<(std::ostream &out, const Matrix<T> &matrix) {
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
