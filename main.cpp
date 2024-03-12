#include "Graph.hpp"
#include "CycleDetectionDFS.hpp"
#include <iostream>

using namespace std;

int main() {
    Graph G(6);
    G.addEdge(0, 1);
    G.addEdge(0, 3);
    G.addEdge(0, 4);
    G.addEdge(1, 2);
    G.addEdge(1, 3);
    G.addEdge(1, 4);
    G.addEdge(2, 3);
    G.addEdge(2, 4);
    G.addEdge(2, 5);
    G.addEdge(3, 5);
    G.addEdge(4, 5);
    G.printAdjList();
    G.printAdjMatrix();

    CycleDetectionDFS cdDFS(G);
    cdDFS.hasCycle();
    
    return 0;
}