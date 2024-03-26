#include "Graph.hpp"
#include <iostream>

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