/*
    * Dijkstra's Algorithm Implementation in C++
    * This code uses a priority queue (min-heap) and an adjacency list to find the shortest paths from a starting node to all other nodes in a weighted undirected graph.
    * It maintains a distance array to track the shortest distances, and a previous node array to reconstruct the paths.
    * The graph is undirected and edges are bidirectional.
    * A priority queue is used to efficiently select the node with the smallest current distance.
    * The code includes a function to print the shortest path from the start node to every other node.
    * Written using the C++ STL for educational clarity and easy modification.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <stack>

using namespace std;

struct Graph_dijkstra {
    Graph_dijkstra(int V) : V(V) {
        adj.resize(V);
    }

private:
    int V;  // Number of vertices
    vector<vector<pair<int, int>>> adj; // Adjacency list: node -> (neighbor, weight)

public:
    void add_edge(int u, int v, int weight) {
        adj[u].emplace_back(v, weight);
        adj[v].emplace_back(u, weight); // Undirected graph
    }

    void dijkstra(int start) {
        vector<int> dist(V, INT_MAX); // Distance from the start node
        vector<int> prev(V, -1);      // Previous node in shortest path
        dist[start] = 0;

        // Min-heap: (distance, node)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.emplace(0, start);

        while (!pq.empty()) {
            int curr_dist = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if (curr_dist > dist[u]) continue;

            for (auto [v, weight] : adj[u]) {
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    prev[v] = u;
                    pq.emplace(dist[v], v);
                }
            }
        }

        // Print result
        cout << "Dijkstra (with paths) from node " << start << ":\n";
        for (int i = 0; i < V; ++i) {
            cout << "Node: " << i << " | Distance: " << dist[i] << " | Path: ";
            print_path(prev, i);
            cout << endl;
        }
    }

    void print_path(const vector<int>& prev, int node) {
        stack<int> path;
        for (int at = node; at != -1; at = prev[at]) {
            path.push(at);
        }
        while (!path.empty()) {
            cout << path.top();
            path.pop();
            if (!path.empty()) cout << " -> ";
        }
    }
};

int main() {
    Graph_dijkstra g(6);
    g.add_edge(0, 1, 7);
    g.add_edge(0, 2, 9);
    g.add_edge(0, 5, 14);
    g.add_edge(1, 2, 10);
    g.add_edge(1, 3, 15);
    g.add_edge(2, 3, 11);
    g.add_edge(2, 5, 2);
    g.add_edge(3, 4, 6);
    g.add_edge(4, 5, 9);

    g.dijkstra(0);

    return 0;
}