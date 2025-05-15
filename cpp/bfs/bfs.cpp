#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Graph_bfs
{
    Graph_bfs(int V): V(V)
    {
        adj.resize(V);
        visited.resize(V, false);
    };

private:
    int V;  // Number of vertices
    vector<vector<int>> adj; // Adjacency list
    vector<bool> visited; // Vector to mark visited vertices
    queue<int> q; // Queue to store vertices to visit   

public:
    int get_size() const { return V; } // Returns the number of vertices

    void add_edge(int u, int v) { // Adds an edge between u and v
        adj[u].push_back(v);
        adj[v].push_back(u); // Undirected graph
    }

    void set_visited(int node) { // Marks a node as visited
        visited[node] = true;
    }

    bool is_visited(int node) const { // Checks if a node was visited
        return visited[node];
    }

    vector<int> get_adj(int node) const { // Returns the neighbors of a node
        return adj[node];
    }

    void push_queue(int node) { // Pushes a node to the queue
        q.push(node);
    }

    int pop_queue() { // Pops a node from the queue
        int node = q.front();
        q.pop();
        return node;
    }

    bool is_queue_empty() const { // Checks if the queue is empty
        return q.empty();
    }
};

// Function to perform BFS from a given start node
void bfs(int start, Graph_bfs g) {

    cout << "BFS starting from node " << start << ":" << endl;

    g.set_visited(start); // Mark the start node as visited
    g.push_queue(start);

    while (!g.is_queue_empty()) {
        int current = g.pop_queue(); // Remove the current node from the queue
        cout << "Visited: " << current << endl;

        for (int neighbor : g.get_adj(current)) { // For each neighbor of the current node
            if (!g.is_visited(neighbor)) { // If the neighbor has not been visited
                g.set_visited(neighbor); // Mark the neighbor as visited
                g.push_queue(neighbor); // Add the neighbor to the queue
            }
        }
    }
}

int main() {
    Graph_bfs g(6);
    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(1, 3);
    g.add_edge(1, 4);
    g.add_edge(2, 4);
    g.add_edge(3, 5);
    g.add_edge(4, 5);


    bfs(0, g);

    return 0;
}
