#include "CycleDetectionDFS.hpp"
#include "Graph.hpp"
#include <iostream>

// ====================== //
//       CONSTRUTOR       //
// ====================== //
// inicializa o CycleDetectionDFS com um grafo fornecido
CycleDetectionDFS::CycleDetectionDFS(const Graph& G) : G(G), cycleCount(0) {}


// ==================== //
//       DETECÇÃO       //
// ==================== //
bool CycleDetectionDFS::hasCycle() {
    std::map<int, std::vector<int>> adjLst = G.getAdjLst();// obtém a lista de adjacência do grafo.
    int V = G.getV(); //obtém o número de vértices no grafo.
    std::vector<int> visited(V, 0);// cria um vetor para marcar os vértices visitados.

    for (int v = 0; v < V; ++v) {
        //se o vértice atual não foi visitado, inicia uma busca DFS a partir dele.
        if (!visited[v]) {
            dfsCycleCheck(adjLst, visited, v, -1);
        }
    }
    return cycleCount > 0;
}

// =============== //
//       DFS       //
// =============== //
bool CycleDetectionDFS::dfsCycleCheck(const std::map<int, std::vector<int>>& adjLst, std::vector<int>& visited, int v, int parent) {
    //marca o vértice atual como visitado.
    visited[v] = 1;

    //itera sobre todos os vértices adjacentes ao vértice atual.
    for (int w : adjLst.at(v)) {
        //se o vértice adjacente não foi visitado, realiza uma busca DFS recursivamente a partir dele.
        if (!visited[w]) {
            dfsCycleCheck(adjLst, visited, w, v);
        }
        //se o vértice adjacente já foi visitado e não é o pai do vértice atual, um ciclo foi encontrado.
        else if (w != parent) {
            cycleCount++;
        }
    }


    return false; 
}

void CycleDetectionDFS::printCycleCount() const {
    std::cout << "Número de ciclos detectados: " << cycleCount / 2 << std::endl;
}
