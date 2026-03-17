#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, val;
    vector<int> numbers;

    cout << "Enter N: ";
    cin >> N;

    // 1. Get N numbers and put them in the vector
    for (int i = 0; i < N; i++) {
        cin >> val;
        numbers.push_back(val);
    }

    // 2. Start variables using the first number
    int max = numbers[0];
    int min = numbers[0];
    int sum = 0;

    // 3. One loop to find all three results
    for (int i = 0; i < N; i++) {
        sum += numbers[i];
        if (numbers[i] > max) max = numbers[i];
        if (numbers[i] < min) min = numbers[i];
    }

    // 4. Print results
    cout << "Max: " << max << endl;
    cout << "Min: " << min << endl;
    cout << "Sum: " << sum << endl;

    return 0;
}