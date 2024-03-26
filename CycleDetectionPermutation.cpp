#include "CycleDetectionPermutation.hpp"
#include <iostream>
#include <algorithm>
#include <numeric>
#include <chrono>
#include <cmath>

using namespace std::chrono;

// ====================== //
//       CONSTRUTOR       //
// ====================== //
// inicializa o CycleDetectionPermutation com o número de vértices
CycleDetectionPermutation::CycleDetectionPermutation(int n) : cycleCount(0), operationCount(0) {
    graph.assign(n, std::vector<bool>(n, false));
    operationCount += n * n; // contagem de atribuições na matriz de adjacência
}
// método para adicionar uma aresta
void CycleDetectionPermutation::addEdge(int u, int v) {
    graph[u][v] = true;
    graph[v][u] = true;
    operationCount += 2; // (duas atribuições)
}


// ==================== //
//       DETECÇÃO       //
// ==================== //
// # findAllCycles
void CycleDetectionPermutation::findAllCycles() {
    // ----- INICIALIZAÇÃO ----- //
    auto start = high_resolution_clock::now();      // inicializa o cronômetro
    int n = graph.size();                           // inicializa o número de vértices
    std::vector<int> vertices(n);                   // inicializa um vetor de vértices para gerar subconjuntos
    std::iota(vertices.begin(), vertices.end(), 0); // preenche o vetor
    operationCount += n;                            // adiciona à contagem de operações

    // ----- SUBCONJUNTOS -----//
    // gera todos os subconjuntos de vértices possíveis do grafo
    for (int r = 2; r <= n; ++r) {
        std::vector<bool> bitmask(r, 1);
        bitmask.resize(n, 0);

        do {
            std::vector<int> subset;
            for (int i = 0; i < n; ++i) {
                operationCount++; // loop
                if (bitmask[i]) {
                    subset.push_back(vertices[i]);
                    operationCount++; // push_back
                }
            }
            // verifica se o subconjunto atual forma um ciclo
            checkSubsetsForCycles(subset);
        } while (std::prev_permutation(bitmask.begin(), bitmask.end()));
        
        operationCount++;
    }

    // ----- FINALIZAÇÃO ----- //
    auto stop = high_resolution_clock::now();                   // interrompe o cronômetro
    auto duration = duration_cast<milliseconds>(stop - start);  // calcula a duração
    displayExecutionTime(duration);                             // exibe o tempo de execução
}
// # isValidCycle
bool CycleDetectionPermutation::isValidCycle(const std::vector<int>& subset) {
    operationCount++; // (verificação do tamanho do subgrafo)

    // verifica se existe uma aresta entre o primeiro e o último vértices do subconjunto
    if (!graph[subset.front()][subset.back()]) {
        operationCount += 2; // (acesso ao vetor e comparação)
        return false;
    }

    // analisa se cada par de vértices consecutivos no subconjunto está conectado por uma aresta
    for (size_t i = 0; i < subset.size() - 1; ++i) {
        operationCount += 3; // (acesso ao vetor (2) + comparação)
        if (!graph[subset[i]][subset[i + 1]]) {
            return false;
        }
    }

    return true;
}


// ====================== //
//       PERMUTAÇÃO       //
// ====================== //
// # checkSubsetsForCycles
// investiga todos os subconjuntos de vértices do grafo para encontrar ciclos válidos, excluindo subconjuntos de tamanho menor que 3
void CycleDetectionPermutation::checkSubsetsForCycles(const std::vector<int>& subset) {
    operationCount++; // (verificação de tamanho do subset)
    if (subset.size() < 3) {
        return;
    }
    
    // cria uma cópia do subconjunto para permutar e encontrar todos os ciclos possíveis
    std::vector<int> perm = subset;
    std::sort(perm.begin(), perm.end());
    operationCount += perm.size() * log(perm.size()); // (estimativa para std::sort)
    do {
        if (isValidCycle(perm)) {   // analisa se um determinado subconjunto de vértices forma um ciclo válido no grafo
            cycleCount++;
            printCycle(perm);
            operationCount++;
        }
        operationCount++; // (próxima permutação)
    } while (std::next_permutation(perm.begin(), perm.end()));
}


// =================== //
//       PRINT'S       //
// =================== //
// # printCycle
void CycleDetectionPermutation::printCycle(const std::vector<int>& cycle) {
    for (int v : cycle) {
        std::cout << v << ' ';
    }
    std::cout << std::endl;
}
// # displayExecutionTime
void CycleDetectionPermutation::displayExecutionTime(const std::chrono::milliseconds& duration) {
    std::cout << "Tempo de execucao: " << duration.count() << "ms" << std::endl;
}
// # displayOperationCount
void CycleDetectionPermutation::displayOperationCount() const {
    std::cout << "Contagem de operacoes: " << operationCount << std::endl;
}


// ==================== //
//       GETTER'S       //
// ==================== //
// # getCycleCount
int CycleDetectionPermutation::getCycleCount() const {
    return cycleCount; // retorna o número total de ciclos válidos encontrados no grafo
}