#include "CycleDetectionDFS.hpp"
#include <iostream>
#include <set>
#include <vector>
#include <chrono>
#include <algorithm>
#include <map>

using namespace std;
using namespace std::chrono;

// Classe CycleDetectionDFS para encontrar ciclos em um grafo usando busca em profundidade (DFS)
CycleDetectionDFS::CycleDetectionDFS(const Graph& G) : G(G), operationCount(0) {}

// Método para encontrar todos os ciclos únicos no grafo
int CycleDetectionDFS::findAllUniqueCycles() {
    auto start = high_resolution_clock::now(); // Marca o início da execução
    int V = G.getV(); // Obtém o número de vértices do grafo
    auto adjLst = G.getAdjLst(); // Obtém a lista de adjacência do grafo
    vector<bool> visited(V, false); // Vetor para rastrear os vértices visitados
    vector<int> path; // Vetor para rastrear o caminho atual
    set<vector<int>> uniqueCycles; // Conjunto para armazenar ciclos únicos

    // Para cada vértice não visitado, executa DFS para encontrar ciclos
    for (int i = 0; i < V; ++i) {
        if (!visited[i]) {
            DFS(i, visited, i, path, uniqueCycles, adjLst);
        }
    }

    // Exibe todos os ciclos únicos encontrados
    for (const auto& cycle : uniqueCycles) {
        for (int v : cycle) {
            cout << v << " ";
        }
        cout << endl;
    }
    cout << "Total de ciclos: " << uniqueCycles.size() << endl;

    auto stop = high_resolution_clock::now(); // Marca o fim da execução
    auto duration = duration_cast<milliseconds>(stop - start); // Calcula a duração da execução
    cout << "Tempo de execucao: " << duration.count() << "ms" << endl; // Exibe o tempo de execução
    cout << "Contagem de operacoes: " << operationCount << endl << endl; // Exibe a contagem de operações
    return uniqueCycles.size(); // Retorna o número total de ciclos únicos
}

// Função auxiliar DFS para encontrar ciclos
void CycleDetectionDFS::DFS(int v, vector<bool>& visited, int start, vector<int>& path, set<vector<int>>& uniqueCycles, const map<int, vector<int>>& adjLst) {
    visited[v] = true; // Marca o vértice como visitado
    path.push_back(v); // Adiciona o vértice ao caminho atual

    // Para cada vértice adjacente não visitado
    for (int u : adjLst.at(v)) {
        // Se o vértice adjacente for o vértice inicial e o caminho for maior que 2, um ciclo foi encontrado
        if (u == start && path.size() > 2) {
            vector<int> cycle = path; // Copia o caminho para um vetor de ciclo
            sort(cycle.begin(), cycle.end()); // Ordena para garantir a unicidade
            uniqueCycles.insert(cycle); // Insere o ciclo ordenado no conjunto de ciclos únicos
        } else if (!visited[u]) {
            DFS(u, visited, start, path, uniqueCycles, adjLst); // Continua a busca em profundidade
        }
    }

    path.pop_back(); // Remove o vértice do caminho atual
    visited[v] = false; // Marca o vértice como não visitado (para futuras iterações)
}
