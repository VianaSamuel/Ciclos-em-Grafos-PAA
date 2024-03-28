#ifndef CYCLEDETECTIONPERMUTATION_HPP
#define CYCLEDETECTIONPERMUTATION_HPP

#include <vector>
#include <cmath>
#include <chrono>

class CycleDetectionPermutation {
private:
    std::vector<std::vector<bool>> graph;
    int cycleCount;
    int operationCount;

    void printCycle(const std::vector<int>& cycle);
    bool isValidCycle(const std::vector<int>& subset);
    void checkSubsetsForCycles(const std::vector<int>& subset);

public:
    CycleDetectionPermutation(int n);
    void addEdge(int u, int v);
    void findAllCycles();
    int getCycleCount() const;
};

#endif