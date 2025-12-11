#include <bits/stdc++.h>
using namespace std;

class Graph {
    int V;                        // Number of vertices
    vector<vector<int>> adj;      // Adjacency list

    void dfs(int node, vector<bool>& visited, stack<int>& st) {
        visited[node] = true;
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, visited, st);
            }
        }
        st.push(node); // push after visiting all neighbors
    }

public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v); // directed edge u -> v
    }

    void topologicalSort() {
        vector<bool> visited(V, false);
        stack<int> st;

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(i, visited, st);
            }
        }

        // Print contents of stack (topological order)
        cout << "Topological Sort (DFS): ";
        while (!st.empty()) {
            cout << st.top() << " ";
            st.pop();
        }
        cout << endl;
    }
};

int main() {
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    g.topologicalSort();

    return 0;
}
