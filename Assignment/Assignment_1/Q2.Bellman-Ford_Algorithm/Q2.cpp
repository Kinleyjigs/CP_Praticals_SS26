#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<tuple<int,int,int>> edges(E);

    cout << "Enter edges (u v w):\n";
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = {u, v, w};
    }

    int source;
    cout << "Enter source vertex: ";
    cin >> source;

    vector<int> dist(V + 1, INT_MAX);
    dist[source] = 0;

    for (int i = 0; i < V - 1; i++) {
        for (auto& [u, v, w] : edges) {
            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    bool negativeCycle = false;
    for (auto& [u, v, w] : edges) {
        if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
            negativeCycle = true;
            break;
        }
    }

    if (negativeCycle) {
        cout << "\nNegative weight cycle detected! Shortest paths are not reliable.\n";
    } else {
        cout << "\nShortest distances from source " << source << ":\n";
        for (int i = 1; i <= V; i++) { 
            cout << "Vertex " << i << " : ";
            if (dist[i] == INT_MAX)
                cout << "Unreachable\n";
            else
                cout << dist[i] << "\n";
        }
    }

    return 0;
}