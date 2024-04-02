#include "Graph.hpp"
#include "CycleDetectionDFS.hpp"
#include "CycleDetectionPermutation.hpp"
#include <iostream>

using namespace std;

int main() {
    // Grafo G
    // Graph G(6);
    // G.addEdge(0, 1);
    // G.addEdge(0, 3);
    // G.addEdge(0, 4);
    // G.addEdge(1, 2);
    // G.addEdge(1, 3);
    // G.addEdge(1, 4);
    // G.addEdge(2, 3);
    // G.addEdge(2, 4);
    // G.addEdge(2, 5);
    // G.addEdge(3, 5);
    // G.addEdge(4, 5);
    // cout << "=======" << endl;
    // cout << "Grafo G" << endl;
    // cout << "=======" << endl;
    // G.printGraph();

    // Grafo H
    // Graph H(6);
    // H.addEdge(0, 1);
    // H.addEdge(1, 2);
    // H.addEdge(0, 3);
    // H.addEdge(3, 4);
    // H.addEdge(4, 5);
    // cout << "=======" << endl;
    // cout << "Grafo H" << endl;
    // cout << "=======" << endl;
    // H.printGraph();

    // Grafo K5
    int k = 5;
    Graph K5(k);
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < k; ++j) {
            if (i != j) {
                K5.addEdge(i, j);
            }
        }
    }
    // cout << "========" << endl;
    // cout << "Grafo K5" << endl;
    // cout << "========" << endl;
    // K5.printGraph();


    // // PERMUTAÇÃO
    // cout << "##########" << endl;
    // cout << "PERMUTACAO" << endl;
    // cout << "##########" << endl;
    // CycleDetectionPermutation cdP_G(G);
    // CycleDetectionPermutation cdP_H(H);
    CycleDetectionPermutation cdP_K5(K5);
    // cout << "-------" << endl;
    // cout << "Grafo G" << endl;
    // cout << "-------" << endl;
    // cdP_G.findAllCycles();
    // cout << "-------" << endl;
    // cout << "Grafo H" << endl;
    // cout << "-------" << endl;
    // cdP_H.findAllCycles();
    // cout << "--------" << endl;
    // cout << "Grafo K5" << endl;
    // cout << "--------" << endl;
    cdP_K5.findAllCycles();


    // // CAMINHAMENTO
    // cout << "############" << endl;
    // cout << "CAMINHAMENTO" << endl;
    // cout << "############" << endl;
    // CycleDetectionDFS cdDFS_G(G);
    // CycleDetectionDFS cdDFS_H(H);
    // CycleDetectionDFS cdDFS_K5(K5);
    // cout << "-------" << endl;
    // cout << "Grafo G" << endl;
    // cout << "-------" << endl;
    // cdDFS_G.findAllUniqueCycles();
    // cout << "-------" << endl;
    // cout << "Grafo H" << endl;
    // cout << "-------" << endl;
    // cdDFS_H.findAllUniqueCycles();
    // cout << "--------" << endl;
    // cout << "Grafo K5" << endl;
    // cout << "--------" << endl;
    // cdDFS_K5.findAllUniqueCycles();
    
    return 0;
}