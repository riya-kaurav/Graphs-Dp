#include <bits/stdc++.h>
using namespace std;

/*
 Step 1 DFS:
 - Used for topological sort
 - Push node into stack after visiting all its neighbours
*/
void dfs1(int node, unordered_map<int, bool> &vis,
          stack<int> &st, unordered_map<int, list<int>> &adj) {

    vis[node] = true;

    for (auto nbr : adj[node]) {
        if (!vis[nbr]) {
            dfs1(nbr, vis, st, adj);
        }
    }

    // push after full DFS (finishing time)
    st.push(node);
}

/*
 Step 2 DFS:
 - DFS on transpose graph
 - Marks all nodes of one SCC
*/
void dfs2(int node, unordered_map<int, bool> &vis,
          unordered_map<int, list<int>> &transpose) {

    vis[node] = true;

    for (auto nbr : transpose[node]) {
        if (!vis[nbr]) {
            dfs2(nbr, vis, transpose);
        }
    }
}

/*
 Main function to count Strongly Connected Components
*/
int stronglyConnectedComponents(int v, vector<vector<int>> &edges) {

    // Step 1: Create adjacency list
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int w = edges[i][1];
        adj[u].push_back(w);
    }

    // Step 2: Topological sort using DFS
    stack<int> st;
    unordered_map<int, bool> vis;

    for (int i = 0; i < v; i++) {
        if (!vis[i]) {
            dfs1(i, vis, st, adj);
        }
    }

    // Step 3: Create transpose graph
    unordered_map<int, list<int>> transpose;
    for (int i = 0; i < v; i++) {
        vis[i] = false;   // reset visited array
        for (auto nbr : adj[i]) {
            transpose[nbr].push_back(i);
        }
    }

    // Step 4: DFS using stack order on transpose graph
    int count = 0;
    while (!st.empty()) {
        int top = st.top();
        st.pop();

        if (!vis[top]) {
            count++;
            dfs2(top, vis, transpose);
        }
    }

    return count;
}