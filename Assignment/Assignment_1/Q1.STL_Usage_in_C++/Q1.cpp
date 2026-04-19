#include <iostream>
#include <vector>
#include <deque>
#include <array>
#include <numeric>
using namespace std;

int main() {
    int N;
    cout << "Enter number of elements (N): ";
    cin >> N;

    vector<int> numbers(N);

    cout << "Enter " << N << " integers:\n";
    for (int &num : numbers) {
        cin >> num;
    }

    cout << "\nVector in reverse: ";
    for (auto it = numbers.rbegin(); it != numbers.rend(); ++it) {
        cout << *it << " ";
    }
    cout << "\n\n";

    int Q;
    cout << "Enter number of operations (Q): ";
    cin >> Q;

    deque<int> dq;

    cout << "\nOperation Guide:\n";
    cout << "1 x  -> push_front(x)\n";
    cout << "2 x  -> push_back(x)\n";
    cout << "3    -> pop_front()\n\n";

    for (int i = 0; i < Q; i++) {
        int op;
        cout << "Operation " << i + 1 << ": ";
        cin >> op;

        if (op == 1 || op == 2) {
            int x;
            cout << "Enter value: ";
            cin >> x;

            if (op == 1) {
                dq.push_front(x);
            } else {
                dq.push_back(x);
            }

        } else if (op == 3) {
            if (!dq.empty()) {
                dq.pop_front();
            } else {
                cout << "Deque is empty, cannot pop.\n";
            }

        } else {
            cout << "Invalid operation! Try again.\n";
            i--; 
        }
    }

    cout << "\nFinal deque contents: ";
    for (int value : dq) {
        cout << value << " ";
    }
    cout << "\n\n";

    const int M = 5;
    array<int, M> fixedArr;

    cout << "Enter " << M << " integers for the array:\n";
    for (int &x : fixedArr) {
        cin >> x;
    }

    int sum = accumulate(fixedArr.begin(), fixedArr.end(), 0);

    cout << "Sum of array elements: " << sum << "\n";

    return 0;
}