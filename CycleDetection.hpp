#ifndef CYCLEDETECTION_HPP
#define CYCLEDETECTION_HPP

#include <vector>

class CycleDetection {
private:
    std::vector<std::vector<bool>> graph;
    int cycleCount;

    void printCycle(const std::vector<int>& cycle);
    bool isValidCycle(const std::vector<int>& subset);
    void checkSubsetsForCycles(const std::vector<int>& subset);

public:
    CycleDetection(int n);
    void addEdge(int u, int v);
    void findAllCycles();
    int getCycleCount() const;
};

#endif // CYCLEDETECTION_HPP
