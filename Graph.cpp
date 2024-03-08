#include "Graph.hpp"
#include <iostream>

using namespace std;

// ====================== //
//       CONSTRUTOR       //
// ====================== //
Graph::Graph(int V) {
    this->V = V;
    adjL = new list<int>[V];
}

// ======================== //
//       LISTA DE ADJ.      //
// ======================== //
void Graph::addEdge(int v, int w) {
    adjL[v].push_back(w);
    adjL[w].push_back(v);
}

// ================ //
//       PRINT      //
// ================ //
void Graph::printGraph() {
    for (int v = 0; v < V; ++v) {
        cout << "| " << v << " |-> ";
        for (int w : adjL[v]) {
            cout << w << " ";
        }
        cout << endl;
    }
}
