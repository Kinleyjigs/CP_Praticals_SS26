#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, target;
    
    // 1. Get the input
    cout << "Enter the number of elements (n): ";
    cin >> n;
    
    cout << "Enter the target sum: ";
    cin >> target;

    vector<int> arr(n);
    cout << "Enter the " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // 2. Set up our "scoreboard"
    // We make a list from 0 up to the target, filled with 0s.
    vector<int> dp(target + 1, 0);
    
    // Base case: There is exactly 1 way to make a sum of 0 (by picking nothing at all!)
    dp[0] = 1;

    // 3. Update the scoreboard for each number we have
    for (int i = 0; i < n; i++) {
        // We count backwards from the target down to the current number
        for (int j = target; j >= arr[i]; j--) {
            // Add the number of ways we could make the sum WITHOUT this current number
            dp[j] += dp[j - arr[i]];
        }
    }

    // 4. Print the final answer stored at our exact target spot
    cout << "Output:\n" << dp[target] << endl;

    return 0;
}