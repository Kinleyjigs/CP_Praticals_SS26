// Problem 1: Dinner Table Arrangements
// This implementation follows the provided sample behavior:
// arrange all friends in a line so every adjacent pair shares at least one allergy.

#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while (T--) {
		int N;
		cin >> N;

		vector<unsigned int> allergyMask(N, 0U);

		for (int i = 0; i < N; i++) {
			int M;
			cin >> M;
			unsigned int mask = 0U;
			for (int j = 0; j < M; j++) {
				int allergyId;
				cin >> allergyId;
				mask |= (1U << (allergyId - 1));
			}
			allergyMask[i] = mask;
		}

		if (N == 1) {
			cout << "YES\n";
			continue;
		}

		vector<int> canSitWith(N, 0);
		for (int i = 0; i < N; i++) {
			int neighbors = 0;
			for (int j = 0; j < N; j++) {
				if (i == j) continue;
				if ((allergyMask[i] & allergyMask[j]) != 0U) {
					neighbors |= (1 << j);
				}
			}
			canSitWith[i] = neighbors;
		}

		// Quick pruning: in a path, isolated nodes (for N > 1) are impossible.
		bool impossible = false;
		for (int i = 0; i < N; i++) {
			if (canSitWith[i] == 0) {
				impossible = true;
				break;
			}
		}

		if (impossible) {
			cout << "NO\n";
			continue;
		}

		int fullMask = (1 << N) - 1;
		vector<vector<char>> dp(1 << N, vector<char>(N, 0));
		for (int i = 0; i < N; i++) {
			dp[1 << i][i] = 1;
		}

		for (int mask = 0; mask <= fullMask; mask++) {
			for (int last = 0; last < N; last++) {
				if (!dp[mask][last]) continue;

				int available = canSitWith[last] & (~mask);
				while (available) {
					int bit = available & -available;
					int nxt = __builtin_ctz(static_cast<unsigned int>(bit));
					dp[mask | bit][nxt] = 1;
					available ^= bit;
				}
			}
		}

		bool ok = false;
		for (int last = 0; last < N; last++) {
			if (dp[fullMask][last]) {
				ok = true;
				break;
			}
		}

		cout << (ok ? "YES" : "NO") << '\n';
	}

	return 0;
}
