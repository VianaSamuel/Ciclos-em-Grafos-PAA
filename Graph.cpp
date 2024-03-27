#include "Graph.hpp"
#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

// ====================== //
//       CONSTRUTOR       //
// ====================== //
Graph::Graph(int V) {
    this->V = V;    // inicializa o número de vértices

    // ----- LISTA ----- //
    // inicializa a lista de adjacência, onde:
    // chave = vértice
    // valor = lista de vértices adjacentes
    adjLst = map<int, vector<int>>();

    // ----- MATRIZ ----- //
    // inicializa a matriz de adjacência, onde:
    // linhas = V elementos
    // colunas = V elementos inicializados como false
    adjMtx.resize(V, vector<bool>(V, false));
}


// ================== //
//       ARESTAS      //
// ================== //
void Graph::addEdge(int v, int w) {
    // ----- TRATAMENTO ----- //
    if (v < 0 || v >= this->V || w < 0 || w >= this->V) {
        cout << endl << "Erro: Os vértices fornecidos devem estar dentro do intervalo válido (0 a " << this->V-1 << ")." << endl;
        return;
    }
    
    // ----- LISTA ----- //
    adjLst[v].push_back(w);
    adjLst[w].push_back(v);

    // ----- MATRIZ ----- //
    adjMtx[v][w] = true;
    adjMtx[w][v] = true;
}


// =================== //
//       PRINT'S       //
// =================== //
// # printGraph
void Graph::printGraph() {
    // ----- LISTA ----- //
    cout << "LISTA" << endl;
    cout << "#---#" << endl;
    // VÉRTICE (chave .first) v
    for (const auto &pair : adjLst) {
        cout << "| " << pair.first << " |-> ";
        // LISTA DE ADJACENTES (valor .second) w
        for (int w : pair.second) {
            cout << w << " ";
        }
        cout << endl;
    }
    cout << "#---#" << endl;

    // ----- MATRIZ ----- //
    cout << endl << "MATRIZ" << endl;
    cout << "#---#  ";
    for (int i=0; i<V; ++i) {
        cout << " " << i;
    }
    cout << endl;
    // VÉRTICE (linha) v
    for (int v=0; v<V; ++v) {
        cout << "| " << v << " |-> ";
        // VÉRTICE (coluna) u
        for (int u=0; u<V; ++u) {
            // CONEXAO ENTRE v E u ?
            cout << (adjMtx[v][u] ? "1 " : "0 ");
        }
        cout << endl;
    }
    cout << "#---#" << endl;
}


// ==================== //
//       GETTER'S       //
// ==================== //
// # getV
int Graph::getV() const { return this->V; }
// # getAdjLst
const map<int, vector<int>>& Graph::getAdjLst() const { return this->adjLst; }
// # getAdjMtx
const vector<vector<bool>>& Graph::getAdjMtx() const { return this->adjMtx; }


void Graph::DFS(int v, vector<bool>& visited, int start, vector<int>& path, set<string>& uniqueCycles) {
    visited[v] = true; // marca o vértice atual como visitado
    path.push_back(v); // adiciona o vértice atual ao caminho atual

    // percorre todos os vértices adjacentes ao vértice atual `v`
    for (int u : adjLst[v]) {
        // se o vértice adjacente é o vértice de início e o tamanho do caminho é maior que 2, um ciclo é encontrado
        if (u == start && path.size() > 2) {
            vector<int> cycle = path; // cia uma cópia do caminho atual para representar o ciclo
            cycle.push_back(start); // adiciona o vértice de início ao ciclo para fechá-lo
            string cycleKey = createCycleKey(cycle); // cria uma chave única para o ciclo
            uniqueCycles.insert(cycleKey); // insere o ciclo no conjunto de ciclos únicos
        } else if (!visited[u]) {
            // se o vértice adjacente não foi visitado, continua a busca em profundidade a partir desse vértice
            DFS(u, visited, start, path, uniqueCycles);
        }
    }

    // retornando da recursão, remove o vértice atual do caminho e o marca como não visitado
    path.pop_back();
    visited[v] = false;
}


string Graph::createCycleKey(const vector<int>& cycle) {
    vector<int> normalizedCycle = cycle; // cria uma cópia do ciclo
    sort(normalizedCycle.begin(), normalizedCycle.end()); // ordena os vértices do ciclo
    string key; // inicializa a chave do ciclo
    // constrói a chave concatenando os vértices ordenados do ciclo com um espaço
    for (int v : normalizedCycle) {
        key += to_string(v) + " ";
    }
    return key; // Retorna a chave única do ciclo.
}

// método para encontrar todos os ciclos únicos no grafo e imprimir esses ciclos
int Graph::findAllUniqueCycles() {
    vector<bool> visited(V, false); // vetor de vértices visitados
    vector<int> path; // vetor que armazena o caminho atual
    set<string> uniqueCycles; // inicializa o conjunto de ciclos único

    for (int i = 0; i < V; i++) {
        DFS(i, visited, i, path, uniqueCycles); // Chama DFS para o vértice `i`
        visited[i] = true; // Marca o vértice `i` como visitado após retornar do DFS
    }
    cout << "Ciclos encontrados:" << endl;
    for (const string& cycle : uniqueCycles) {
        cout << cycle << endl;
    }

    // Retorna o número de ciclos encontrados.
    return uniqueCycles.size();
}
