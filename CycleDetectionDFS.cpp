#include "CycleDetectionDFS.hpp"
#include <iostream>

using namespace std::chrono;

// ====================== //
//       CONSTRUTOR       //
// ====================== //
// inicializa o CycleDetectionDFS com um grafo fornecido
CycleDetectionDFS::CycleDetectionDFS(const Graph& G) : G(G) {}


// ==================== //
//       DETECÇÃO       //
// ==================== //
// # findAllUniqueCycles
// encontra e imprime todos os ciclos únicos no grafo
int CycleDetectionDFS::findAllUniqueCycles() {
    // ----- INICIALIZAÇÃO ----- //
    auto start = high_resolution_clock::now();      // inicializa o cronômetro
    int V = G.getV();                               // obtém o número de vértices do grafo
    auto adjLst = G.getAdjLst();                    // obtém a lista de adjacência do grafo
    vector<bool> visited(V, false);                 // vetor para rastrear os vértices visitados
    vector<int> path;                               // vetor para rastrear o caminho atual
    set<vector<int>> uniqueCycles;                  // conjunto para armazenar ciclos únicos

    // ----- DFS ----- //
    // para cada vértice não-visitado, executa DFS para encontrar ciclos
    for (int i = 0; i < V; ++i) {
        if (!visited[i]) {
            DFS(i, visited, i, path, uniqueCycles, adjLst);
        }
    }

    // ----- PRINT ----- //
    // exibe todos os ciclos únicos encontrados
    for (const auto& cycle : uniqueCycles) {
        for (int v : cycle) {
            cout << v << " ";
        }
        cout << endl;
    }
    cout << "Total de ciclos: " << uniqueCycles.size() << endl;

    // ----- FINALIZAÇÃO ----- //
    auto stop = high_resolution_clock::now();                               // interrompe o cronômetro
    auto duration = duration_cast<milliseconds>(stop - start);              // calcula a duração da execução
    cout << "Tempo de execucao: " << duration.count() << "ms" << endl;      // exibe o tempo de execução
    return uniqueCycles.size();                                             // retorna o número total de ciclos únicos
}

// =============== //
//       DFS       //
// =============== //
// # DFS
// realiza a busca em profundidade
void CycleDetectionDFS::DFS(int v, vector<bool>& visited, int start, vector<int>& path, set<vector<int>>& uniqueCycles, const map<int, vector<int>>& adjLst) {
    visited[v] = true;  // marca o vértice atual como visitado
    path.push_back(v);  // adiciona o vértice atual ao caminho atual

    // para cada vértice 'u' não-visitado e adjacente ao vértice atual 'v'
    for (int u : adjLst.at(v)) {
        // SE o vértice adjacente for o vértice inicial
        // E o tamanho do caminho for maior que 2
        // ENTÃO um ciclo é ENCONTRADO
        if (u == start && path.size() > 2) {
            vector<int> cycle = path;           // cria uma cópia do caminho atual para um vetor de ciclo
            sort(cycle.begin(), cycle.end());   // ordena o ciclo para garantir a unicidade
            uniqueCycles.insert(cycle);         // insere o ciclo ordenado no conjunto de ciclos únicos
        } else if (!visited[u]) {
            // SE o vértice adjacente não foi visitado
            // CONTINUA a busca em profundidade a partir desse vértice
            DFS(u, visited, start, path, uniqueCycles, adjLst);
        }
    }

    path.pop_back();    // remove o vértice atual do caminho atual
    visited[v] = false; // marca o vértice atual como não visitado (para futuras iterações)
}