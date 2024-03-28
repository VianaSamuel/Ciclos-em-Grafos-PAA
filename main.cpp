#include "Graph.hpp"
#include "CycleDetectionDFS.hpp"
#include "CycleDetectionPermutation.hpp"
#include <iostream>

using namespace std;

int main() {
    cout << "-------" << endl;
    cout << "Grafo G -> (DFS)" << endl;
    cout << "-------" << endl;
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
    G.printGraph();
    CycleDetectionDFS cdDFS_G(G);
    cdDFS_G.findAllUniqueCycles();
    cout << endl << endl;

    cout << "-------" << endl;
    cout << "Grafo H -> (DFS)" << endl;
    cout << "-------" << endl;
    Graph H(6);
    H.addEdge(0, 1);
    H.addEdge(1, 2);
    H.addEdge(0, 3);
    H.addEdge(3, 4);
    H.addEdge(4, 5);
    H.printGraph();
    CycleDetectionDFS cdDFS_H(H);
    cdDFS_H.findAllUniqueCycles();
    cout << endl << endl;


    cout << "--------" << endl;
    cout << "Grafo K5 -> (PERMUTACAO)" << endl;
    cout << "--------" << endl;
    int n = 5;
    CycleDetectionPermutation cdP(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i != j) {
                cdP.addEdge(i, j);
            }
        }
    }
    cdP.findAllCycles();
    cout << "Quantidade total de ciclos encontrada: " << cdP.getCycleCount() << endl;
    
    return 0;
}