#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <tuple>
#include <climits>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M, K;
    cin >> N >> M >> K;
    
    vector<int> toll(N);
    for (int i = 0; i < N; i++) {
        cin >> toll[i];
    }
    
    // BFS approach
    // State: (booth, coins_left, skips_used)
    // We want minimum time to reach booth N
    
    // Use a map to track visited states and their minimum time
    map<tuple<int, int, int>, int> visited;
    
    // Queue: (booth, coins, skips_used, time)
    queue<tuple<int, int, int, int>> q;
    
    // Start at booth 0 with M coins and 0 skips used
    q.push({0, M, 0, 0});
    visited[{0, M, 0}] = 0;
    
    int answer = INT_MAX;
    
    while (!q.empty()) {
        auto [booth, coins, skips_used, time] = q.front();
        q.pop();
        
        // If we reached booth N (which is beyond the last toll booth), update answer
        if (booth == N) {
            answer = min(answer, time);
            continue;
        }
        
        // Option 1: Pay toll at current booth and move to next booth
        if (coins >= toll[booth]) {
            int new_coins = coins - toll[booth];
            int new_time = time + 1;
            auto state = make_tuple(booth + 1, new_coins, skips_used);
            
            // Only visit this state if we haven't seen it or found a better path
            if (visited.find(state) == visited.end() || visited[state] > new_time) {
                visited[state] = new_time;
                q.push({booth + 1, new_coins, skips_used, new_time});
            }
        }
        
        // Option 2: Skip booth and move to next booth
        if (skips_used < K) {
            int new_time = time + 2;
            auto state = make_tuple(booth + 1, coins, skips_used + 1);
            
            // Only visit this state if we haven't seen it or found a better path
            if (visited.find(state) == visited.end() || visited[state] > new_time) {
                visited[state] = new_time;
                q.push({booth + 1, coins, skips_used + 1, new_time});
            }
        }
    }
    
    if (answer == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << answer << endl;
    }
    
    return 0;
}
