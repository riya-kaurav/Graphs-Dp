#include <bits/stdc++.h>
using namespace std;

// Structure to represent an edge
struct Edge {
    int u, v, weight;
};

// Disjoint Set Union (Union-Find) structure
struct DSU {
    vector<int> parent, rank;

    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i; // each node is its own parent initially
    }

    // Find with path compression
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    // Union by rank
    bool unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY) return false; // already in same set → cycle

        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
        return true;
    }
};

int main() {
    int V, E; // V = number of vertices, E = number of edges
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<Edge> edges(E);
    cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < E; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }

    // Step 1: Sort edges by weight
    sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
        return a.weight < b.weight;
    });

    DSU dsu(V);
    vector<Edge> mst; // store MST edges
    int totalWeight = 0;

    // Step 2: Iterate through edges
    for (auto &edge : edges) {
        if (dsu.unite(edge.u, edge.v)) {
            // If union successful → no cycle → include edge
            mst.push_back(edge);
            totalWeight += edge.weight;
        }
    }

    // Print MST result
    cout << "\nMinimum Spanning Tree edges:\n";
    for (auto &edge : mst) {
        cout << edge.u << " - " << edge.v << " : " << edge.weight << "\n";
    }
    cout << "Total weight of MST = " << totalWeight << "\n";

    return 0;
}