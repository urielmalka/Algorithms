#include <iostream>
#include <vector>

using namespace std;

struct Graph_dfs {
    Graph_dfs(int V) : V(V) {
        adj.resize(V);
        visited.resize(V, false);
    }

private:
    int V;  // Number of vertices
    vector<vector<int>> adj; // Adjacency list
    vector<bool> visited; // Vector to mark visited vertices

public:
    void add_edge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); // Undirected graph
    }

    void set_visited(int node) {
        visited[node] = true;
    }

    bool is_visited(int node) const {
        return visited[node];
    }

    vector<int> get_adj(int node) const {
        return adj[node];
    }

    void dfs(int node) {
        set_visited(node);
        cout << "Visited: " << node << endl;

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor);
            }
        }
    }
};

int main() {
    Graph_dfs g(6);
    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(1, 3);
    g.add_edge(1, 4);
    g.add_edge(2, 4);
    g.add_edge(3, 5);
    g.add_edge(4, 5);

    cout << "DFS starting from node 0:" << endl;
    g.dfs(0);

    return 0;
}
