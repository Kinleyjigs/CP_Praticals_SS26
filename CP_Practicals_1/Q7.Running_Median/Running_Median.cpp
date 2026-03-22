#include <iostream>
#include <vector>
#include <queue>
#include <iomanip> // Needed to format the decimal places

using namespace std;

// Function to calculate the running median
vector<double> runningMedian(vector<int> a) {
    // Bucket 1: Max-Heap for the smaller half of numbers
    priority_queue<int> leftBucket; 
    
    // Bucket 2: Min-Heap for the larger half of numbers
    priority_queue<int, vector<int>, greater<int>> rightBucket; 
    
    vector<double> medians;

    for (int i = 0; i < a.size(); i++) {
        int currentNumber = a[i];

        // Step 1: Put the number in the correct bucket
        if (leftBucket.empty() || currentNumber <= leftBucket.top()) {
            leftBucket.push(currentNumber);
        } else {
            rightBucket.push(currentNumber);
        }

        // Step 2: Balance the buckets! 
        // Left bucket can have at most 1 more item than the right bucket.
        if (leftBucket.size() > rightBucket.size() + 1) {
            rightBucket.push(leftBucket.top());
            leftBucket.pop();
        } else if (rightBucket.size() > leftBucket.size()) {
            leftBucket.push(rightBucket.top());
            rightBucket.pop();
        }

        // Step 3: Find the median
        if (leftBucket.size() == rightBucket.size()) {
            // Even total: Average the tops of both buckets
            double median = (leftBucket.top() + rightBucket.top()) / 2.0;
            medians.push_back(median);
        } else {
            // Odd total: The median is just the top of the left bucket
            double median = leftBucket.top();
            medians.push_back(median);
        }
    }

    return medians;
}

int main() {
    int n;
    cout << "Enter the number of integers: ";
    cin >> n;

    vector<int> a(n);
    cout << "Enter the integers: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Get the medians
    vector<double> result = runningMedian(a);

    // Print the results, forcing exactly 1 decimal place (e.g., 12.0)
    cout << "Output:" << endl;
    cout << fixed << setprecision(1); 
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }

    return 0;
}