#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, k;
    cout << "Enter N and K: ";
    cin >> n >> k;

    priority_queue<int> pq; // Max heap by default
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        pq.push(val);
    }

    cout << "Output: ";
    // Pop the top K elements
    for (int i = 0; i < k; i++) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;

    return 0;
}