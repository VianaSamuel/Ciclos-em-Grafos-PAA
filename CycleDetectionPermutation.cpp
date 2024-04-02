#include "CycleDetectionPermutation.hpp"
#include <iostream>

using namespace std::chrono;

// ====================== //
//       CONSTRUTOR       //
// ====================== //
// inicializa o CycleDetectionPermutation com um grafo fornecido
CycleDetectionPermutation::CycleDetectionPermutation(const Graph& G) : G(G), cycleCount(0), operationCount(0) { }


// ==================== //
//       DETECÇÃO       //
// ==================== //
// # findAllCycles
void CycleDetectionPermutation::findAllCycles() {
    // ----- INICIALIZAÇÃO ----- //
    auto start = high_resolution_clock::now();      // inicializa o cronômetro
    int n = G.getV();                               // obtém o número de vértices do grafo
    vector<vector<bool>> adjMtx = G.getAdjMtx();    // obtém a matriz de adjacência do grafo
    vector<int> vertices(n);                        // inicializa um vetor de vértices para gerar subconjuntos
    iota(vertices.begin(), vertices.end(), 0);      // preenche o vetor
    operationCount += n;                            // adiciona à contagem de operações

    // ----- SUBCONJUNTOS -----//
    // gera todos os subconjuntos de vértices possíveis do grafo
    for (int r = 2; r <= n; ++r) {
        vector<bool> bitmask(r, 1);
        bitmask.resize(n, 0);

        do {
            vector<int> subset;
            for (int i = 0; i < n; ++i) {
                operationCount++; // loop
                if (bitmask[i]) {
                    subset.push_back(vertices[i]);
                    operationCount++; // push_back
                }
            }
            // verifica se o subconjunto atual forma um ciclo
            checkSubsetsForCycles(subset, adjMtx);
        } while (prev_permutation(bitmask.begin(), bitmask.end()));
        
        operationCount++;
    }

    // ----- PRINT ----- //
    cout << "Total de ciclos: " << cycleCount << endl;

    // ----- FINALIZAÇÃO ----- //
    auto stop = high_resolution_clock::now();                   // interrompe o cronômetro
    auto duration = duration_cast<milliseconds>(stop - start);  // calcula a duração
    cout << "Tempo de execucao: " << duration.count() << "ms" << endl;
    cout << "Contagem de operacoes: " << operationCount << endl << endl << endl;
}
// # isValidCycle
bool CycleDetectionPermutation::isValidCycle(const vector<int>& subset, vector<vector<bool>>& adjMtx) {
    operationCount++; // (verificação do tamanho do subgrafo)

    // verifica se existe uma aresta entre o primeiro e o último vértices do subconjunto
    if (!adjMtx[subset.front()][subset.back()]) {
        operationCount += 2; // (acesso ao vetor e comparação)
        return false;
    }

    // analisa se cada par de vértices consecutivos no subconjunto está conectado por uma aresta
    for (size_t i = 0; i < subset.size() - 1; ++i) {
        operationCount += 3; // (acesso ao vetor (2) + comparação)
        if (!adjMtx[subset[i]][subset[i + 1]]) {
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
void CycleDetectionPermutation::checkSubsetsForCycles(const vector<int>& subset, vector<vector<bool>>& adjMtx) {
    operationCount++; // (verificação de tamanho do subset)
    if (subset.size() < 3) {
        return;
    }
    
    // cria uma cópia do subconjunto para permutar e encontrar todos os ciclos possíveis
    vector<int> perm = subset;
    do {
        if (isValidCycle(perm, adjMtx)) {   // analisa se um determinado subconjunto de vértices forma um ciclo válido no grafo
            cycleCount++;
            printCycle(perm);
            operationCount++;
        }
        operationCount++; // (próxima permutação)
    } while (next_permutation(perm.begin(), perm.end()));
}


// =================== //
//       PRINT'S       //
// =================== //
// # printCycle
void CycleDetectionPermutation::printCycle(const vector<int>& cycle) {
    for (int v : cycle) {
        cout << v << ' ';
    }
    cout << endl;
}