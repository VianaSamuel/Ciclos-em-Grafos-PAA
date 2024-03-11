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
    void printAdjList();
    void printAdjMatrix();
};

#endif