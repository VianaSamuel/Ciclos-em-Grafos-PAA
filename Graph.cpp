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
    adjLst = map<char, vector<char>>();

    // ----- MATRIZ ----- //
    // inicializa a matriz de adjacencia, onde:
    // linhas = V elementos
    // colunas = V elementos inicializados como false
    adjMtx.resize(V, vector<bool>(V, false));
}

// ================== //
//       ARESTAS      //
// ================== //
void Graph::addEdge(char v, char w) {
    // ----- TRATAMENTO ----- //
    if (v - 'A' >= V || w - 'A' >= V) {
        cout << "Erro: O tamanho de vértices inicializado no grafo foi excedido" << endl;
        return;
    }
    if (!isalpha(v) || !isalpha(w)) {
        cout << "Erro: Os vértices fornecidos não são caracteres alfabéticos" << endl;
        return;
    }
    v = toupper(v);
    w = toupper(w);

    // ----- LISTA ----- //
    adjLst[v].push_back(w);
    adjLst[w].push_back(v);

    // ----- MATRIZ ----- //
    adjMtx[v - 'A'][w - 'A'] = true;
    adjMtx[w - 'A'][v - 'A'] = true;
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
        for (char w : pair.second) {
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
    cout << "#---#" << endl;
    // VERTICE (linha) v //
    for (int v = 0; v < V; ++v) {
        cout << "| " << static_cast<char>(v + 'A') << " |-> ";
        // VERTICE (coluna) u //
        for (int u = 0; u < V; ++u) {
            // CONEXAO ENTRE v E u ? //
            cout << (adjMtx[v][u] ? "1 " : "0 ");
        }
        cout << endl;
    }
    cout << "#---#" << endl;
}