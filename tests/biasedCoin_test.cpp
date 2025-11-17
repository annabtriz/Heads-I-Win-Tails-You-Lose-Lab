#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/biasedCoin.hpp"

using namespace std;

TEST_CASE("correct number of results?") {
    vector<int> N_values = {10, 50};
    vector<double> P_values = {0.25, 0.5, 0.75};
    int M = 10;

    auto results = run_biased_coin(N_values, M, P_values);

    REQUIRE(results.size() == N_values.size() * P_values.size() * M);
}

TEST_CASE("heads within valid bounds?") {
    vector<int> N_values = {100};
    vector<double> P_values = {0.25, 0.5, 0.75};
    int M = 10;

    auto results = run_biased_coin(N_values, M, P_values);

    for (size_t i = 0; i < results.size(); ++i) {
        REQUIRE(results[i].heads >= 0);
        REQUIRE(results[i].heads <= results[i].N);
    }
}

TEST_CASE("is probability within valid range?") {
    vector<int> N_values = {20};
    vector<double> P_values = {0.10, 0.50, 0.80};
    int M = 5;

    auto results = run_biased_coin(N_values, M, P_values);

    for (size_t i = 0; i < results.size(); ++i) {
        REQUIRE(results[i].p >= 0.0);
        REQUIRE(results[i].p <= 1.0);
    }
}

TEST_CASE("benchmark") {
    vector<int> N_small = {1000};
    vector<int> N_large = {5000};
    vector<double> P_values = {0.25, 0.5, 0.75};
    int M = 10;

    BENCHMARK("N = 1000") {
        return run_biased_coin(N_small, M, P_values);
    };

    BENCHMARK("N = 5000") {
        return run_biased_coin(N_large, M, P_values);
    };
}