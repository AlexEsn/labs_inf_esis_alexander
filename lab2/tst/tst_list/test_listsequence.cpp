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