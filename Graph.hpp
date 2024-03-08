#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <list>

using namespace std;

class Graph {
    int V;
    list<int> *adjL;

public:
    Graph(int V);
    void addEdge(int v, int w);
    void printGraph();
};

#endif