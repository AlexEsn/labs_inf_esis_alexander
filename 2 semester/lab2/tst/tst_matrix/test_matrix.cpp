#include "gtest/gtest.h"
#include "matrix/matrix.h"


TEST(ConstructMatrix, BuildMatrixWithDefaultConstr) {
    Matrix<int> matrix;
    EXPECT_EQ(matrix.GetNumColumns(), 0);
    EXPECT_EQ(matrix.GetNumRows(), 0);
}

TEST(ConstructMatrix, BuildMatrixWithLight) {
    Matrix<int> matrix1(10, 10);
    EXPECT_ANY_THROW(Matrix<int> matrix3(-10, 10));
    EXPECT_EQ(matrix1.GetNumColumns(), 10);
}

TEST(MatrixMetod, OperatorPlus) {
    Matrix<int> matrix1(1, 1);
    matrix1[0][0] = 5;
    Matrix<int> matrix2(1, 1);
    matrix2[0][0] = 6;
    matrix1 = matrix1 + matrix2;
    EXPECT_EQ(matrix1[0][0], 11);
}

TEST(MatrixMetod, OperatorMulti) {
    Matrix<int> matrix(1, 1);
    matrix[0][0] = 5;
    matrix = 7 * matrix;
    EXPECT_EQ(matrix[0][0], 35);
}

TEST(MatrixMetod, OperatorEqually) {
    Matrix<int> matrix1(1, 1);
    matrix1[0][0] = 5;
    Matrix<int> matrix2(1, 1);
    matrix2[0][0] = 5;
    EXPECT_TRUE(matrix1 == matrix2);
}