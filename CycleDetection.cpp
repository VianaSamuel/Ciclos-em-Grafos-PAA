#include "CycleDetection.hpp"
#include <iostream>
#include <algorithm>
#include <numeric> 

// Construtor da classe CycleDetection inicializa o contador de ciclos e o grafo com um determinado número de vértices, todos desconectados inicialmente.
CycleDetection::CycleDetection(int n) : cycleCount(0) {
    graph.assign(n, std::vector<bool>(n, false));
}

// Método para adicionar uma aresta bidirecional entre os vértices u e v no grafo.
void CycleDetection::addEdge(int u, int v) {
    graph[u][v] = true;
    graph[v][u] = true;
}

// Método para imprimir um ciclo encontrado.
void CycleDetection::printCycle(const std::vector<int>& cycle) {
    for (int v : cycle) {
        std::cout << v << ' ';
    }
    std::cout << std::endl;
}

// Verifica se um determinado subconjunto de vértices forma um ciclo válido no grafo.
bool CycleDetection::isValidCycle(const std::vector<int>& subset) {
    // Verifica se existe uma aresta entre o primeiro e o último vértices do subconjunto.
    if (!graph[subset.front()][subset.back()]) {
        return false;
    }
    // Verifica se cada par de vértices consecutivos no subconjunto está conectado por uma aresta.
    for (size_t i = 0; i < subset.size() - 1; ++i) {
        if (!graph[subset[i]][subset[i + 1]]) {
            return false;
        }
    }
    return true;
}

// Verifica todos os subconjuntos de vértices do grafo para encontrar ciclos válidos, excluindo subconjuntos de tamanho menor que 3.
void CycleDetection::checkSubsetsForCycles(const std::vector<int>& subset) {
    if (subset.size() < 3) {
        return; // Ignora subconjuntos de tamanho menor que 3 para evitar ciclos triviais.
    }
    // Cria uma cópia do subconjunto para permutar e encontrar todos os ciclos possíveis.
    std::vector<int> perm = subset;
    std::sort(perm.begin(), perm.end());
    do {
        if (isValidCycle(perm)) {
            cycleCount++;
            printCycle(perm);
        }
    } while (std::next_permutation(perm.begin(), perm.end()));
}

// Método público que inicia o processo de detecção de ciclos em todo o grafo.
void CycleDetection::findAllCycles() {
    int n = graph.size();
    // Cria um vetor de vértices para gerar subconjuntos.
    std::vector<int> vertices(n);
    // Preenche o vetor com os números de 0 a n-1.
    std::iota(vertices.begin(), vertices.end(), 0);

    // Gera todos os subconjuntos possíveis de vértices do grafo, de tamanho 2 até n.
    for (int r = 2; r <= n; ++r) {
        std::vector<bool> bitmask(r, 1); // Usado para gerar os subconjuntos.
        bitmask.resize(n, 0);
        do {
            std::vector<int> subset;
            for (int i = 0; i < n; ++i) {
                if (bitmask[i]) {
                    subset.push_back(vertices[i]);
                }
            }
            // Verifica se o subconjunto atual forma um ciclo válido.
            checkSubsetsForCycles(subset);
        } while (std::prev_permutation(bitmask.begin(), bitmask.end()));
    }
}

// Retorna o número total de ciclos válidos encontrados no grafo.
int CycleDetection::getCycleCount() const {
    return cycleCount;
}
