#include "benchmark/benchmark.h"

#include <boost/numeric/ublas/matrix_sparse.hpp>                   //boost

namespace bst = boost::numeric::ublas;

#include "tree/sparse_matrix_BTree.h"

#define MIN 2                       //initial power of two
#define MAX 30                      //final power of two


static void BM_push_compressed_matrix(benchmark::State &state) {

    compressed_matrix<int> matrix(100000000, 100000000);

    int i = 0, j = 0;
    for (auto _: state) {
        matrix.push_back(i, j, 1);
        i++;
        j++;
    }
}

BENCHMARK(BM_push_compressed_matrix)->Range(1 << MIN, 1 << MAX);

static void BM_push_compressed_matrix_boost(benchmark::State &state) {

    bst::compressed_matrix<int> matrix(100000000, 100000000);

    int i = 0, j = 0;
    for (auto _: state) {
        matrix.push_back(i, j, 1);
        i++;
        j++;
    }
}

BENCHMARK(BM_push_compressed_matrix_boost)->Range(1 << MIN, 1 << MAX);

//static void BM_get_compressed_matrix(benchmark::State &state) {
//
//    compressed_matrix<int> matrix(100000000, 100000000);
//
//    int i = 0, j = 0;
//    for (auto _: state) {
//        matrix.push_back(i, j, 1);
//        matrix(i, j) = 2;
//        i++;
//        j++;
//    }
//}
//
//BENCHMARK(BM_get_compressed_matrix)->Range(1 << MIN, 1 << MAX);
//
//static void BM_get_compressed_matrix_boost(benchmark::State &state) {
//
//    bst::compressed_matrix<int> matrix(100000000, 100000000);
//    int i = 0, j = 0;
//    for (auto _: state) {
//        matrix.push_back(i, j, 1);
//        matrix(i, j) = 2;
//        i++;
//        j++;
//    }
//}
//
//BENCHMARK(BM_get_compressed_matrix_boost)->Range(1 << MIN, 1 << MAX);

BENCHMARK_MAIN();