#include "gtest/gtest.h"
#include "matrix/matrix.h"


TEST(ConstructMatrix, BuildMatrixWithDefaultConstr) {
    Matrix<int> matrix;
    EXPECT_EQ(matrix.GetNumColumns(), 0);
    EXPECT_EQ(matrix.GetNumRows(), 0);
}

TEST(ConstructMatrix, BuildMatrixWithLight) {
    Matrix<int> matrix1(10, 10);
    try {
        Matrix<int> matrix3(-10, 10);
    }
    catch (std::exception &e) {
        EXPECT_EQ(e.what(), std::string("num_rows must be >= 0"));
    }
    EXPECT_EQ(matrix1.GetNumColumns(), 10);
}

TEST(ConstructMatrix, CopyConstr) {
    Matrix<int> matrix1(10, 10);
    EXPECT_EQ(matrix1.GetNumRows(), 10);
    Matrix<int> matrix2(matrix1);
    matrix1.Reset(1, 1);
    EXPECT_EQ(matrix2.GetNumRows(), 10);
}