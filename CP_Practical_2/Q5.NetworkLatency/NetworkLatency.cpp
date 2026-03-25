#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<pair<int,int>>> g(N+1);

    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    vector<long long> dist(N+1, 1e18);
    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;

    dist[1] = 0;
    pq.push({0, 1});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;

        for (auto [v, w] : g[u]) {
            if (dist[v] > d + w) {
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }

    cout << (dist[N] == 1e18 ? -1 : dist[N]);
}