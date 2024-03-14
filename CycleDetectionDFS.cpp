#include "Graph.hpp"
#include "CycleDetectionDFS.hpp" 
#include <iostream> 

using namespace std;

// ====================== //
//       CONSTRUTOR       //
// ====================== //
// inicializa o CycleDetectionDFS com um grafo fornecido
CycleDetectionDFS::CycleDetectionDFS(const Graph& G) : G(G) { }


// ==================== //
//       DETECÇÃO       //
// ==================== //
void CycleDetectionDFS::hasCycle() {
    // ----- INICIALIZAÇÃO ----- //
    // obtém o número de vértices do grafo, cria um array de vértices visitados e os inicializa como não visitados
    int V = G.getV();
    bool *visited = new bool[V];
    for (int v = 0; v < V; v++) {
        visited[v] = false;
    }

    // ----- DFS ----- //
    // realiza a busca em profundidade a partir do vértice 0, utilizando -1 como vértice-pai
    bool ret = dfsCycleCheck(0, visited, -1);
    cout << endl << "CycleDetectionDFS:" << endl << "O grafo " << (ret ? "possui" : "nao possui") << " ciclo(s)." << endl;
    
    // ----- MEMÓRIA -----//
    // libera a memória alocada para o array
    delete[] visited;
}


// =============== //
//       DFS       //
// =============== //
bool CycleDetectionDFS::dfsCycleCheck(int node, bool *visited, int parent) {
    // ----- INICIALIZAÇÃO ----- //
    // obtém a lista de adjacência do grafo e marca o vértice atual como visitado
    map<int, vector<int>> adjLst = G.getAdjLst();
    visited[node] = true;

    // ----- ITERAÇÃO ----- //
    // itera sobre todos os vértices adjacentes ao vértice atual
    for (const auto& w : adjLst.at(node)) {
        // SE o vértice adjacente não foi visitado
        if (!visited[w]) {
            // realiza uma chamada recursiva para este vértice
            if (dfsCycleCheck(w, visited, node)) return true;
        }
        // SE o vértice adjacente já foi visitado e SE ele não é o pai do vértice atual
        else if (w != parent) {
            // CICLO ENCONTRADO
            return true;
        }
    }

    // CICLO NÃO ENCONTRADO
    return false; 
}