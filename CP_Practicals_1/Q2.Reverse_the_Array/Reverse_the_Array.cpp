#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cout << "Enter N: ";
    cin >> N;

    vector<int> numbers;

    // 1. Fill the vector normally
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        numbers.push_back(temp);
    }

    // 2. Reverse Traversal
    cout << "Reversed: ";
    for (int i = N - 1; i >= 0; i--) {
        cout << numbers[i] << " ";
    }

    cout << endl;
    return 0;
}