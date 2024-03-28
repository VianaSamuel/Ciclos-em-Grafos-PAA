#ifndef CYCLEDETECTIONDFS_HPP
#define CYCLEDETECTIONDFS_HPP

#include "Graph.hpp"

using namespace std;

class CycleDetectionDFS {
    const Graph& G;
    int operationCount;

public:
    CycleDetectionDFS(const Graph& G);
    int findAllUniqueCycles();
    void DFS(int v, vector<bool> &visited, int start, vector<int> &path, set<string> &uniqueCycles, const map<int, vector<int>>& adjLst);
    string createCycleKey(const vector<int>& cycle);
};

#endif