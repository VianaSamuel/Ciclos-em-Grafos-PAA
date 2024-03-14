#ifndef CYCLEDETECTIONDFS_HPP
#define CYCLEDETECTIONDFS_HPP

#include "Graph.hpp"

using namespace std;

class CycleDetectionDFS {
    const Graph& G;

public:
    CycleDetectionDFS(const Graph& G);
    void hasCycle();
    bool dfsCycleCheck(int node, bool *visited, int parent);
};

#endif