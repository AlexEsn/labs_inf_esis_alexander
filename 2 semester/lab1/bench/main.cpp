#include "benchmark/benchmark.h"
#include "sort/sort.h"
#include <vector>
#include <algorithm>

#define MIN 2                       //initial power of two
#define MAX 16                      //final power of two

#define RANDOM 1
#define REVERSE 1
#define SEQ 1                       //0 for Arr and 1 for List

bool comp(int &left, int &right) {
    return left < right;
}

static void BM_BubbleSort(benchmark::State &state) {

    for (auto _: state) {

        state.PauseTiming();

        srand(time(nullptr));

#if SEQ == 0
        Sequence<int> *arr = new ArraySequence<int>;
#else
        Sequence<int> *arr = new ListSequence<int>;
#endif

#if RANDOM
        for (int i = 0; i < state.range(); i++)
            arr->Append(rand());
#else
#if REVERSE
        for (int i = 0; i < state.range(); i++)
            arr->Append(i);

#else
        for (int i = state.range() - 1; i >= 0; i--)
            arr->Append(i);
#endif
#endif


        state.ResumeTiming();

        BubbleSort(*arr, comp);
    }
//    state.SetComplexityN(state.range(0));
}

BENCHMARK(BM_BubbleSort)->Range(1 << MIN, 1 << MAX);

static void BM_ShakerSort(benchmark::State &state) {

    for (auto _: state) {

        state.PauseTiming();

        srand(time(nullptr));

#if SEQ == 0
        Sequence<int> *arr = new ArraySequence<int>;
#else
        Sequence<int> *arr = new ListSequence<int>;
#endif

#if RANDOM
        for (int i = 0; i < state.range(); i++)
            arr->Append(rand());
#else
#if REVERSE
        for (int i = 0; i < state.range(); i++)
            arr->Append(i);

#else
        for (int i = state.range() - 1; i >= 0; i--)
            arr->Append(i);
#endif
#endif

        state.ResumeTiming();

        ShakerSort(*arr, comp);
    }
//    state.SetComplexityN(state.range(0));
}

BENCHMARK(BM_ShakerSort)->Range(1 << MIN, 1 << MAX);

static void BM_InsertionSort(benchmark::State &state) {

    for (auto _: state) {

        state.PauseTiming();

        srand(time(nullptr));

#if SEQ == 0
        Sequence<int> *arr = new ArraySequence<int>;
#else
        Sequence<int> *arr = new ListSequence<int>;
#endif

#if RANDOM
        for (int i = 0; i < state.range(); i++)
            arr->Append(rand());
#else
#if REVERSE
        for (int i = 0; i < state.range(); i++)
            arr->Append(i);

#else
        for (int i = state.range() - 1; i >= 0; i--)
            arr->Append(i);
#endif
#endif

        state.ResumeTiming();

        InsertionSort(*arr, comp);
    }
//    state.SetComplexityN(state.range(0));
}

BENCHMARK(BM_InsertionSort)->Range(1 << MIN, 1 << MAX);

static void BM_SelectionSort(benchmark::State &state) {

    for (auto _: state) {

        state.PauseTiming();

        srand(time(nullptr));

#if SEQ == 0
        Sequence<int> *arr = new ArraySequence<int>;
#else
        Sequence<int> *arr = new ListSequence<int>;
#endif

#if RANDOM
        for (int i = 0; i < state.range(); i++)
            arr->Append(rand());
#else
#if REVERSE
        for (int i = 0; i < state.range(); i++)
            arr->Append(i);

#else
        for (int i = state.range() - 1; i >= 0; i--)
            arr->Append(i);
#endif
#endif

        state.ResumeTiming();

        SelectionSort(*arr, comp);
    }
//    state.SetComplexityN(state.range(0));
}

BENCHMARK(BM_SelectionSort)->Range(1 << MIN, 1 << MAX);

static void BM_QuickSort(benchmark::State &state) {

    for (auto _: state) {

        state.PauseTiming();

        srand(time(nullptr));

#if SEQ == 0
        Sequence<int> *arr = new ArraySequence<int>;
#else
        Sequence<int> *arr = new ListSequence<int>;
#endif

#if RANDOM
        for (int i = 0; i < state.range(); i++)
            arr->Append(rand());
#else
#if REVERSE
        for (int i = 0; i < state.range(); i++)
            arr->Append(i);

#else
        for (int i = state.range() - 1; i >= 0; i--)
            arr->Append(i);
#endif
#endif

        state.ResumeTiming();

        QuickSort(*arr, comp, 0, arr->GetLength() - 1);
    }
//    state.SetComplexityN(state.range(0));
}

BENCHMARK(BM_QuickSort)->Range(1 << MIN, 1 << MAX);

static void BM_MergeSort(benchmark::State &state) {

    for (auto _: state) {

        state.PauseTiming();

        srand(time(nullptr));

#if SEQ == 0
        Sequence<int> *arr = new ArraySequence<int>;
#else
        Sequence<int> *arr = new ListSequence<int>;
#endif

#if RANDOM
        for (int i = 0; i < state.range(); i++)
            arr->Append(rand());
#else
#if REVERSE
        for (int i = 0; i < state.range(); i++)
            arr->Append(i);

#else
        for (int i = state.range() - 1; i >= 0; i--)
            arr->Append(i);
#endif
#endif

        state.ResumeTiming();

        MergeSort(*arr, comp, 0, arr->GetLength() - 1);
    }
//    state.SetComplexityN(state.range(0));
}

BENCHMARK(BM_MergeSort)->Range(1 << MIN, 1 << MAX);

static void BM_QuickSort_STL(benchmark::State &state) {

    for (auto _: state) {

        state.PauseTiming();

        srand(time(nullptr));

        std::vector<int> arr;

#if RANDOM
        for (int i = 0; i < state.range(); i++)
            arr.push_back(rand());
#else
#if REVERSE
        for (int i = 0; i < state.range(); i++)
            arr.push_back(i);

#else
        for (int i = state.range() - 1; i >= 0; i--)
            arr.push_back(i);
#endif
#endif

        state.ResumeTiming();

        std::sort(arr.begin(), arr.end());
    }
//    state.SetComplexityN(state.range(0));
}

BENCHMARK(BM_QuickSort_STL)->Range(1 << MIN, 1 << MAX);

BENCHMARK_MAIN();