#include <iostream>
#include <vector>

using namespace std;

#define INF 1e9 // Using a large value for infinity

void floydWarshall(int V, vector<vector<int>>& graph) {
    // Create a distance matrix and initialize it with the input graph
    vector<vector<long long>> dist(V, vector<long long>(V));

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    // Main Algorithm: Try every vertex 'k' as an intermediate point
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                // If path through k is shorter, update dist[i][j]
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Check for Negative Cycles
    // If distance from a node to itself becomes negative, there is a cycle
    for (int i = 0; i < V; i++) {
        if (dist[i][i] < 0) {
            cout << "Negative cycle detected!" << endl;
            return;
        }
    }

    // Print the final distance matrix
    cout << "Shortest distance matrix:" << endl;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF) cout << "INF\t";
            else cout << dist[i][j] << "\t";
        }
        cout << endl;
    }
}

int main() {
    int V;
    cout << "Enter number of vertices: ";
    cin >> V;

    vector<vector<int>> graph(V, vector<int>(V));
    cout << "Enter the adjacency matrix (use " << INF << " for no edge):" << endl;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> graph[i][j];
        }
    }

    floydWarshall(V, graph);

    return 0;
}