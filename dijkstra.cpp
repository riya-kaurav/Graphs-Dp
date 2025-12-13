#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // Step 1: Create adjacency list
    unordered_map<int, list<pair<int,int>>> adj;
    for(int i = 0; i < edges; i++) {
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];

        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // remove this line if graph is directed
    }

    // Step 2: Create distance array
    vector<int> dist(vertices, INT_MAX);
    dist[source] = 0;

    // Step 3: Set to store {distance, node}
    set<pair<int,int>> st;
    st.insert({0, source});

    // Step 4: Dijkstra loop
    while(!st.empty()) {
        auto top = *(st.begin());
        st.erase(st.begin());

        int nodeDist = top.first;
        int node = top.second;

        for(auto nbr : adj[node]) {
            int adjNode = nbr.first;
            int edgeWeight = nbr.second;

            if(nodeDist + edgeWeight < dist[adjNode]) {
                // If already present, remove old entry
                if(dist[adjNode] != INT_MAX) {
                    st.erase({dist[adjNode], adjNode});
                }

                // Update distance and insert new pair
                dist[adjNode] = nodeDist + edgeWeight;
                st.insert({dist[adjNode], adjNode});
            }
        }
    }

    return dist;
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

    int source = 0;
    vector<int> result = dijkstra(vec, vertices, edges, source);

    cout << "Shortest distances from source " << source << ":\n";
    for(int i = 0; i < vertices; i++) {
        cout << "Node " << i << " -> " << result[i] << "\n";
    }

    return 0;
}
