#include <bits/stdc++.h>
using namespace std;

int primsMST(vector<vector<int>> &vec, int vertices, int edges) {
    // Step 1: Create adjacency list
    unordered_map<int, list<pair<int,int>>> adj;
    for(int i = 0; i < edges; i++) {
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];

        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // undirected graph
    }

    // Step 2: Create key array, MST set, and parent array
    vector<int> key(vertices, INT_MAX);
    vector<bool> mst(vertices, false);
    vector<int> parent(vertices, -1);

    // Step 3: Set to store {key, node}
    set<pair<int,int>> st;

    // Start from node 0
    key[0] = 0;
    st.insert({0, 0});

    while(!st.empty()) {
        auto top = *(st.begin());
        st.erase(st.begin());

        int node = top.second;
        mst[node] = true;

        for(auto nbr : adj[node]) {
            int adjNode = nbr.first;
            int weight = nbr.second;

            if(!mst[adjNode] && weight < key[adjNode]) {
                // If already present, remove old entry
                if(key[adjNode] != INT_MAX) {
                    st.erase({key[adjNode], adjNode});
                }

                // Update key and parent
                key[adjNode] = weight;
                parent[adjNode] = node;
                st.insert({key[adjNode], adjNode});
            }
        }
    }

    // Step 4: Calculate total weight of MST
    int totalWeight = 0;
    for(int i = 0; i < vertices; i++) {
        totalWeight += key[i];
    }

    return totalWeight;
}

int main() {
    int vertices = 5;
    int edges = 7;
    vector<vector<int>> vec = {
        {0, 1, 7},
        {0, 2, 1},
        {0, 3, 2},
        {1, 3, 3},
        {1, 4, 1},
        {3, 4, 5},
        {2, 4, 2}
    };

    int mstWeight = primsMST(vec, vertices, edges);
    cout << "Total weight of MST: " << mstWeight << "\n";

    return 0;
}
