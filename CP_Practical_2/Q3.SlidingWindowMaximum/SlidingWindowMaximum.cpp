#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    deque<int> dq;  // Store indices
    vector<int> result;
    
    for (int i = 0; i < n; i++) {
        // Remove elements outside current window
        while (!dq.empty() && dq.front() < i - k + 1) {
            dq.pop_front();
        }
        
        // Remove smaller elements from back
        while (!dq.empty() && arr[dq.back()] < arr[i]) {
            dq.pop_back();
        }
        
        dq.push_back(i);
        
        // Start adding to result after first window
        if (i >= k - 1) {
            result.push_back(arr[dq.front()]);
        }
    }
    
    // Output
    for (int i = 0; i < result.size(); i++) {
        if (i > 0) cout << " ";
        cout << result[i];
    }
    cout << endl;
    
    return 0;
}
