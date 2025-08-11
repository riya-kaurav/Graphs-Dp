#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>

using namespace std;

void dfs(int node, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adj, vector<int> &components) {
    components.push_back(node);
    visited[node] = true;

    for (auto i : adj[node]) {
        if (!visited[i]) {
            dfs(i, visited, adj, components);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges) {
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<vector<int>> ans;
    unordered_map<int, bool> visited;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            vector<int> components;
            dfs(i, visited, adj, components);
            ans.push_back(components);
        }
    }
    return ans;
}

int main() {
    // Example usage:
    int V = 5, E = 4;
    vector<vector<int>> edges = {{0,1},{0,2},{3,4},{2,3}};
    vector<vector<int>> components = depthFirstSearch(V, E, edges);

    for (const auto &comp : components) {
        for (int node : comp) {
            cout << node << " ";
        }
        cout << endl;
    }
    return 0;
}