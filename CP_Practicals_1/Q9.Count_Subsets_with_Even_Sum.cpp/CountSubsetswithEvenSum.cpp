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

    int total_subsets = 1 << n; 
    int even_sum_count = 0;

    for (int mask = 0; mask < total_subsets; mask++) {
        int current_sum = 0;
        
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                current_sum += elements[i];
            }
        }
        
        // Empty set sum is 0, which is mathematically even. 
        if (current_sum % 2 == 0) {
            even_sum_count++;
        }
    }

    cout << "Output: " << even_sum_count << endl;

    return 0;
}