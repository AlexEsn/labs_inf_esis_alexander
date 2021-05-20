#include "gtest/gtest.h"
#include "list/listsequence.h"

TEST(ListSequence, GetFirst){
    int arr[4] = {1, 2, 3, 4};
    ListSequence<int> list(arr, 4);
    EXPECT_EQ(list.GetFirst(), 1);
}

TEST(ListSequence, GetLast){
    int arr[4] = {1, 2, 3, 4};
    ListSequence<int> list(arr, 4);
    EXPECT_EQ(list.GetLast(), 4);
}

TEST(ListSequence, Apped){
    int arr[4] = {1, 2, 3, 4};
    ListSequence<int> list(arr, 4);
    list.Append(10);
    EXPECT_EQ(list.GetLast(), 10);
}

TEST(ListSequence, Prepend){
    int arr[4] = {1, 2, 3, 4};
    ListSequence<int> list(arr, 4);
    list.Prepend(10);
    EXPECT_EQ(list.GetFirst(), 10);
}

TEST(ListSequence, InsertAt){
    int arr[4] = {1, 2, 3, 4};
    ListSequence<int> list(arr, 4);
    list.InsertAt(10, 2);
    EXPECT_EQ(list[2], 10);
}

TEST(ListSequence, Get){
    int arr[4] = {1, 2, 3, 4};
    ListSequence<int> list(arr, 4);
    list[2] = 5;
    EXPECT_EQ(list[2], 5);
}

TEST(ListSequence, GetSubsequence){
    int arr[4] = {1, 2, 3, 4};
    ListSequence<int> list1(arr, 4);
    EXPECT_EQ(list1.GetSubSequence(2, 3)->GetLength(), 2);
    EXPECT_EQ(list1.GetSubSequence(2, 3)->Get(0), 3);
    EXPECT_EQ(list1.GetSubSequence(2, 3)->Get(1), 4);
    ASSERT_ANY_THROW(list1.GetSubSequence(-1, 10));
}

TEST(ListSequence, Concat){
    int arr[4] = {1, 2, 3, 4};
    ListSequence<int> list1(arr, 4);
    ListSequence<int> array2(arr, 4);
    EXPECT_EQ(list1.Concat(&array2)->GetLength(), 8);
    EXPECT_EQ(list1.Concat(&array2)->Get(4), 1);
}