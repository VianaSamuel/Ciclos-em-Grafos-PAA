#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <map>
#include <vector>

using namespace std;

class Graph {
    int V;
    map<char, vector<char>> adjLst;
    vector<vector<bool>> adjMtx;

public:
    Graph(int V);
    void addEdge(char v, char w);
    void printAdjList();
    void printAdjMatrix();
};

#endif