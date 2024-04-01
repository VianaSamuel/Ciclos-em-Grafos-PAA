#ifndef CYCLEDETECTIONDFS_HPP
#define CYCLEDETECTIONDFS_HPP

#include "Graph.hpp"
#include <set>
#include <vector>
#include <chrono>
#include <map>
#include <algorithm>

using namespace std;

class CycleDetectionDFS {
    const Graph& G;
    int operationCount;

public:
    CycleDetectionDFS(const Graph& G);
    int findAllUniqueCycles();
    void DFS(int v, vector<bool>& visited, int start, vector<int>& path, set<vector<int>>& uniqueCycles, const map<int, vector<int>>& adjLst);
};

#endif