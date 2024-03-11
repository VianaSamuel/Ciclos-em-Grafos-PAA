#include "Graph.hpp"
#include <iostream>

using namespace std;

// ====================== //
//       CONSTRUTOR       //
// ====================== //
Graph::Graph(int V) {
    // ----- VERTICES ----- //
    // inicializa o numero de vertices
    this->V = V;

    // ----- LISTA ----- //
    // inicializa a lista de adjacencia, onde:
    // chave = vertice
    // valor = lista de vertices adjacentes
    adjLst = map<int, vector<int>>();

    // ----- MATRIZ ----- //
    // inicializa a matriz de adjacencia, onde:
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
        cout << "Erro: Os vértices fornecidos devem estar dentro do intervalo válido (0 a " << this->V-1 << ")." << endl;
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
// ----- LISTA ----- //
void Graph::printAdjList() {
    cout << endl;
    cout << "LISTA" << endl;
    cout << "#---#" << endl;
    // VERTICE (chave .first) v //
    for (const auto &pair : adjLst) {
        cout << "| " << pair.first << " |-> ";
        // LISTA (valor .second) DE ADJACENTES w //
        for (int w : pair.second) {
            cout << w << " ";
        }
        cout << endl;
    }
    cout << "#---#" << endl;
}

// ----- MATRIZ ----- //
void Graph::printAdjMatrix() {
    cout << endl;
    cout << "MATRIZ" << endl;
    cout << "#---#  ";
    for (int i = 0; i < V; ++i) {
        cout << " " << i;
    }
    cout << endl;
    
    // VERTICE (linha) v //
    for (int v = 0; v < V; ++v) {
        cout << "| " << v << " |-> ";
        // VERTICE (coluna) u //
        for (int u = 0; u < V; ++u) {
            // CONEXAO ENTRE v E u ? //
            cout << (adjMtx[v][u] ? "1 " : "0 ");
        }
        cout << endl;
    }
    cout << "#---#" << endl;
}