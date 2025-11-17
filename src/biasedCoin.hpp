#ifndef BIASEDCOIN_HPP
#define BIASEDCOIN_HPP

#include <vector>

using namespace std;

struct TrialResult {
    int N;
    int trial;
    double p;
    int heads;
};

vector<TrialResult> run_biased_coin(const vector<int>& N_values, int M, const vector<double>& P_values);

#endif