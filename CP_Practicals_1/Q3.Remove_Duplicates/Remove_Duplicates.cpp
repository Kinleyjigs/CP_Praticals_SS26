#include <iostream>
#include <vector>
#include <algorithm> // We need this to use the sort() tool

using namespace std;

int main() {
    int N;
    vector<int> numbers;

    // 1. Get the total number of elements
    cout << "Enter N: ";
    cin >> N;

    // 2. Read the numbers and add them to our vector
    cout << "Enter the numbers: ";
    for (int i = 0; i < N; i++) {
        int val;
        cin >> val;
        numbers.push_back(val);
    }

    // 3. Sort the list from smallest to largest
    sort(numbers.begin(), numbers.end());

    // 4. Go through the sorted list and print only unique numbers
    cout << "Output: ";
    for (int i = 0; i < N; i++) {
        // Print if it's the very first number, OR if it's different from the number right behind it
        if (i == 0 || numbers[i] != numbers[i - 1]) {
            cout << numbers[i] << " ";
        }
    }
    cout << endl;

    return 0;
}