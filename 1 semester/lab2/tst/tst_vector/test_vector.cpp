#include "gtest/gtest.h"
#include "vector/vector.h"


TEST(ConstructVector, BuildVectorWithDefaultConstr) {
    vector<int> v;
    EXPECT_EQ(v.size(), 0);
}

TEST(ConstructVector, BuildVectorWithLight) {
    vector<int> v1(10);
    EXPECT_ANY_THROW(vector<int> v3(-10));
    EXPECT_EQ(v1.size(), 10);
}

TEST(ConstructVector, BuildVectorWithv) {
    int v_int[4] = {1, 2, 3, 4};
    vector<int> v1(v_int, 4);
    EXPECT_EQ(v1[3], 4);
    v1.push_back(5);
    EXPECT_EQ(v1.size(), 5);
}

TEST(ConstructVector, CopyConstr) {
    int v_int[4] = {1, 2, 3, 4};
    vector<int> v1(v_int, 4);
    EXPECT_EQ(v1[3], 4);
    vector<int> v2(v1);
    EXPECT_EQ(v2[3], 4);
    vector<int> v3 = v1;
    v1[2] = 11;
    EXPECT_EQ(v3[2], 3);
}

TEST(vector, GetLight) {
    vector<int> v1(10);
    EXPECT_EQ(v1.size(), 10);
    vector<int> v2(v1);
    v2.push_back(1);
    EXPECT_EQ(v2.size(), 11);
}

TEST(vector, Empty) {
    vector<int> v1;
    EXPECT_TRUE(v1.empty());
    v1.push_back(1);
    EXPECT_EQ(v1.size(), 1);
    EXPECT_FALSE(v1.empty());
}

TEST(vector, Resize) {
    vector<int> v1(10);
    EXPECT_EQ(v1.size(), 10);
    v1.resize(12);
    EXPECT_EQ(v1.size(), 12);
    v1.resize(8);
    EXPECT_EQ(v1.size(), 8);
    v1.resize(1);
    EXPECT_EQ(v1.size(), 1);
}

TEST(vector, Sum) {
    int v_int1[4] = {1, 2, 3, 4};
    vector<int> v1(v_int1, 4);
    int v_int2[2] = {1, 2};
    vector<int> v2(v_int2, 2);
    EXPECT_EQ((v1 + v1).size(), 4);
    EXPECT_EQ((v1 + v1).at(2), 6);
    EXPECT_EQ((v1 + v2).at(3), 4);
}

TEST(vector, MultiScalar) {
    int v_int[4] = {1, 2, 3, 4};
    int s = 3;
    vector<int> v(v_int, 4);
    EXPECT_EQ((3 * v).size(), 4);
    EXPECT_EQ((3 * v).at(0), 3);
}

TEST(vector, CalculatingTheNormOfMatrix) {
    int v_int[4] = {1, 2, 3, 4};
    vector<int> v(v_int, 4);
    EXPECT_EQ(v.CalculatingTheNormOfVector(), static_cast<int>(sqrt(30)));
}

TEST(vector, ScalarMulti) {
    int v_int1[4] = {1, 2, 3, 4};
    vector<int> v1(v_int1, 4);
    int v_int2[2] = {1, 2};
    vector<int> v2(v_int2, 2);
    EXPECT_EQ(v1 * v2, 5);
}