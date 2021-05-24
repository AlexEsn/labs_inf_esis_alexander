#include "gtest/gtest.h"
#include "arr/dynamicarray.h"

TEST(ConstructDynamicArray, BuildArrayWithDefaultConstr) {
    DynamicArray<int> arr;
    EXPECT_EQ(arr.GetLength(), 0);
}

TEST(ConstructDynamicArray, BuildArrayWithLight) {
    DynamicArray<int> arr1(10);
    ASSERT_ANY_THROW(DynamicArray<int> arr2(-10));
}

TEST(ConstructDynamicArray, BuildArrayWithArr) {
    int arr_int[4] = {1, 2, 3, 4};
    DynamicArray<int> arr1(arr_int, 4);
    EXPECT_EQ(arr1[3], 4);
    ASSERT_ANY_THROW(DynamicArray<int> arr2(arr_int, -4));
}

TEST(ConstructDynamicArray, CopyConstr) {
    int arr_int[4] = {1, 2, 3, 4};
    DynamicArray<int> arr1(arr_int, 4);
    EXPECT_EQ(arr1[3], 4);
    DynamicArray<int> arr2(arr1);
    EXPECT_EQ(arr2[3], 4);
    DynamicArray<int> arr3 = arr1;
    EXPECT_EQ(arr2[2], 3);
}

TEST(DynamicArray, GetLight) {
    DynamicArray<int> arr1(10);
    EXPECT_EQ(arr1.GetLength(), 10);
    arr1[15] = 12;
    EXPECT_EQ(arr1.GetLength(), 16);
    DynamicArray<int> arr2(arr1);
    EXPECT_EQ(arr2.GetLength(), 16);
}

TEST(DynamicArray, Resize) {
    int arr_int[4] = {1, 2, 3, 4};
    DynamicArray<int> arr(arr_int, 4);
    arr.Resize(2);
    EXPECT_EQ(arr[1], 2);
    ASSERT_ANY_THROW(arr.Resize(-10));
}

TEST(DynamicArray, Insert) {
    int arr_int[4] = {1, 3, 4, 5};
    DynamicArray<int> arr1(arr_int, 4);
    arr1.Insert(2, 2);
    EXPECT_EQ(arr1[2], 2);
}