#ifndef CYCLE_DETECTION_DFS_HPP
#define CYCLE_DETECTION_DFS_HPP

#include "Graph.hpp"
#include <map>
#include <vector>

class CycleDetectionDFS {
private:
    const Graph& G;
    int cycleCount;
    std::vector<std::vector<int>> cycles;

public:
    CycleDetectionDFS(const Graph& G);
    bool hasCycle();
    bool dfsCycleCheck(const std::map<int, std::vector<int>> &adjLst, std::vector<int> &visited, int v, int parent);
    void printCycleCount() const;
    void printCycles() const;
};

#endif // CYCLE_DETECTION_DFS_HPP
