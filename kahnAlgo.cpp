#include <bits/stdc++.h>
using namespace std;

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e) {

    // ---------- Create adjacency list ----------
    unordered_map<int, list<int>> adj;
    for(int i = 0; i < e; i++) {
        int u = edges[i][0];
        int w = edges[i][1];
        adj[u].push_back(w);
    }

    // ---------- Find indegrees ----------
    vector<int> indegree(v, 0);

    for(auto &i : adj) {
        for(auto j : i.second) {
            indegree[j]++;
        }
    }

    // ---------- Push all nodes with indegree 0 ----------
    queue<int> q;
    for(int i = 0; i < v; i++) {
        if(indegree[i] == 0) {
            q.push(i);
        }
    }

    // ---------- BFS (Kahn's Algorithm) ----------
    vector<int> ans;
    while(!q.empty()) {
        int front = q.front();
        q.pop();
        ans.push_back(front);

        for(auto neighbour : adj[front]) {
            indegree[neighbour]--;
            if(indegree[neighbour] == 0) {
                q.push(neighbour);
            }
        }
    }

    return ans;
}

int main() {
    // Example
    int v = 6;
    vector<vector<int>> edges = {
        {5, 2}, {5, 0}, {4, 0},
        {4, 1}, {2, 3}, {3, 1}
    };
    int e = edges.size();

    vector<int> result = topologicalSort(edges, v, e);

    cout << "Topological Order: ";
    for(int x : result) cout << x << " ";
    cout << endl;

    return 0;
}