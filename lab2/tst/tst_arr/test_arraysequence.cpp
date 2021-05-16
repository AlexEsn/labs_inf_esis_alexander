#include "gtest/gtest.h"
#include "arr/arraysequence.h"

TEST(ConstructArraySequence, CopyConstr) {
    int arr_int[4] = {1, 2, 3, 4};
    ArraySequence<int> arr1(arr_int, 4);
    ArraySequence<int> arr2(arr1);
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