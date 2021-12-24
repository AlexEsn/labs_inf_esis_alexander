#include "benchmark/benchmark.h"
#include "arr/arraysequence.h"
#include "list/listsequence.h"
#include <vector>
#include <list>
#include <iostream>

static void BM_ArraySequence_Accessing(benchmark::State& state) {
    ArraySequence<int> arr(1000);
    for (auto _ : state){
        arr.Get(state.range(0)) = 0;
    }
    state.SetComplexityN(state.range(0));
}
static void BM_ListSequence_Accessing(benchmark::State& state) {
    for (auto _ : state){
        ListSequence<int> list;
        list.Get(1000) = 0;
    }
    state.SetComplexityN(state.range(0));
}

static void BM_STL_Vector_Accessing(benchmark::State& state) {
    std::vector<int> vector(1000);
    for (auto _ : state){
        vector[state.range(0)] = 0;
    }
    state.SetComplexityN(state.range(0));
}
static void BM_STL_List_Accessing(benchmark::State& state) {
    for (auto _ : state){
        std::list<int> list;
        auto i = list.begin();
        std::advance(i, 1000);
        list.insert(i, 0);
    }
    state.SetComplexityN(state.range(0));
}

BENCHMARK(BM_ArraySequence_Accessing)->RangeMultiplier(2)->Range(1<<10, 1<<18)->Complexity(benchmark::oN);
BENCHMARK(BM_ListSequence_Accessing)->RangeMultiplier(2)->Range(1<<10, 1<<18)->Complexity(benchmark::oN);
BENCHMARK(BM_STL_Vector_Accessing)->RangeMultiplier(2)->Range(1<<10, 1<<18)->Complexity(benchmark::oN);
BENCHMARK(BM_STL_List_Accessing)->RangeMultiplier(2)->Range(1<<10, 1<<18)->Complexity(benchmark::oN);

static void BM_ArraySequence_Append(benchmark::State& state) {
    ArraySequence<int> arr;
    for (auto _ : state){
        arr.Append(0);
    }
    state.SetComplexityN(state.range(0));

}
static void BM_ListSequence_Append(benchmark::State& state) {
    ListSequence<int> list;
    for (auto _ : state){
        list.Append(0);
    }
    state.SetComplexityN(state.range(0));
}

static void BM_STL_Vector_Append(benchmark::State& state) {
    std::vector<int> vector;
    for (auto _ : state){
        vector.push_back(0);
    }
    state.SetComplexityN(state.range(0));

}
static void BM_STL_List_Append(benchmark::State& state) {
    std::list<int> list;
    for (auto _ : state){
        list.push_back(0);
    }
    state.SetComplexityN(state.range(0));
}

BENCHMARK(BM_ArraySequence_Append)->RangeMultiplier(2)->Range(1<<10, 1<<18)->Complexity(benchmark::oN);
BENCHMARK(BM_ListSequence_Append)->RangeMultiplier(2)->Range(1<<10, 1<<18)->Complexity(benchmark::oN);
BENCHMARK(BM_STL_Vector_Append)->RangeMultiplier(2)->Range(1<<10, 1<<18)->Complexity(benchmark::oN);
BENCHMARK(BM_STL_List_Append)->RangeMultiplier(2)->Range(1<<10, 1<<18)->Complexity(benchmark::oN);

static void BM_ArraySequence_Prepend(benchmark::State& state) {
    ArraySequence<int> arr;
    for (auto _ : state){
        arr.Prepend(0);
    }
    state.SetComplexityN(state.range(0));
}
static void BM_ListSequence_Prepend(benchmark::State& state) {
    ListSequence<int> list;
    for (auto _ : state){
        list.Prepend(0);
    }
    state.SetComplexityN(state.range(0));
}

static void BM_STL_Vector_Prepend(benchmark::State& state) {
    std::vector<int> vector;
    for (auto _ : state){
        vector.insert(vector.begin(), 0);
    }
    state.SetComplexityN(state.range(0));
}
static void BM_STL_List_Prepend(benchmark::State& state) {
    std::list<int> list;
    for (auto _ : state){
        list.push_front(0);
    }
    state.SetComplexityN(state.range(0));
}

BENCHMARK(BM_ArraySequence_Prepend)->RangeMultiplier(2)->Range(1<<10, 1<<18)->Complexity(benchmark::oN);
BENCHMARK(BM_ListSequence_Prepend)->RangeMultiplier(2)->Range(1<<10, 1<<18)->Complexity(benchmark::oN);
BENCHMARK(BM_STL_Vector_Prepend)->RangeMultiplier(2)->Range(1<<10, 1<<18)->Complexity(benchmark::oN);
BENCHMARK(BM_STL_List_Prepend)->RangeMultiplier(2)->Range(1<<10, 1<<18)->Complexity(benchmark::oN);

BENCHMARK_MAIN();