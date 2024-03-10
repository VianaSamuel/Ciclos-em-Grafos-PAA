#include "Graph.hpp"
#include <iostream>

using namespace std;

int main() {
    Graph g(6);
    g.addEdge('A', 'B');
    g.addEdge('A', 'D');
    g.addEdge('A', 'E');
    g.addEdge('B', 'C');
    g.addEdge('B', 'D');
    g.addEdge('B', 'E');
    g.addEdge('C', 'D');
    g.addEdge('C', 'E');
    g.addEdge('C', 'F');
    g.addEdge('D', 'F');
    g.addEdge('E', 'F');

    g.printAdjList();
    g.printAdjMatrix();
    
    return 0;
}