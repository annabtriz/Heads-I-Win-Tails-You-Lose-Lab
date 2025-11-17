#include "biasedCoin.hpp"

#include <cstdlib>
#include <ctime>
#include <chrono>
#include <iostream>

using namespace std;

vector<TrialResult> run_biased_coin(const vector<int>& N_values, int M, const vector<double>& P_values) {
    vector<TrialResult> results;

    srand(static_cast<unsigned>(time(nullptr)));

    for (double p : P_values) {
        for (int N : N_values) {
            for (int trial = 1; trial <= M; ++trial) {
                int heads_count = 0;

                for (int flip = 0; flip < N; ++flip) {
                    double r = static_cast<double>(rand()) / RAND_MAX;
                    if (r < p) heads_count++;
                }

                results.push_back({N, trial, p, heads_count});
            }
        }
    }

    return results;
}