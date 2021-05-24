#include "benchmark/benchmark.h"
#include "arr/arraysequence.h"
#include "list/listsequence.h"

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
        list.Get(100000) = 0;
    }
    state.SetComplexityN(state.range(0));
}

BENCHMARK(BM_ArraySequence_Accessing)->RangeMultiplier(2)->Range(1<<10, 1<<18)->Complexity(benchmark::oN);
BENCHMARK(BM_ListSequence_Accessing)->RangeMultiplier(2)->Range(1<<10, 1<<18)->Complexity(benchmark::oN);

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

BENCHMARK(BM_ArraySequence_Append)->RangeMultiplier(2)->Range(1<<10, 1<<18)->Complexity(benchmark::oN);
BENCHMARK(BM_ListSequence_Append)->RangeMultiplier(2)->Range(1<<10, 1<<18)->Complexity(benchmark::oN);

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

BENCHMARK(BM_ArraySequence_Prepend)->RangeMultiplier(2)->Range(1<<10, 1<<18)->Complexity(benchmark::oN);
BENCHMARK(BM_ListSequence_Prepend)->RangeMultiplier(2)->Range(1<<10, 1<<18)->Complexity(benchmark::oN);

BENCHMARK_MAIN();