#include "Graph.hpp"
#include "CycleDetectionDFS.hpp" 
#include <iostream> 

using namespace std; 
CycleDetectionDFS::CycleDetectionDFS(const Graph& G) : G(G) { 
    // Inicializa o objeto com o grafo fornecido
}

void CycleDetectionDFS::hasCycle() {
    int V = G.getV(); // Obtém o número de vértices do grafo
    bool *visited = new bool[V]; // Cria um array dinâmico para marcar vértices visitados

    // Inicializa todos os vértices como não visitados
    for (int v = 0; v < V; v++) {
        visited[v] = false;
    }

    // Inicia a busca em profundidade a partir do vértice 0, com -1 como vértice pai (não tem pai)
    bool ret = hasCycleHelper(0, visited, -1);

    // Imprime o resultado da detecção de ciclos
    cout << endl << "CycleDetectionDFS:" << endl << "O grafo " << (ret ? "possui" : "não possui") << " ciclo(s)." << endl;
    
    // Libera a memória alocada para o array visited
    delete[] visited;
}

bool CycleDetectionDFS::hasCycleHelper(int node, bool *visited, int parent) {
    map<int, vector<int>> adjLst = G.getAdjLst(); // Obtém a lista de adjacências do grafo
    visited[node] = true; // Marca o vértice atual como visitado

    // Itera sobre todos os vértices adjacentes ao vértice atual
    for (const auto& w : adjLst.at(node)) {
        if (!visited[w]) { // Se o vértice adjacente não foi visitado
            if (hasCycleHelper(w, visited, node)) return true; // Faz uma chamada recursiva para esse vértice
        } else if (w != parent) { // Se o vértice adjacente já foi visitado e não é o pai do vértice atual
            return true; // Encontramos um ciclo, retorna true
        }
    }

    return false; 
}