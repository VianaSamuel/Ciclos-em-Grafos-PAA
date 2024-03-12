#include "Graph.hpp"
#include "CycleDetectionDFS.hpp"
#include <iostream>

using namespace std;

// ====================== //
//       CONSTRUTOR       //
// ====================== //
CycleDetectionDFS::CycleDetectionDFS(const Graph& G) : G(G){ }

void CycleDetectionDFS::hasCycle() {
    int V = G.getV();
    bool *visited = new bool [V];

    for (int v=0; v<V; v++) {
        visited[v] = false;
    }

    bool ret = hasCycleHelper(0, visited, -1);

    cout << endl << "CycleDetectionDFS:" << endl << "O grafo " << (ret ? "possui" : "não possui") << " ciclo(s)." << endl;
}

bool CycleDetectionDFS::hasCycleHelper(int node, bool *visited, int parent) {
    map<int, vector<int>> adjLst = G.getAdjLst();
    visited[node] = true;

    for (const auto& w : adjLst.at(node)) {
        if (!visited[w]) {
            if (hasCycleHelper(w, visited, node)) return true;
        } else if (w != parent) {
            return true;
        }
    }

    return false;
}