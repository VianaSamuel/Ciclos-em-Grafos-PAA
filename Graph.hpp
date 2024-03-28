#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <map>
#include <vector>

using namespace std;

class Graph {
    int V;
    map<int, vector<int>> adjLst;
    vector<vector<bool>> adjMtx;

public:
    Graph(int V);
    void addEdge(int v, int w);
    void printGraph();
    int getV() const;
    const map<int, std::vector<int>>& getAdjLst() const;
    const vector<vector<bool>> &getAdjMtx() const;
};

#endif