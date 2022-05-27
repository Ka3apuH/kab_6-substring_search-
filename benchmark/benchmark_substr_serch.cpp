//
// Created by kirill_kazarin on 27.05.22.
//

#include "benchmark_substr_serch.h"
#include <random>
#include "substr_serch.h"
#include "benchmark/benchmark.h"

using namespace h_work;

BENCHMARK_DEFINE_F(strSRCH, strSRCH_KMP) (benchmark::State& state) {
    for (auto _ : state) {
        auto res=strSRCH_KMP(str_buf,"ece");
        //benchmark::DoNotOptimize(pr_heap.add_element(randomDevice()));
        state.SetComplexityN(state.range(0));
    }

}


BENCHMARK_REGISTER_F(strSRCH, strSRCH_KMP)
        ->RangeMultiplier(2)
        ->Range(8, 8<<12)
        ->Complexity(benchmark::oAuto)
        ->UseRealTime();

BENCHMARK_DEFINE_F(strSRCH, strSRCH_Boyer_Moore) (benchmark::State& state) {
    for (auto _ : state) {
        auto res=strSRCH_Boyer_Moore(str_buf,"ece");
        //benchmark::DoNotOptimize(pr_heap.add_element(randomDevice()));
        state.SetComplexityN(state.range(0));
    }

}


BENCHMARK_REGISTER_F(strSRCH, strSRCH_Boyer_Moore)
        ->RangeMultiplier(2)
        ->Range(8, 8<<12)
        ->Complexity(benchmark::oAuto)
        ->UseRealTime();

BENCHMARK_DEFINE_F(strSRCH, strSRCH_Rabin_Karp) (benchmark::State& state) {
    for (auto _ : state) {
        auto res=strSRCH_Rabin_Karp(str_buf,"ece");
        //benchmark::DoNotOptimize(pr_heap.add_element(randomDevice()));
        state.SetComplexityN(state.range(0));
    }

}


BENCHMARK_REGISTER_F(strSRCH, strSRCH_Rabin_Karp)
        ->RangeMultiplier(2)
        ->Range(8, 8<<12)
        ->Complexity(benchmark::oAuto)
        ->UseRealTime();


// Run the benchmark
BENCHMARK_MAIN();


