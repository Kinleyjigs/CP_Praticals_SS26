#include <iostream>
#include <vector>
using namespace std;

int main () {

    int N;
    cout << "Enter the number of integers: ";
    cin >> N;

    vector<int> arr(N);
    cout << "Enter the integers: ";
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int K;
    cout << "Enter the integer K: ";
    cin >> K;

    int count = 0;
    int totalSubsets = 1 << N; 

    for (int mask = 0; mask < totalSubsets; mask++) {
        int sum = 0;
        for (int j = 0; j < N; j++) {
            if (mask & (1 << j)) { 
                sum += arr[j];
            }
        }
        if (sum % K == 0) {
            count++;
        }
    }

    cout << "Number of subsets whose sum is divisible by " << K << ": " << count << endl;

    return 0;

}
