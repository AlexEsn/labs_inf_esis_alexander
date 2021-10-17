#include "seq/sequence.h"
#include "arr/arraysequence.h"
#include "list/listsequence.h"
#include <random>

template<typename T>
void swap(T &first, T &second) {
    T temp = first;
    first = second;
    second = temp;
}

template<typename T>
void BubbleSort(Sequence<T> &base, bool (&comp)(T &left, T &right)) {
    for (int i = 0; i < base.GetLength(); ++i) {
        for (int j = 0; j < base.GetLength() - 1; ++j) {
            if (comp(base[j], base[j + 1])) swap(base[j], base[j + 1]);
        }
    }
}

template<typename T>
void ShakerSort(Sequence<T> &base, bool (&comp)(T &left, T &right)) {
    int left = 0, right = base.GetLength() - 1, control, numOfIter = 0;
    while (left < right) {
        for (int i = left; i < right; ++i, numOfIter++)
            if (comp(base[i], base[i + 1])){
                swap(base[i], base[i + 1]);
                control = i;
            }
        right = control;
        for (int i = right; i > left; --i, numOfIter++)
            if (!comp(base[i], base[i - 1])){
                swap(base[i], base[i - 1]);
                control = i;
            }
        left = control;
    }
    std::cout << numOfIter << std::endl;
}

template<typename T>
void InsertionSort(Sequence<T> &base, bool (&comp)(T &left, T &right)){
    for (int i = 1; i < base.GetLength(); ++i) {
        for (int j = i - 1; j >= 0; --j) {
            std::cout << *(dynamic_cast<ListSequence<int>*>(&base)) << std::endl;
            if(comp(base[i], base[j])){
                T temp = base[i];
                for (int k = i; k >= j ; --k) {
                    swap(base[k], base[k - 1]);
                }
                base[j] = temp;
            }
        }
    }

}




bool comp(int &left, int &right) {
    return left < right;
}

int main() {

    Sequence<int> *arr = new ListSequence<int>;
    srand(time(nullptr));
    for (int i = 0; i < 5; ++i) {
        arr->Append(random() % 100);
    }
    std::cout << *(dynamic_cast<ListSequence<int>*>(arr)) << std::endl;

    InsertionSort(*arr, comp);

    std::cout << *(dynamic_cast<ListSequence<int>*>(arr)) << std::endl;

    return 0;
}