#include <bits/stdc++.h>
using namespace std;

// Function to perform Topological Sort using DFS
void topoSortDFS(int node, vector<pair<int,int>> adj[], vector<int> &vis, stack<int> &st) {
    vis[node] = 1; // mark current node as visited
    for (auto it : adj[node]) {
        int v = it.first; // neighbor vertex
        if (!vis[v]) {
            topoSortDFS(v, adj, vis, st); // recursive DFS call
        }
    }
    st.push(node); // push node to stack after visiting all neighbors
}

// Function to find shortest path in DAG
void shortestPath(int src, int V, vector<pair<int,int>> adj[]) {
    // Step 1: Perform Topological Sort
    vector<int> vis(V, 0);
    stack<int> st;
    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            topoSortDFS(i, adj, vis, st);
        }
    }

    // Step 2: Initialize distances with infinity
    vector<int> dist(V, INT_MAX);
    dist[src] = 0; // distance to source is 0

    // Step 3: Process vertices in topological order
    while (!st.empty()) {
        int u = st.top();
        st.pop();

        // If u is reachable
        if (dist[u] != INT_MAX) {
            // Relax all edges from u
            for (auto it : adj[u]) {
                int v = it.first;   // neighbor
                int wt = it.second; // edge weight
                if (dist[u] + wt < dist[v]) {
                    dist[v] = dist[u] + wt; // update shortest distance
                }
            }
        }
    }

    // Step 4: Print shortest distances
    cout << "Shortest distances from source " << src << ":\n";
    for (int i = 0; i < V; i++) {
        if (dist[i] == INT_MAX) cout << "INF "; // unreachable node
        else cout << dist[i] << " ";
    }
    cout << endl;
}

int main() {
    int V = 6; // number of vertices
    vector<pair<int,int>> adj[V]; // adjacency list (vertex, weight)

    // Example DAG edges (u -> v with weight w)
    adj[0].push_back({1, 2});
    adj[0].push_back({4, 1});
    adj[1].push_back({2, 3});
    adj[4].push_back({2, 2});
    adj[2].push_back({3, 6});
    adj[4].push_back({5, 4});
    adj[5].push_back({3, 1});

    int src = 0; // source vertex
    shortestPath(src, V, adj);

    return 0;
}
