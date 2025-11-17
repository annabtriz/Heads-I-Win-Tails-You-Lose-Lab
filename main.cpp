#include "src/biasedCoin.hpp"

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    vector<int> N_values = {10, 50, 100, 500, 1000}; //flips
    int M = 10; //my trials
    vector<double> P_values = {0.25, 0.5, 0.75}; //probability heads

    auto results = run_biased_coin(N_values, M, P_values);

    cout << setw(15) << "Flips (N)"
         << setw(15) << "Trial"
         << setw(20) << "Prob Heads (p)"
         << setw(15) << "Heads Count" << "\n";

    for (const auto& r : results) {
        cout << setw(15) << r.N
             << setw(15) << r.trial
             << setw(20) << r.p
             << setw(15) << r.heads
             << "\n";
    }

    return 0;
}