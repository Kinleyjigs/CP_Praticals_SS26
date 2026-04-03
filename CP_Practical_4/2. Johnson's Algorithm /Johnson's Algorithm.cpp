#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const long long INF = (long long)1e18;

struct Edge {
	int u, v;
	long long w;
};

int main() {
	int n, m;
	cin >> n >> m;

	vector<Edge> edges;
	vector<vector<pair<int, long long>>> g(n);

	for (int i = 0; i < m; i++) {
		int u, v;
		long long w;
		cin >> u >> v >> w;
		edges.push_back({u, v, w});
	}

	// Add extra source n with 0-weight edge to every node.
	vector<long long> h(n + 1, INF);
	h[n] = 0;
	vector<Edge> bf = edges;
	for (int i = 0; i < n; i++) bf.push_back({n, i, 0});

	for (int i = 0; i < n; i++) {
		bool changed = false;
		for (auto &e : bf) {
			if (h[e.u] < INF && h[e.u] + e.w < h[e.v]) {
				h[e.v] = h[e.u] + e.w;
				changed = true;
			}
		}
		if (!changed) break;
	}

	// Check negative cycle.
	for (auto &e : bf) {
		if (h[e.u] < INF && h[e.u] + e.w < h[e.v]) {
			cout << "Negative cycle detected\n";
			return 0;
		}
	}

	// Reweight edges: w' = w + h[u] - h[v]
	for (auto &e : edges) {
		long long nw = e.w + h[e.u] - h[e.v];
		g[e.u].push_back({e.v, nw});
	}

	vector<vector<long long>> ans(n, vector<long long>(n, INF));

	for (int s = 0; s < n; s++) {
		vector<long long> d(n, INF);
		d[s] = 0;
		priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
		pq.push({0, s});

		while (!pq.empty()) {
			pair<long long, int> top = pq.top();
			pq.pop();
			long long cur = top.first;
			int u = top.second;
			if (cur != d[u]) continue;

			for (size_t i = 0; i < g[u].size(); i++) {
				int v = g[u][i].first;
				long long w = g[u][i].second;
				if (d[u] + w < d[v]) {
					d[v] = d[u] + w;
					pq.push({d[v], v});
				}
			}
		}

		for (int v = 0; v < n; v++) {
			if (d[v] < INF) ans[s][v] = d[v] - h[s] + h[v];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (ans[i][j] >= INF / 2) cout << "INF ";
			else cout << ans[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}
