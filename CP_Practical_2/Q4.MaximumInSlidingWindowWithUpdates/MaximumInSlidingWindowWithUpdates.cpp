#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, K, Q;
    cin >> N >> K >> Q;
    
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    // Process Q queries
    for (int q = 0; q < Q; q++) {
        int type;
        cin >> type;
        
        if (type == 1) {
            // Update query: Type 1 pos val
            int pos, val;
            cin >> pos >> val;
            A[pos] = val;  // Direct update at index pos
        } else {
            // Maximum query: Type 2 i
            // Find maximum in sliding window of size K ending at position i (1-indexed)
            int pos;
            cin >> pos;
            pos--;  // Convert to 0-indexed
            
            // Window spans from (pos - K + 1) to pos
            int windowStart = pos - K + 1;
            int maxVal = INT_MIN;
            
            for (int j = windowStart; j <= pos; j++) {
                maxVal = max(maxVal, A[j]);
            }
            
            cout << maxVal << "\n";
        }
    }
    
    return 0;
}
