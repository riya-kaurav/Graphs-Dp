#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;

public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int src, int dest) {
        adj[src].push_back(dest);
        adj[dest].push_back(src); // undirected
    }

    void BFS(int start) {
        vector<bool> visited(V, false); // track visited nodes
        queue<int> q;                   // queue for BFS

        visited[start] = true;
        q.push(start);

        cout << "BFS Traversal starting from " << start << ": ";

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cout << node << " ";

            // Visit all neighbors
            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        cout << endl;
    }
};

int main() {
    Graph g(6); // 6 vertices (0 to 5)

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 5);

    g.BFS(0); // Start BFS from node 0
    return 0;
}