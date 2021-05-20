#include "gtest/gtest.h"
#include "arr/arraysequence.h"

TEST(ConstructArraySequence, Constr) {
    int arr_int[4] = {1, 2, 3, 4};
    ASSERT_ANY_THROW(ArraySequence<int> arr1(-10));
    ASSERT_ANY_THROW(ArraySequence<int> arr1(arr_int, -10));
}

TEST(ConstructArraySequence, CopyConstr) {
    int arr_int[4] = {1, 2, 3, 4};
    ArraySequence<int> arr1(arr_int, 4);
    ArraySequence<int> arr2(arr1);
    arr1[2] = 9;
    EXPECT_EQ(arr2[2], 3);
}

TEST(ArraySequence, GetFirst){
    int arr[4] = {1, 2, 3, 4};
    ArraySequence<int> array(arr, 4);
    EXPECT_EQ(array.GetFirst(), 1);
}

TEST(ArraySequence, GetLast){
    int arr[4] = {1, 2, 3, 4};
    ArraySequence<int> array(arr, 4);
    EXPECT_EQ(array.GetLast(), 4);
}

TEST(ArraySequence, Apped){
    int arr[4] = {1, 2, 3, 4};
    ArraySequence<int> array(arr, 4);
    array.Append(10);
    EXPECT_EQ(array[0], 10);
}

TEST(ArraySequence, Prepend){
    int arr[4] = {1, 2, 3, 4};
    ArraySequence<int> array(arr, 4);
    array.Prepend(10);
    EXPECT_EQ(array[array.GetLength() - 1], 10);
}

TEST(ArraySequence, InsertAt){
    int arr[4] = {1, 2, 3, 4};
    ArraySequence<int> array(arr, 4);
    array.InsertAt(10, 2);
    EXPECT_EQ(array[2], 10);
}

TEST(ArraySequence, Get){
    int arr[4] = {1, 2, 3, 4};
    ArraySequence<int> array(arr, 4);
    array[2] = 22;
    EXPECT_EQ(array[2], 22);
}

TEST(ArraySequence, GetSubsequence){
    int arr[4] = {1, 2, 3, 4};
    ArraySequence<int> array1(arr, 4);
    EXPECT_EQ(array1.GetSubSequence(2, 3)->GetLength(), 2);
    EXPECT_EQ(array1.GetSubSequence(2, 3)->Get(0), 3);
    EXPECT_EQ(array1.GetSubSequence(2, 3)->Get(1), 4);
    ASSERT_ANY_THROW(array1.GetSubSequence(-1, 10));
}

TEST(ArraySequence, Concat){
    int arr[4] = {1, 2, 3, 4};
    ArraySequence<int> array1(arr, 4);
    ArraySequence<int> array2(arr, 4);
    EXPECT_EQ(array1.Concat(&array2)->GetLength(), 8);
    EXPECT_EQ(array1.Concat(&array2)->Get(4), 1);
}