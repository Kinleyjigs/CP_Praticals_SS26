#include <iostream>
#include <vector>
using namespace std;

struct Edge {
	int u, v, w;
};

struct DSU {
	vector<int> p, r;
	DSU(int n) {
		p.resize(n);
		r.assign(n, 0);
		for (int i = 0; i < n; i++) p[i] = i;
	}
	int find(int x) {
		if (p[x] == x) return x;
		return p[x] = find(p[x]);
	}
	bool unite(int a, int b) {
		a = find(a);
		b = find(b);
		if (a == b) return false;
		if (r[a] < r[b]) swap(a, b);
		p[b] = a;
		if (r[a] == r[b]) r[a]++;
		return true;
	}
};

int main() {
	int n, m;
	cin >> n >> m;

	vector<Edge> edges(m);
	for (int i = 0; i < m; i++) {
		cin >> edges[i].u >> edges[i].v >> edges[i].w;
	}

	DSU dsu(n);
	int components = n;
	int mstWeight = 0;

	while (components > 1) {
		vector<int> best(n, -1);

		for (int i = 0; i < m; i++) {
			int a = dsu.find(edges[i].u);
			int b = dsu.find(edges[i].v);
			if (a == b) continue;

			if (best[a] == -1 || edges[i].w < edges[best[a]].w) best[a] = i;
			if (best[b] == -1 || edges[i].w < edges[best[b]].w) best[b] = i;
		}

		bool merged = false;
		for (int i = 0; i < n; i++) {
			int id = best[i];
			if (id == -1) continue;
			if (dsu.unite(edges[id].u, edges[id].v)) {
				mstWeight += edges[id].w;
				components--;
				merged = true;
			}
		}

		if (!merged) break;
	}

	if (components != 1) cout << "Graph is disconnected\n";
	else cout << "MST weight = " << mstWeight << "\n";

	return 0;
}
