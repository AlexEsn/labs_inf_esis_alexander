#include "gtest/gtest.h"
#include "sort/sort.h"

struct My_Struct{
public:
    int _sort_item;
};

bool comp(int &left, int &right) {
    return left < right;
}

bool comp(My_Struct &left, My_Struct &right) {
    return left._sort_item < right._sort_item;
}

int rand_arr[] = {4, 5, 1, 3, 2};
int revers_arr[] = {5, 4 , 3, 2, 1};
int arr[] = {1, 2, 3, 4, 5};
int empty_arr[] = {};

TEST(RandomArr, BubbleSort) {
    Sequence<int> *base_list = new ListSequence<int>;
    for (int & i : rand_arr)
        base_list->Append(i);
    BubbleSort(*base_list, comp);
    for (int i = 0; i < base_list->GetLength();i++)
        EXPECT_EQ((*base_list)[i], arr[i]);
    Sequence<int> *base_arr = new ArraySequence<int>;
    for (int & i : rand_arr)
        base_arr->Append(i);
    BubbleSort(*base_arr, comp);
    for (int i = 0; i < base_arr->GetLength();i++)
        EXPECT_EQ((*base_arr)[i], arr[i]);
}

TEST(Arr, BubbleSort) {
    Sequence<int> *base_list = new ListSequence<int>;
    for (int & i : arr)
        base_list->Append(i);
    BubbleSort(*base_list, comp);
    for (int i = 0; i < base_list->GetLength();i++)
        EXPECT_EQ((*base_list)[i], arr[i]);
    Sequence<int> *base_arr = new ArraySequence<int>;
    for (int & i : arr)
        base_arr->Append(i);
    BubbleSort(*base_arr, comp);
    for (int i = 0; i < base_arr->GetLength();i++)
        EXPECT_EQ((*base_arr)[i], arr[i]);
}

TEST(Revers_Arr, BubbleSort) {
    Sequence<int> *base_list = new ListSequence<int>;
    for (int & i : revers_arr)
        base_list->Append(i);
    BubbleSort(*base_list, comp);
    for (int i = 0; i < base_list->GetLength();i++)
        EXPECT_EQ((*base_list)[i], arr[i]);
    Sequence<int> *base_arr = new ArraySequence<int>;
    for (int & i : revers_arr)
        base_arr->Append(i);
    BubbleSort(*base_arr, comp);
    for (int i = 0; i < base_arr->GetLength();i++)
        EXPECT_EQ((*base_arr)[i], arr[i]);
}

TEST(Empty_Arr, BubbleSort) {
    Sequence<int> *base_list = new ListSequence<int>;
    for (int & i : empty_arr)
        base_list->Append(i);
    BubbleSort(*base_list, comp);
    EXPECT_EQ(base_list->GetLength(), 0);
    Sequence<int> *base_arr = new ArraySequence<int>;
    for (int & i : empty_arr)
        base_arr->Append(i);
    BubbleSort(*base_arr, comp);
    EXPECT_EQ(base_arr->GetLength(), 0);
}

TEST(Sort_My_Struct, BubbleSort) {
    Sequence<My_Struct> *base_list = new ListSequence<My_Struct>;
    for (int & i : rand_arr){
        My_Struct item = {i};
        base_list->Append(item);
    }
    BubbleSort(*base_list, comp);
    for (int i = 0; i < base_list->GetLength();i++)
        EXPECT_EQ((*base_list)[i]._sort_item, arr[i]);
    Sequence<My_Struct> *base_arr = new ArraySequence<My_Struct>;
    for (int & i : rand_arr){
        My_Struct item = {i};
        base_arr->Append(item);
    }
    BubbleSort(*base_arr, comp);
    for (int i = 0; i < base_arr->GetLength();i++)
        EXPECT_EQ((*base_arr)[i]._sort_item, arr[i]);
}

TEST(RandomArr, ShakerSort) {
    Sequence<int> *base_list = new ListSequence<int>;
    for (int & i : rand_arr)
        base_list->Append(i);
    ShakerSort(*base_list, comp);
    for (int i = 0; i < base_list->GetLength();i++)
        EXPECT_EQ((*base_list)[i], arr[i]);
    Sequence<int> *base_arr = new ArraySequence<int>;
    for (int & i : rand_arr)
        base_arr->Append(i);
    ShakerSort(*base_arr, comp);
    for (int i = 0; i < base_arr->GetLength();i++)
        EXPECT_EQ((*base_arr)[i], arr[i]);
}

TEST(Arr, ShakerSort) {
    Sequence<int> *base_list = new ListSequence<int>;
    for (int & i : arr)
        base_list->Append(i);
    ShakerSort(*base_list, comp);
    for (int i = 0; i < base_list->GetLength();i++)
        EXPECT_EQ((*base_list)[i], arr[i]);
    Sequence<int> *base_arr = new ArraySequence<int>;
    for (int & i : arr)
        base_arr->Append(i);
    ShakerSort(*base_arr, comp);
    for (int i = 0; i < base_arr->GetLength();i++)
        EXPECT_EQ((*base_arr)[i], arr[i]);
}

TEST(Revers_Arr, ShakerSort) {
    Sequence<int> *base_list = new ListSequence<int>;
    for (int & i : revers_arr)
        base_list->Append(i);
    ShakerSort(*base_list, comp);
    for (int i = 0; i < base_list->GetLength();i++)
        EXPECT_EQ((*base_list)[i], arr[i]);
    Sequence<int> *base_arr = new ArraySequence<int>;
    for (int & i : revers_arr)
        base_arr->Append(i);
    ShakerSort(*base_arr, comp);
    for (int i = 0; i < base_arr->GetLength();i++)
        EXPECT_EQ((*base_arr)[i], arr[i]);
}

TEST(Empty_Arr, ShakerSort) {
    Sequence<int> *base_list = new ListSequence<int>;
    for (int & i : empty_arr)
        base_list->Append(i);
    ShakerSort(*base_list, comp);
    EXPECT_EQ(base_list->GetLength(), 0);
    Sequence<int> *base_arr = new ArraySequence<int>;
    for (int & i : empty_arr)
        base_arr->Append(i);
    ShakerSort(*base_arr, comp);
    EXPECT_EQ(base_arr->GetLength(), 0);
}

TEST(Sort_My_Struct, ShakerSort) {
    Sequence<My_Struct> *base_list = new ListSequence<My_Struct>;
    for (int & i : rand_arr){
        My_Struct item = {i};
        base_list->Append(item);
    }
    ShakerSort(*base_list, comp);
    for (int i = 0; i < base_list->GetLength();i++)
        EXPECT_EQ((*base_list)[i]._sort_item, arr[i]);
    Sequence<My_Struct> *base_arr = new ArraySequence<My_Struct>;
    for (int & i : rand_arr){
        My_Struct item = {i};
        base_arr->Append(item);
    }
    ShakerSort(*base_arr, comp);
    for (int i = 0; i < base_arr->GetLength();i++)
        EXPECT_EQ((*base_arr)[i]._sort_item, arr[i]);
}

TEST(RandomArr, InsertionSort) {
    Sequence<int> *base_list = new ListSequence<int>;
    for (int & i : rand_arr)
        base_list->Append(i);
    InsertionSort(*base_list, comp);
    for (int i = 0; i < base_list->GetLength();i++)
        EXPECT_EQ((*base_list)[i], arr[i]);
    Sequence<int> *base_arr = new ArraySequence<int>;
    for (int & i : rand_arr)
        base_arr->Append(i);
    InsertionSort(*base_arr, comp);
    for (int i = 0; i < base_arr->GetLength();i++)
        EXPECT_EQ((*base_arr)[i], arr[i]);
}

TEST(Arr, InsertionSort) {
    Sequence<int> *base_list = new ListSequence<int>;
    for (int & i : arr)
        base_list->Append(i);
    InsertionSort(*base_list, comp);
    for (int i = 0; i < base_list->GetLength();i++)
        EXPECT_EQ((*base_list)[i], arr[i]);
    Sequence<int> *base_arr = new ArraySequence<int>;
    for (int & i : arr)
        base_arr->Append(i);
    InsertionSort(*base_arr, comp);
    for (int i = 0; i < base_arr->GetLength();i++)
        EXPECT_EQ((*base_arr)[i], arr[i]);
}

TEST(Revers_Arr, InsertionSort) {
    Sequence<int> *base_list = new ListSequence<int>;
    for (int & i : revers_arr)
        base_list->Append(i);
    InsertionSort(*base_list, comp);
    for (int i = 0; i < base_list->GetLength();i++)
        EXPECT_EQ((*base_list)[i], arr[i]);
    Sequence<int> *base_arr = new ArraySequence<int>;
    for (int & i : revers_arr)
        base_arr->Append(i);
    InsertionSort(*base_arr, comp);
    for (int i = 0; i < base_arr->GetLength();i++)
        EXPECT_EQ((*base_arr)[i], arr[i]);
}

TEST(Empty_Arr, InsertionSort) {
    Sequence<int> *base_list = new ListSequence<int>;
    for (int & i : empty_arr)
        base_list->Append(i);
    InsertionSort(*base_list, comp);
    EXPECT_EQ(base_list->GetLength(), 0);
    Sequence<int> *base_arr = new ArraySequence<int>;
    for (int & i : empty_arr)
        base_arr->Append(i);
    InsertionSort(*base_arr, comp);
    EXPECT_EQ(base_arr->GetLength(), 0);
}

TEST(Sort_My_Struct, InsertionSort) {
    Sequence<My_Struct> *base_list = new ListSequence<My_Struct>;
    for (int & i : rand_arr){
        My_Struct item = {i};
        base_list->Append(item);
    }
    InsertionSort(*base_list, comp);
    for (int i = 0; i < base_list->GetLength();i++)
        EXPECT_EQ((*base_list)[i]._sort_item, arr[i]);
    Sequence<My_Struct> *base_arr = new ArraySequence<My_Struct>;
    for (int & i : rand_arr){
        My_Struct item = {i};
        base_arr->Append(item);
    }
    InsertionSort(*base_arr, comp);
    for (int i = 0; i < base_arr->GetLength();i++)
        EXPECT_EQ((*base_arr)[i]._sort_item, arr[i]);
}

TEST(RandomArr, SelectionSort) {
    Sequence<int> *base_list = new ListSequence<int>;
    for (int & i : rand_arr)
        base_list->Append(i);
    SelectionSort(*base_list, comp);
    for (int i = 0; i < base_list->GetLength();i++)
        EXPECT_EQ((*base_list)[i], arr[i]);
    Sequence<int> *base_arr = new ArraySequence<int>;
    for (int & i : rand_arr)
        base_arr->Append(i);
    SelectionSort(*base_arr, comp);
    for (int i = 0; i < base_arr->GetLength();i++)
        EXPECT_EQ((*base_arr)[i], arr[i]);
}

TEST(Arr, SelectionSort) {
    Sequence<int> *base_list = new ListSequence<int>;
    for (int & i : arr)
        base_list->Append(i);
    SelectionSort(*base_list, comp);
    for (int i = 0; i < base_list->GetLength();i++)
        EXPECT_EQ((*base_list)[i], arr[i]);
    Sequence<int> *base_arr = new ArraySequence<int>;
    for (int & i : arr)
        base_arr->Append(i);
    SelectionSort(*base_arr, comp);
    for (int i = 0; i < base_arr->GetLength();i++)
        EXPECT_EQ((*base_arr)[i], arr[i]);
}

TEST(Revers_Arr, SelectionSort) {
    Sequence<int> *base_list = new ListSequence<int>;
    for (int & i : revers_arr)
        base_list->Append(i);
    SelectionSort(*base_list, comp);
    for (int i = 0; i < base_list->GetLength();i++)
        EXPECT_EQ((*base_list)[i], arr[i]);
    Sequence<int> *base_arr = new ArraySequence<int>;
    for (int & i : revers_arr)
        base_arr->Append(i);
    SelectionSort(*base_arr, comp);
    for (int i = 0; i < base_arr->GetLength();i++)
        EXPECT_EQ((*base_arr)[i], arr[i]);
}

TEST(Empty_Arr, SelectionSort) {
    Sequence<int> *base_list = new ListSequence<int>;
    for (int & i : empty_arr)
        base_list->Append(i);
    SelectionSort(*base_list, comp);
    EXPECT_EQ(base_list->GetLength(), 0);
    Sequence<int> *base_arr = new ArraySequence<int>;
    for (int & i : empty_arr)
        base_arr->Append(i);
    SelectionSort(*base_arr, comp);
    EXPECT_EQ(base_arr->GetLength(), 0);
}

TEST(Sort_My_Struct, SelectionSort) {
    Sequence<My_Struct> *base_list = new ListSequence<My_Struct>;
    for (int & i : rand_arr){
        My_Struct item = {i};
        base_list->Append(item);
    }
    SelectionSort(*base_list, comp);
    for (int i = 0; i < base_list->GetLength();i++)
        EXPECT_EQ((*base_list)[i]._sort_item, arr[i]);
    Sequence<My_Struct> *base_arr = new ArraySequence<My_Struct>;
    for (int & i : rand_arr){
        My_Struct item = {i};
        base_arr->Append(item);
    }
    SelectionSort(*base_arr, comp);
    for (int i = 0; i < base_arr->GetLength();i++)
        EXPECT_EQ((*base_arr)[i]._sort_item, arr[i]);
}

TEST(RandomArr, QuickSort) {
    Sequence<int> *base_list = new ListSequence<int>;
    for (int & i : rand_arr)
        base_list->Append(i);
    QuickSort(*base_list, comp, 0, base_list->GetLength() - 1);
    for (int i = 0; i < base_list->GetLength();i++)
        EXPECT_EQ((*base_list)[i], arr[i]);
    Sequence<int> *base_arr = new ArraySequence<int>;
    for (int & i : rand_arr)
        base_arr->Append(i);
    QuickSort(*base_arr, comp, 0, base_list->GetLength() - 1);
    for (int i = 0; i < base_arr->GetLength();i++)
        EXPECT_EQ((*base_arr)[i], arr[i]);
}

TEST(Arr, QuickSort) {
    Sequence<int> *base_list = new ListSequence<int>;
    for (int & i : arr)
        base_list->Append(i);
    QuickSort(*base_list, comp, 0, base_list->GetLength() - 1);
    for (int i = 0; i < base_list->GetLength();i++)
        EXPECT_EQ((*base_list)[i], arr[i]);
    Sequence<int> *base_arr = new ArraySequence<int>;
    for (int & i : arr)
        base_arr->Append(i);
    QuickSort(*base_arr, comp, 0, base_list->GetLength() - 1);
    for (int i = 0; i < base_arr->GetLength();i++)
        EXPECT_EQ((*base_arr)[i], arr[i]);
}

TEST(Revers_Arr, QuickSort) {
    Sequence<int> *base_list = new ListSequence<int>;
    for (int & i : revers_arr)
        base_list->Append(i);
    QuickSort(*base_list, comp, 0, base_list->GetLength() - 1);
    for (int i = 0; i < base_list->GetLength();i++)
        EXPECT_EQ((*base_list)[i], arr[i]);
    Sequence<int> *base_arr = new ArraySequence<int>;
    for (int & i : revers_arr)
        base_arr->Append(i);
    QuickSort(*base_arr, comp, 0, base_list->GetLength() - 1);
    for (int i = 0; i < base_arr->GetLength();i++)
        EXPECT_EQ((*base_arr)[i], arr[i]);
}

TEST(Empty_Arr, QuickSort) {
    Sequence<int> *base_list = new ListSequence<int>;
    for (int & i : empty_arr)
        base_list->Append(i);
    QuickSort(*base_list, comp, 0, base_list->GetLength() - 1);
    EXPECT_EQ(base_list->GetLength(), 0);
    Sequence<int> *base_arr = new ArraySequence<int>;
    for (int & i : empty_arr)
        base_arr->Append(i);
    QuickSort(*base_arr, comp, 0, base_list->GetLength() - 1);
    EXPECT_EQ(base_arr->GetLength(), 0);
}

TEST(Sort_My_Struct, QuickSort) {
    Sequence<My_Struct> *base_list = new ListSequence<My_Struct>;
    for (int & i : rand_arr){
        My_Struct item = {i};
        base_list->Append(item);
    }
    QuickSort(*base_list, comp, 0, base_list->GetLength() - 1);
    for (int i = 0; i < base_list->GetLength();i++)
        EXPECT_EQ((*base_list)[i]._sort_item, arr[i]);
    Sequence<My_Struct> *base_arr = new ArraySequence<My_Struct>;
    for (int & i : rand_arr){
        My_Struct item = {i};
        base_arr->Append(item);
    }
    QuickSort(*base_arr, comp, 0, base_list->GetLength() - 1);
    for (int i = 0; i < base_arr->GetLength();i++)
        EXPECT_EQ((*base_arr)[i]._sort_item, arr[i]);
}

TEST(RandomArr, MergeSort) {
    Sequence<int> *base_list = new ListSequence<int>;
    for (int & i : rand_arr)
        base_list->Append(i);
    MergeSort(*base_list, comp, 0, base_list->GetLength() - 1);
    for (int i = 0; i < base_list->GetLength();i++)
        EXPECT_EQ((*base_list)[i], arr[i]);
    Sequence<int> *base_arr = new ArraySequence<int>;
    for (int & i : rand_arr)
        base_arr->Append(i);
    MergeSort(*base_arr, comp, 0, base_list->GetLength() - 1);
    for (int i = 0; i < base_arr->GetLength();i++)
        EXPECT_EQ((*base_arr)[i], arr[i]);
}

TEST(Arr, MergeSort) {
    Sequence<int> *base_list = new ListSequence<int>;
    for (int & i : arr)
        base_list->Append(i);
    MergeSort(*base_list, comp, 0, base_list->GetLength() - 1);
    for (int i = 0; i < base_list->GetLength();i++)
        EXPECT_EQ((*base_list)[i], arr[i]);
    Sequence<int> *base_arr = new ArraySequence<int>;
    for (int & i : arr)
        base_arr->Append(i);
    MergeSort(*base_arr, comp, 0, base_list->GetLength() - 1);
    for (int i = 0; i < base_arr->GetLength();i++)
        EXPECT_EQ((*base_arr)[i], arr[i]);
}

TEST(Revers_Arr, MergeSort) {
    Sequence<int> *base_list = new ListSequence<int>;
    for (int & i : revers_arr)
        base_list->Append(i);
    MergeSort(*base_list, comp, 0, base_list->GetLength() - 1);
    for (int i = 0; i < base_list->GetLength();i++)
        EXPECT_EQ((*base_list)[i], arr[i]);
    Sequence<int> *base_arr = new ArraySequence<int>;
    for (int & i : revers_arr)
        base_arr->Append(i);
    MergeSort(*base_arr, comp, 0, base_list->GetLength() - 1);
    for (int i = 0; i < base_arr->GetLength();i++)
        EXPECT_EQ((*base_arr)[i], arr[i]);
}

TEST(Sort_My_Struct, MergeSort) {
    Sequence<My_Struct> *base_list = new ListSequence<My_Struct>;
    for (int & i : rand_arr){
        My_Struct item = {i};
        base_list->Append(item);
    }
    MergeSort(*base_list, comp, 0, base_list->GetLength() - 1);
    for (int i = 0; i < base_list->GetLength();i++)
        EXPECT_EQ((*base_list)[i]._sort_item, arr[i]);
    Sequence<My_Struct> *base_arr = new ArraySequence<My_Struct>;
    for (int & i : rand_arr){
        My_Struct item = {i};
        base_arr->Append(item);
    }
    MergeSort(*base_arr, comp, 0, base_list->GetLength() - 1);
    for (int i = 0; i < base_arr->GetLength();i++)
        EXPECT_EQ((*base_arr)[i]._sort_item, arr[i]);
}