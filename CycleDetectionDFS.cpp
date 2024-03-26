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
    int V = G.getV();               // obtém o número de vértices do grafo
    bool *visited = new bool[V];    // cria um array de vértices visitados
    for (int v = 0; v < V; v++) {   // inicializa os vértices do array como não visitados
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
    map<int, vector<int>> adjLst = G.getAdjLst();   // obtém a lista de adjacência do grafo
    visited[node] = true;                           // marca o vértice atual como visitado

    // ----- ITERAÇÃO ----- //
    // itera sobre todos os vértices adjacentes ao vértice atual
    for (const auto& w : adjLst.at(node)) {
        if (!visited[w]) {                                      // SE o vértice adjacente não foi visitado
            if (dfsCycleCheck(w, visited, node)) return true;   // realiza uma chamada recursiva para este vértice
        }
        else if (w != parent) { // SE o vértice adjacente já foi visitado e SE ele não é o pai do vértice atual
            return true;        // CICLO ENCONTRADO
        }
    }

    return false;   // CICLO NÃO ENCONTRADO
}