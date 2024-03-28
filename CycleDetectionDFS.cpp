#include "Graph.hpp"
#include "CycleDetectionDFS.hpp" 
#include <iostream>
#include <chrono>

using namespace std::chrono;

// ====================== //
//       CONSTRUTOR       //
// ====================== //
// inicializa o CycleDetectionDFS com um grafo fornecido
CycleDetectionDFS::CycleDetectionDFS(const Graph& G) : G(G), operationCount(0) { }


// ==================== //
//       DETECÇÃO       //
// ==================== //
// # findAllUniqueCycles
// encontra e imprime todos os ciclos únicos no grafo
int CycleDetectionDFS::findAllUniqueCycles() {
    // ----- INICIALIZAÇÃO ----- //
    auto start = high_resolution_clock::now();      // inicializa o cronômetro
    int V = G.getV();                               // obtém o número de vértices do grafo
    map<int, vector<int>> adjLst = G.getAdjLst();   // obtém a lista de adjacência do grafo
    vector<bool> visited(V, false);                 // cria um vetor de vértices visitados
    vector<int> path;                               // cria um vetor que armazena o caminho atual
    set<string> uniqueCycles;                       // cria o conjunto de ciclos únicos

    // ----- DFS ----- //
    for (int i = 0; i < V; i++) {
        operationCount++; // (contagem incrementada a cada loop)

        DFS(i, visited, i, path, uniqueCycles, adjLst);     // chama DFS para o vértice 'i'
        visited[i] = true;                                  // marca o vértice 'i' como visitado após retornar do DFS
    }

    // ----- PRINT ----- //
    cout << "Total de ciclos unicos: " << uniqueCycles.size() << endl;
    if (uniqueCycles.size() != 0) {
        cout << "Ciclos encontrados:" << endl;
        for (const string& cycle : uniqueCycles) {
            cout << cycle << endl;
        }
    }

    // ----- FINALIZAÇÃO ----- //
    auto stop = high_resolution_clock::now();                   // interrompe o cronômetro
    auto duration = duration_cast<milliseconds>(stop - start);  // calcula a duração
    cout << "Tempo de execucao: " << duration.count() << "ms" << endl;
    cout << "Contagem de operacoes: " << operationCount << endl;
    return uniqueCycles.size();                                 // retorna o resultado
}


// =============== //
//       DFS       //
// =============== //
// # DFS
// realiza a busca em profundidade
void CycleDetectionDFS::DFS(int v, vector<bool>& visited, int start, vector<int>& path, set<string>& uniqueCycles, const map<int, vector<int>>& adjLst) {
    visited[v] = true;      // marca o vértice atual como visitado
    path.push_back(v);      // adiciona o vértice atual ao caminho atual

    // percorre todos os vértices adjacentes ao vértice atual 'v'
    for (int u : adjLst.at(v)) {
        operationCount ++; // (contagem incrementada a cada loop)

        // SE o vértice adjacente é o vértice de início
        // E o tamanho do caminho é maior que 2
        // ENTÃO um ciclo é ENCONTRADO
        if (u == start && path.size() > 2) {
            operationCount += 2; // (2 comparações do if)

            vector<int> cycle = path;                       // cria uma cópia do caminho atual para representar o ciclo
            cycle.push_back(start);                         // adiciona o vértice de início ao ciclo para fechá-lo
            string cycleKey = createCycleKey(cycle);        // cria uma chave única para o ciclo
            uniqueCycles.insert(cycleKey);                  // insere o ciclo no conjunto de ciclos únicos
        } else if (!visited[u]) {
            operationCount++; // (1 comparação do else if)

            // SE o vértice adjacente não foi visitado
            // CONTINUA a busca em profundidade a partir desse vértice
            DFS(u, visited, start, path, uniqueCycles, adjLst);
        }
    }

    path.pop_back();        // remove o vértice atual
    visited[v] = false;     // o marca como não visitado
}


// ================== //
//       CICLOS       //
// ================== //
// # createCycleKey
// ordena os vértices da lista e retorna uma chave única representando o ciclo
string CycleDetectionDFS::createCycleKey(const vector<int>& cycle) {
    vector<int> normalizedCycle = cycle;                    // cria uma cópia do ciclo
    sort(normalizedCycle.begin(), normalizedCycle.end());   // ordena os vértices do ciclo
    string key;                                             // inicializa a chave do ciclo

    // constrói a chave concatenando os vértices ordenados do ciclo
    for (int v : normalizedCycle) {
        operationCount++; // (contagem incrementada a cada loop)

        key += to_string(v) + " ";
    }

    return key; // retorna a chave única do ciclo
}