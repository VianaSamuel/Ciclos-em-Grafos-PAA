#include "Graph.hpp"
#include "CycleDetectionDFS.hpp"
#include "CycleDetection.hpp"
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
    CycleDetectionDFS cdDFS_G(G);
    cdDFS_G.hasCycle();

    Graph H(6);
    H.addEdge(0, 1);
    H.addEdge(1, 2);
    H.addEdge(0, 3);
    H.addEdge(3, 4);
    H.addEdge(4, 5);
    H.printAdjList();
    H.printAdjMatrix();
    CycleDetectionDFS cdDFS_H(H);
    cdDFS_H.hasCycle();

    int n = 5;
    CycleDetection cd(n);

    //K5
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i != j) {
                cd.addEdge(i, j);
            }
        }
    }

    cd.findAllCycles();

    std::cout << "Total cycles found: " << cd.getCycleCount() << std::endl;
    
    return 0;
}