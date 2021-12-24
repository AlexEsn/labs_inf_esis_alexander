#pragma once

#include <iostream>
#include "../arr/arraysequence.h"
#include "../list/listsequence.h"

template<typename T>
void swap(T &left, T &right);

template<typename T>
void BubbleSort(Sequence<T> &base, bool (&comp)(T &left, T &right));

template<typename T>
void ShakerSort(Sequence<T> &base, bool (&comp)(T &left, T &right));

template<typename T>
void InsertionSort(Sequence<T> &base, bool (&comp)(T &left, T &right));

template<typename T>
void SelectionSort(Sequence<T> &base, bool (&comp)(T &left, T &right));

template<typename T>
void QuickSort(Sequence<T> &base, bool (&comp)(T &left, T &right), int size);

template<typename T>
void MergeSort(Sequence<T> &base, bool (&comp)(T &left, T &right), int left, int right);

#include "sort.tpp"