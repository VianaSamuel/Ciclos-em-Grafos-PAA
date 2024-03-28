#ifndef CYCLEDETECTIONPERMUTATION_HPP
#define CYCLEDETECTIONPERMUTATION_HPP

#include "Graph.hpp"
#include <numeric>
#include <vector>
#include <chrono>
#include <cmath>
#include <algorithm>

using namespace std;

class CycleDetectionPermutation {
private:
    const Graph& G;
    int cycleCount;
    int operationCount;

    void printCycle(const vector<int>& cycle);
    bool isValidCycle(const vector<int>& subset, vector<vector<bool>>& adjMtx);
    void checkSubsetsForCycles(const vector<int>& subset, vector<vector<bool>>& adjMtx);

public:
    CycleDetectionPermutation(const Graph& G);
    void findAllCycles();
    int getCycleCount() const;
};

#endif