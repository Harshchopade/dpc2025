#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, int parent, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;
    for (int nei : adj[node]) {
        if (!visited[nei]) {
            if (dfs(nei, node, adj, visited)) return true;
        } else if (nei != parent) {
            return true;
        }
    }
    return false;
}

bool hasCycle(int V, vector<pair<int,int>>& edges) {
    vector<vector<int>> adj(V);
    for (auto& e : edges) {
        int u = e.first, v = e.second;
        if (u == v) return true;
        for (int x : adj[u]) if (x == v) return true;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool> visited(V, false);
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, adj, visited)) return true;
        }
    }
    return false;
}

int main() {
    int V = 5;
    vector<pair<int,int>> edges = {{0,1},{1,2},{2,3},{3,4},{4,0}};
    cout << (hasCycle(V, edges) ? "true" : "false") << endl;

    V = 3;
    edges = {{0,1},{1,2}};
    cout << (hasCycle(V, edges) ? "true" : "false") << endl;

    V = 4;
    edges = {{0,1},{1,2},{2,0}};
    cout << (hasCycle(V, edges) ? "true" : "false") << endl;

    return 0;
}
