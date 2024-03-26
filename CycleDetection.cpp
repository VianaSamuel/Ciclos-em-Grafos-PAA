#include "CycleDetection.hpp"
#include <iostream>
#include <algorithm>
#include <numeric>
#include <chrono>
#include <cmath>

using namespace std::chrono;

CycleDetection::CycleDetection(int n) : cycleCount(0), operationCount(0) {
    graph.assign(n, std::vector<bool>(n, false));
    operationCount += n * n; // Cada atribuição na matriz de adjacências
}

// Método para adicionar uma aresta
void CycleDetection::addEdge(int u, int v) {
    graph[u][v] = true;
    graph[v][u] = true;
    operationCount += 2; // Duas atribuições
}

// Método para imprimir um ciclo.
void CycleDetection::printCycle(const std::vector<int>& cycle) {
    for (int v : cycle) {
        std::cout << v << ' ';
    }
    std::cout << std::endl;
}

// Analisa se um determinado subconjunto de vértices forma um ciclo válido no grafo.
bool CycleDetection::isValidCycle(const std::vector<int>& subset) {
    operationCount++; // Por verificar o tamanho do subgrafo
    // Verifica se existe uma aresta entre o primeiro e o último vértices do subconjunto.
    if (!graph[subset.front()][subset.back()]) {
        operationCount += 2; // Acesso ao vetor e comparação
        return false;
    }
    // Analisa se cada par de vértices consecutivos no subconjunto está conectado por uma aresta.
    for (size_t i = 0; i < subset.size() - 1; ++i) {
        operationCount += 3; // Acesso ao vetor (2) + comparação
        if (!graph[subset[i]][subset[i + 1]]) {
            return false;
        }
    }
    return true;
}

// Investiga todos os subconjuntos de vértices do grafo para encontrar ciclos válidos, excluindo subconjuntos de tamanho menor que 3.
void CycleDetection::checkSubsetsForCycles(const std::vector<int>& subset) {
    operationCount++; // Verificação de tamanho do subset
    if (subset.size() < 3) {
        return;
    }
    // Cria uma cópia do subconjunto para permutar e encontrar todos os ciclos possíveis.
    std::vector<int> perm = subset;
    std::sort(perm.begin(), perm.end());
    operationCount += perm.size() * log(perm.size()); // Estimativa para std::sort
    do {
        if (isValidCycle(perm)) {
            cycleCount++;
            printCycle(perm);
            operationCount++;
        }
        operationCount++; // proxima permutacao
    } while (std::next_permutation(perm.begin(), perm.end()));
}

//detecção de ciclos
void CycleDetection::findAllCycles() {
    auto start = high_resolution_clock::now(); // Inicia o cronômetro

    int n = graph.size();
    // Cria um vetor de vértices para gerar subconjuntos
    std::vector<int> vertices(n);
    // Preenche o vetor
    std::iota(vertices.begin(), vertices.end(), 0);
    operationCount += n; // iota

    // Gera todos os subconjuntos possíveis de vértices do grafo
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
            // Verifica se o subconjunto atual forma um ciclo
            checkSubsetsForCycles(subset);
        } while (std::prev_permutation(bitmask.begin(), bitmask.end()));
        operationCount++; // prev_permutation
    }

    auto stop = high_resolution_clock::now(); // cronômetro
    auto duration = duration_cast<milliseconds>(stop - start); // Calcula a duração

    displayExecutionTime(duration); // Exibe o tempo de execução
}

// Retorna o número total de ciclos válidos encontrados no grafo.
int CycleDetection::getCycleCount() const {
    return cycleCount;
}

void CycleDetection::displayExecutionTime(const std::chrono::milliseconds& duration) {
    std::cout << "Tempo de execução: " << duration.count() << "ms" << std::endl;
}

void CycleDetection::displayOperationCount() const {
    std::cout << "Contagem de operações: " << operationCount << std::endl;
}
