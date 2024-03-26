#include "Graph.hpp"
#include "CycleDetectionDFS.hpp" 
#include <iostream> 

using namespace std;

// ====================== //
//       CONSTRUTOR       //
// ====================== //
// inicializa o CycleDetectionDFS com um grafo fornecido
CycleDetectionDFS::CycleDetectionDFS(const Graph& G) : G(G), cycleCount(0) { }


// ==================== //
//       DETECÇÃO       //
// ==================== //
bool CycleDetectionDFS::hasCycle() {
    // ----- INICIALIZAÇÃO ----- //
    map<int, vector<int>> adjLst = G.getAdjLst();   // obtém a lista de adjacência do grafo
    int V = G.getV();                               // obtém o número de vértices do grafo
    vector<int> visited (V, 0);                     // cria um array de vértices visitados
    bool FLAG = false;                              // flag pra indicar ciclos

    // VÉRTICE (chave .first) v
    for (const auto &pair : adjLst) {
        int v = pair.first;
        visited[v] = 1; // marca o vértice atual como visitado
        
        // LISTA DE ADJACENTES (valor .second) w
        for (int w : pair.second) {
            FLAG = dfsCycleCheck(adjLst, visited, w);
            if (FLAG) {
                return true; // CICLO ENCONTRADO
            }
        }
        
        visited[v] = 0; // reseta a marcação do vértice atual
    }
    
    return false; // CICLO NÃO ENCONTRADO
}


// =============== //
//       DFS       //
// =============== //
bool CycleDetectionDFS::dfsCycleCheck(const map<int, vector<int>>& adjLst, vector<int>& visited, int v) {
    bool FLAG = false;

    if (visited[v] == 2) {  // SE o vértice ATUAL já foi visitado e está marcado como parte de um possível ciclo
        return true;        // CICLO ENCONTRADO
    }
    
    visited[v] = 1; // marca o vértice atual como visitado
    
    for (int w : adjLst.at(v)) {
        if (visited[w] == 1) {  // SE o vértice ADJACENTE já foi visitado
            visited[w] = 2;     // o marca como parte de um possível ciclo
        } else {
            FLAG = dfsCycleCheck(adjLst, visited, w); // explora adjacentes recursivamente
            if (FLAG) {
                return true; // CICLO ENCONTRADO
            }
        }
    }
    
    return false; // CICLO NÃO ENCONTRADO
}