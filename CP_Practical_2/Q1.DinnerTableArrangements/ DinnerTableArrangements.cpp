// Problem 1: Dinner Table Arrangements
// Arrange N friends in a circular arrangement where adjacent friends share NO common allergies.
// This is a Hamiltonian cycle problem with allergy constraints.
// Two friends can sit adjacent iff (allergyMask[i] & allergyMask[j]) == 0

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

		// Read allergies for each friend as a bitmask
		vector<unsigned int> allergyMask(N, 0U);
		for (int i = 0; i < N; i++) {
			int M;
			cin >> M;
			unsigned int mask = 0U;
			for (int j = 0; j < M; j++) {
				int allergyId;
				cin >> allergyId;
				mask |= (1U << (allergyId - 1));  // Allergy ID -> bit position (ID i maps to bit i-1)
			}
			allergyMask[i] = mask;
		}

		// Edge case: single friend can always sit at the table alone
		if (N == 1) {
			cout << "YES\n";
			continue;
		}

		// Lambda to check if two friends can sit together (NO common allergies)
		auto canSitTogether = [&](int i, int j) -> bool {
			return (allergyMask[i] & allergyMask[j]) == 0U;
		};

		// Early pruning: each friend must have at least one compatible neighbor
		bool possible = true;
		for (int i = 0; i < N; i++) {
			bool hasNeighbor = false;
			for (int j = 0; j < N; j++) {
				if (i != j && canSitTogether(i, j)) {
					hasNeighbor = true;
					break;
				}
			}
			if (!hasNeighbor) {
				possible = false;
				break;
			}
		}

		if (!possible) {
			cout << "NO\n";
			continue;
		}

		// DP for Hamiltonian cycle detection using bitmask
		// dp[mask][last] = true if we can arrange people in 'mask' and end at person 'last'
		vector<vector<bool>> dp(1 << N, vector<bool>(N, false));

		// Base case: start with each individual friend
		for (int i = 0; i < N; i++) {
			dp[1 << i][i] = true;
		}

		// Fill DP table: try extending each valid state
		for (int mask = 0; mask < (1 << N); mask++) {
			for (int last = 0; last < N; last++) {
				if (!dp[mask][last]) continue;

				// Try adding each unvisited person as the next in the arrangement
				for (int next = 0; next < N; next++) {
					// Check if 'next' is not yet visited and can sit with 'last'
					if ((mask & (1 << next)) == 0 && canSitTogether(last, next)) {
						dp[mask | (1 << next)][next] = true;
					}
				}
			}
		}

		// Check if a valid Hamiltonian cycle exists
		bool foundCycle = false;
		int fullMask = (1 << N) - 1;
		for (int last = 0; last < N; last++) {
			// Check: all visited + can close the cycle back to friend 0
			if (dp[fullMask][last] && canSitTogether(last, 0)) {
				foundCycle = true;
				break;
			}
		}

		cout << (foundCycle ? "YES" : "NO") << "\n";
	}

	return 0;
}
