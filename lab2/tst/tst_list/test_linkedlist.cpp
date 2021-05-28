#include "gtest/gtest.h"
#include "list/linkedlist.h"

TEST(ConstructLinkedList, BuildArrayWithDefaultConstr) {
    LinkedList<int> list;
    EXPECT_EQ(list.GetLength(), 0);
}

TEST(ConstructLinkedList, BuildArrayWithArr) {
    int arr_int[4] = {1, 2, 3, 4};
    LinkedList<int> list1(arr_int, 4);
    LinkedList<int>::iterator it_list = list1.get_nth(3);
    EXPECT_EQ(*it_list, 4);
    list1.remove_back();
    LinkedList<int> list2(list1);
    it_list = list2.get_nth(2);
    EXPECT_EQ(*it_list, 3);
}

TEST(ConstructLinkedList, CopyConstr) {
    int arr_int[4] = {1, 2, 3, 4};
    LinkedList<int> list1(arr_int, 4);
    LinkedList<int>::iterator it_list;
    list1.remove_back();
    LinkedList<int> list2(list1);
    it_list = list2.get_nth(2);
    EXPECT_EQ(*it_list, 3);
}

TEST(LinkedList, GetLight) {
    int arr_int[4] = {1, 2, 3, 4};
    LinkedList<int> list(arr_int, 4);
    EXPECT_EQ(list.GetLength(), 4);
    list.remove_back();
    EXPECT_EQ(list.GetLength(), 3);
    list.remove_front();
    EXPECT_EQ(list.GetLength(), 2);
    list.push_back(1);
    EXPECT_EQ(list.GetLength(), 3);
}

TEST(LinkedList, IsEmpty) {
    LinkedList<int> list;
    EXPECT_TRUE(list.IsEmpty());
    list.push_back(10);
    EXPECT_FALSE(list.IsEmpty());
    list.remove_back();
    EXPECT_TRUE(list.IsEmpty());
}

TEST(LinkedList, BeginEnd) {
    int arr_int[4] = {1, 2, 3, 4};
    LinkedList<int> list(arr_int, 4);
    LinkedList<int>::iterator it = list.begin();
    for (int i = 0; it != list.end(); ++it, ++i) {
        EXPECT_EQ(arr_int[i], *it);
    }
}

TEST(LinkedList, InsertAfter) {
    LinkedList<int> list;
    list.push_back(1);
    LinkedList<int>::iterator it = list.begin();
    list.insert_after(12, it);
    EXPECT_EQ(*(++it), 12);
}

TEST(LinkedList, FindIterator) {
    int arr_int[4] = {1, 2, 3, 4};
    LinkedList<int> list(arr_int, 4);
    LinkedList<int>::iterator it1 = list.find(5);
    LinkedList<int>::iterator it2 = list.end();
    EXPECT_EQ(it1, it2);
}

TEST(LinkedList, RemoveIt) {
    int arr_int[4] = {1, 2, 3, 4};
    LinkedList<int> list(arr_int, 4);
    LinkedList<int>::iterator it = list.begin();
    list.remove_it(it);
    EXPECT_EQ(list.GetLength(), 3);
}