#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main() {
    int N, K;

    // 1. Get N and K from the user
    cout << "Enter the total number of elements (N): ";
    cin >> N;
    cout << "Enter the window size (K): ";
    cin >> K;

    vector<int> arr(N);
    cout << "Enter " << N << " integers separated by spaces: " << endl;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    // 2. Prepare the deque for the sliding window
    deque<int> dq; 

    cout << "Sliding Window Maximums: " << endl;
    for (int i = 0; i < N; i++) {
        // Remove indices that are now outside the window
        if (!dq.empty() && dq.front() == i - K) {
            dq.pop_front();
        }

        // Remove elements smaller than the current one from the back
        while (!dq.empty() && arr[i] >= arr[dq.back()]) {
            dq.pop_back();
        }

        // Add current index
        dq.push_back(i);

        // Print the front of the deque once the first window is full
        if (i >= K - 1) {
            cout << arr[dq.front()] << " ";
        }
    }

    cout << endl;
    return 0;
}