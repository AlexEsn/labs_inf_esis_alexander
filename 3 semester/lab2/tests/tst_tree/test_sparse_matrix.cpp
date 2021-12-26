#include "gtest/gtest.h"
#include "tree/sparse_matrix_BTree.h"

TEST(ConstructCompressed_matrix, Constr) {
    compressed_matrix<int> matrix;
    EXPECT_EQ(matrix.size1(), 0);
    EXPECT_EQ(matrix.size2(), 0);
    EXPECT_EQ(matrix.nnz(), 0);
}

TEST(ConstructCompressed_matrix, ConstrWithRowAndColumns) {
    compressed_matrix<int> matrix(1, 2);
    EXPECT_EQ(matrix.size1(), 1);
    EXPECT_EQ(matrix.size2(), 2);
    EXPECT_EQ(matrix.nnz(), 0);
    ASSERT_ANY_THROW(compressed_matrix<int> matrix(-1, 2));
}

TEST(Compressed_matrix, resize) {
    compressed_matrix<int> matrix(1, 2);
    EXPECT_EQ(matrix.size1(), 1);
    EXPECT_EQ(matrix.size2(), 2);
    EXPECT_EQ(matrix.nnz(), 0);
    matrix.resize(1, 2, false);
    EXPECT_EQ(matrix.size1(), 1);
    EXPECT_EQ(matrix.size2(), 2);
    EXPECT_EQ(matrix.nnz(), 0);
    ASSERT_ANY_THROW(matrix.resize(-111, -2, false));
    ASSERT_ANY_THROW(matrix.resize(1, -2, false));
    ASSERT_ANY_THROW(matrix.resize(-441, 2, true));
}

TEST(Compressed_matrix, nnz) {
    compressed_matrix<int> matrix(1, 2);
    EXPECT_EQ(matrix.size1(), 1);
    EXPECT_EQ(matrix.size2(), 2);
    EXPECT_EQ(matrix.nnz(), 0);
    matrix.push_back(0, 1, 1);
    EXPECT_EQ(matrix.size1(), 1);
    EXPECT_EQ(matrix.size2(), 2);
    EXPECT_EQ(matrix.nnz(), 1);
    ASSERT_ANY_THROW(matrix.push_back(11111111, 111111, 1));
    EXPECT_EQ(matrix.size1(), 1);
    EXPECT_EQ(matrix.size2(), 2);
    EXPECT_EQ(matrix.nnz(), 1);
}

TEST(Compressed_matrix, push_back) {
    compressed_matrix<int> matrix(1, 2);
    EXPECT_EQ(matrix.size1(), 1);
    EXPECT_EQ(matrix.size2(), 2);
    EXPECT_EQ(matrix.nnz(), 0);
    matrix.push_back(0, 1, 1);
    EXPECT_EQ(matrix.size1(), 1);
    EXPECT_EQ(matrix.size2(), 2);
    EXPECT_EQ(matrix.nnz(), 1);
    ASSERT_ANY_THROW(matrix.push_back(11111, 111111, 1));
    EXPECT_EQ(matrix.size1(), 1);
    EXPECT_EQ(matrix.size2(), 2);
    EXPECT_EQ(matrix.nnz(), 1);
    ASSERT_ANY_THROW(matrix.push_back(-11, -111, 1));
    ASSERT_ANY_THROW(matrix.push_back(0, -1, 1));
    ASSERT_ANY_THROW(matrix.push_back(1, 2, 1));
}


TEST(Compressed_matrix, Operator) {
    compressed_matrix<int> matrix(1, 2);
    matrix.push_back(0, 1, 5);
    EXPECT_EQ(matrix(0, 1), 5);
    matrix(0, 1) =  6;
    EXPECT_EQ(matrix(0, 1), 6);
    EXPECT_EQ(matrix(0, 0), 0);
}