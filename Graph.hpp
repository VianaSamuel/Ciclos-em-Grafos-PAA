#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <map>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Graph {
    int V;
    map<int, vector<int>> adjLst;
    vector<vector<bool>> adjMtx;

    void DFS(int v, vector<bool>& visited, int start, vector<int>& path, set<string>& uniqueCycles);
    string createCycleKey(const vector<int>& cycle);
    bool cycleExists(const vector<int>& cycle, const vector<vector<int>>& uniqueCycles);

public:
    Graph(int V);

    void addEdge(int v, int w);
    void printGraph();
    bool detectCycle();
    int getV() const;
    const map<int, std::vector<int>>& getAdjLst() const;
    const vector<vector<bool>> &getAdjMtx() const;

    int findAllUniqueCycles(); 

private:
    bool dfsUtil(int v, vector<bool>& visited, int parent);
};

#endif