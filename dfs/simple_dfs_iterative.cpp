#include <iostream>
#include <vector>
#include <stack>

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
        adj[v].push_back(u);  // Undirected graph
    }

    void dfs_iterative(int start) {
        stack<int> s; // stack -> LIFO 
        s.push(start);
        visited[start] = true;

        cout << "DFS (Iterative) starting from node " << start << ":" << endl;

        while (!s.empty()) {
            int current = s.top();
            s.pop();
            cout << "Visited: " << current << endl;

            for (auto it = adj[current].rbegin(); it != adj[current].rend(); ++it) {
                int neighbor = *it;
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    s.push(neighbor);
                }
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

    g.dfs_iterative(0);

    return 0;
}
