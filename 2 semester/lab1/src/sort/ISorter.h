#pragma once

#include "sort.h"

template<typename T>
class ISorter {
public:
    virtual void Sort(Sequence<T> *seq, bool (*comp)(const T &, const T &)) = 0;
};

template<typename T>
class MergeSorter : public ISorter<T> {
public:
    void Sort(Sequence<T> *seq, bool (*comp)(const T &, const T &)) override {
        MergeSort(*seq, comp, 0, seq->GetLength());
    }
};

template<typename T>
class QuickSorter : public ISorter<T> {
public:
    void Sort(Sequence<T> *seq, bool (*comp)(const T &, const T &)) override {
        QuickSort(*seq, comp, 0, seq->GetLength());
    }
};

template<typename T>
class BubbleSorter : public ISorter<T> {
public:
    void Sort(Sequence<T> *seq, bool (*comp)(const T &, const T &)) override {
        BubbleSort(*seq, comp);
    }
};


template<typename T>
class ShakerSorter : public ISorter<T> {
public:
    void Sort(Sequence<T> *seq, bool (*comp)(const T &, const T &)) override {
        ShakerSort(*seq, comp);
    }
};

template<typename T>
class InsertionSorter : public ISorter<T> {
public:
    void Sort(Sequence<T> *seq, bool (*comp)(const T &, const T &)) override {
        InsertionSort(*seq, comp);
    }
};

template<typename T>
class SelectionSorter : public ISorter<T> {
public:
    void Sort(Sequence<T> *seq, bool (*comp)(const T &, const T &)) override {
        SelectionSort(*seq, comp);
    }
};