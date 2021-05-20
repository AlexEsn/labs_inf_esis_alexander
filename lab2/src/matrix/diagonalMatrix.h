#pragma once

#include "squareMatrix.h"

template<typename T>
class DiagonalMatrix : public SquareMatrix<T>{

public:
    DiagonalMatrix()= default;
    explicit DiagonalMatrix(int length): DiagonalMatrix(new SquareMatrix<T>(length)){}
};