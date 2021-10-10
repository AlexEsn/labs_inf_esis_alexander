#pragma once

#include "squareMatrix.h"

template<typename T>
class TriangularMatrix : public SquareMatrix<T>{

public:
    TriangularMatrix()= default;
    explicit TriangularMatrix(int length): TriangularMatrix(new SquareMatrix<T>(length)){}
};