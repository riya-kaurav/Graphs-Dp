#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector<int> parent;

public:
    // Constructor: initialize each node as its own parent
    DisjointSet(int n) {
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    // Find function (with path compression)
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // compress path
        }
        return parent[x];
    }

    // Union function: connect two sets
    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            parent[rootY] = rootX; // attach one root to another
        }
    }
};

int main() {
    DisjointSet dsu(5); // 5 elements: 0,1,2,3,4

    dsu.unite(0, 1);
    dsu.unite(3, 4);

    cout << "Find(0): " << dsu.find(0) << endl;
    cout << "Find(1): " << dsu.find(1) << endl;
    cout << "Find(3): " << dsu.find(3) << endl;
    cout << "Find(4): " << dsu.find(4) << endl;
    cout << "Find(2): " << dsu.find(2) << endl;

    return 0;
}