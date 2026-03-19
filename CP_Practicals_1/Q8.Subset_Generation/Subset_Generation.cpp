#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cout << "Enter N: ";
    cin >> n;

    vector<int> elements(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> elements[i];
    }

    // Total subsets is 2^N. We use bitwise left shift (1 << n) to get 2^N.
    int total_subsets = 1 << n; 

    cout << "Output:\n";
    for (int mask = 0; mask < total_subsets; mask++) {
        cout << "{";
        bool first = true;
        for (int i = 0; i < n; i++) {
            // Check if the i-th bit is set in the mask
            if (mask & (1 << i)) {
                if (!first) cout << " ";
                cout << elements[i];
                first = false;
            }
        }
        cout << "}\n";
    }

    return 0;
}