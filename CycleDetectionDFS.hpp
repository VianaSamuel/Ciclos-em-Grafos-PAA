#ifndef CYCLEDETECTIONDFS_HPP
#define CYCLEDETECTIONDFS_HPP

#include "Graph.hpp"

using namespace std;

class CycleDetectionDFS {
    const Graph& G;
    int cycleCount;

public:
    CycleDetectionDFS(const Graph& G);
    bool hasCycle();
    bool dfsCycleCheck(const map<int, vector<int>>& adjLst, vector<int>& visited, int curr);
};

#endif