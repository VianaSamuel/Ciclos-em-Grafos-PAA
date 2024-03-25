#include "CycleDetection.hpp"
#include <iostream>
#include <algorithm>
#include <numeric> // Para std::iota

CycleDetection::CycleDetection(int n) : cycleCount(0) {
    graph.assign(n, std::vector<bool>(n, false));
}

void CycleDetection::addEdge(int u, int v) {
    graph[u][v] = true;
    graph[v][u] = true;
}

void CycleDetection::printCycle(const std::vector<int>& cycle) {
    for (int v : cycle) {
        std::cout << v << ' ';
    }
    std::cout << std::endl;
}

bool CycleDetection::isValidCycle(const std::vector<int>& subset) {
    if (!graph[subset.front()][subset.back()]) {
        return false;
    }
    for (size_t i = 0; i < subset.size() - 1; ++i) {
        if (!graph[subset[i]][subset[i + 1]]) {
            return false;
        }
    }
    return true;
}

void CycleDetection::checkSubsetsForCycles(const std::vector<int>& subset) {
    if (subset.size() < 3) {
        return; // Ignora subconjuntos de tamanho menor que 3
    }
    std::vector<int> perm = subset;
    std::sort(perm.begin(), perm.end());
    do {
        if (isValidCycle(perm)) {
            cycleCount++;
            printCycle(perm);
        }
    } while (std::next_permutation(perm.begin(), perm.end()));
}

void CycleDetection::findAllCycles() {
    int n = graph.size();
    std::vector<int> vertices(n);
    std::iota(vertices.begin(), vertices.end(), 0);

    for (int r = 2; r <= n; ++r) {
        std::vector<bool> bitmask(r, 1);
        bitmask.resize(n, 0);
        do {
            std::vector<int> subset;
            for (int i = 0; i < n; ++i) {
                if (bitmask[i]) {
                    subset.push_back(vertices[i]);
                }
            }
            checkSubsetsForCycles(subset);
        } while (std::prev_permutation(bitmask.begin(), bitmask.end()));
    }
}

int CycleDetection::getCycleCount() const {
    return cycleCount;
}
