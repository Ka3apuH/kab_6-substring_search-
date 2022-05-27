//
// Created by kirill_kazarin on 27.05.22.
//

#ifndef LAB_6_SUBSTRSERCH_BENCHMARK_SUBSTR_SERCH_H
#define LAB_6_SUBSTRSERCH_BENCHMARK_SUBSTR_SERCH_H
#include <random>
#include "benchmark/benchmark.h"
#include <string>
#include "substr_serch.h"

class strSRCH: public benchmark::Fixture{

public:

    void SetUp(const ::benchmark::State &state) override {

        for (int64_t i = 0; i < state.range(0); ++i) {
            str_buf.push_back(static_cast<char>(randomDevice()));
        }
    }

    void TearDown(const ::benchmark::State &state) override{
        str_buf.clear();
    }


protected:
    std::string str_buf;
    std::random_device randomDevice;
};
#endif //LAB_6_SUBSTRSERCH_BENCHMARK_SUBSTR_SERCH_H
